#include "FindAsyncWorker.h"

#include "../library/include/imebra/imebra.h"
#include "../library/include/imebra/tag.h"
#include "../library/include/imebra/exceptions.h"
#include "../library/include/imebra/dimse.h"
#include "../library/include/imebra/acse.h"
#include "../library/include/imebra/dataSet.h"
#include "../library/include/imebra/tcpAddress.h"
#include "../library/include/imebra/tcpStream.h"
#include "../library/include/imebra/streamReader.h"
#include "../library/include/imebra/streamWriter.h"

#include <iostream>
#include <sstream>
#include <memory>
#include <list>
#include "json.h"
#include "Utils.h"

using namespace imebra;
using json = nlohmann::json;

FindAsyncWorker::FindAsyncWorker(std::string data, Function &callback) : AsyncWorker(callback),
                                                                           _input(data)
{
}

void FindAsyncWorker::Execute()
{
	json jsonInput = json::parse(_input);
    auto tags = jsonInput["tags"];
	std::string source_aet = jsonInput["source"]["aet"];
	std::string source_port = jsonInput["source"]["port"];
	std::string target_aet = jsonInput["target"]["aet"];
	std::string target_ip = jsonInput["target"]["ip"];
	std::string target_port = jsonInput["target"]["port"];

	if (source_port.empty() || source_aet.empty()) {
		SetError("Source not set");
		return;
	}

	if (target_ip.empty() || target_port.empty() || target_aet.empty()) {
		SetError("Target not set");
		return;
	}

	// Allocate a TCP stream that connects to the DICOM SCP
	imebra::TCPStream tcpStream(TCPActiveAddress(target_ip, target_port));

	// Allocate a stream reader and a writer that use the TCP stream.
	// If you need a more complex stream (e.g. a stream that uses your
	// own services to send and receive data) then use a Pipe
	imebra::StreamReader readSCU(tcpStream.getStreamInput());
	imebra::StreamWriter writeSCU(tcpStream.getStreamOutput());

	// Add all the abstract syntaxes and the supported transfer
	// syntaxes for each abstract syntax (the pair abstract/transfer syntax is
	// called "presentation context")
	imebra::PresentationContext context(uidStudyRootQueryRetrieveInformationModelFIND_1_2_840_10008_5_1_4_1_2_2_1); // move
	context.addTransferSyntax("1.2.840.10008.1.2"); // Implicit VR little endian
	context.addTransferSyntax("1.2.840.10008.1.2.1"); // Explicit VR little endian
	imebra::PresentationContexts presentationContexts;
	presentationContexts.addPresentationContext(context);

	// The AssociationSCU constructor will negotiate a connection through
	// the readSCU and writeSCU stream reader and writer
	imebra::AssociationSCU scu(source_aet, target_aet, 1, 1, presentationContexts, readSCU, writeSCU, 10);

	// The DIMSE service will use the negotiated association to send and receive
	// DICOM commands
	imebra::DimseService dimse(scu);

	// Let's prepare a dataset to store on the SCP
	imebra::MutableDataSet payload; // We will use the negotiated transfer syntax
    for (json::iterator it = tags.begin(); it != tags.end(); ++it) {
        auto tag = (*it).get<ns::tag>();
    	payload.setString(TagId((tagId_t)std::stoi(tag.key, 0, 16)), tag.value);
    }

	const std::string abstractSyntax = uidStudyRootQueryRetrieveInformationModelFIND_1_2_840_10008_5_1_4_1_2_2_1;

	imebra::CFindCommand command( abstractSyntax,
		dimse.getNextCommandID(),
		dimseCommandPriority_t::medium,
		uidStudyRootQueryRetrieveInformationModelFIND_1_2_840_10008_5_1_4_1_2_2_1,
		payload);
	dimse.sendCommandOrResponse(command);

	try
	{
		for (;;)
		{

		imebra::DimseResponse rsp(dimse.getCFindResponse(command));

		if (rsp.getStatus() == imebra::dimseStatus_t::success)
		{
			break;
		}
		else if (imebra::dimseStatus_t::pending == rsp.getStatus())
		{
			imebra::DataSet data = rsp.getPayloadDataSet();
			try
			{
                imebra::tagsIds_t allTags = data.getTags();
                for (imebra::tagsIds_t::iterator it = allTags.begin() ; it != allTags.end(); ++it) {
                    imebra::TagId tag(*it);
    				std::string value = data.getString(tag, 0);
                    _output += value;
                }

			}
			catch (std::exception & e)
			{
				SetError("Exception: " + std::string(e.what()));
			}
		}
		else
		{
			SetError("Find-scu request failed");
			break;
		}
		}

	}
	catch (const StreamEOFError & error)
	{
		// The association has been closed
		SetError("Association was closed: " + std::string(error.what()));
	}
}

void FindAsyncWorker::OnOK()
{
	HandleScope scope(Env());
	String output = String::New(Env(), _output);
	Callback().Call({output});
}
