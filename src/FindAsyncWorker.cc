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
#include "../library/include/imebra/dicomDictionary.h"


#include "json.h"
#include "Utils.h"

#include <iostream>
#include <sstream>
#include <memory>
#include <list>
#include <iomanip>

using namespace imebra;
using json = nlohmann::json;

namespace {

    std::string str_toupper(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), 
                    [](unsigned char c){ return std::toupper(c); }
                    );
        return s;
    }

    std::string int_to_hex( uint16_t i )
    {
    std::stringstream stream;
    stream  << std::setfill ('0') << std::setw(sizeof(uint16_t)*2) 
            << std::hex << i;
    return str_toupper(stream.str());
    }
}

FindAsyncWorker::FindAsyncWorker(std::string data, Function &callback) : BaseAsyncWorker(data, callback)
{
}

void FindAsyncWorker::Execute(const ExecutionProgress& progress)
{
    ns::sInput in = ns::parseInputJson(_input);

    if (in.tags.empty()) {
        SetErrorJson("Tags not set");
        return;
    }

    if (!in.source.valid()) {
        SetErrorJson("Source not set");
        return;
    }

    if (!in.target.valid()) {
        SetErrorJson("Target not set");
        return;
    }

    const std::string abstractSyntax = uidStudyRootQueryRetrieveInformationModelFIND_1_2_840_10008_5_1_4_1_2_2_1;

    // Allocate a TCP stream that connects to the DICOM SCP
    imebra::TCPStream tcpStream(TCPActiveAddress(in.target.ip, in.target.port));

    // Allocate a stream reader and a writer that use the TCP stream.
    // If you need a more complex stream (e.g. a stream that uses your
    // own services to send and receive data) then use a Pipe
    imebra::StreamReader readSCU(tcpStream.getStreamInput());
    imebra::StreamWriter writeSCU(tcpStream.getStreamOutput());

    // Add all the abstract syntaxes and the supported transfer
    // syntaxes for each abstract syntax (the pair abstract/transfer syntax is
    // called "presentation context")
    imebra::PresentationContext context(abstractSyntax);
    context.addTransferSyntax(imebra::uidImplicitVRLittleEndian_1_2_840_10008_1_2);
    context.addTransferSyntax(imebra::uidExplicitVRLittleEndian_1_2_840_10008_1_2_1);
    imebra::PresentationContexts presentationContexts;
    presentationContexts.addPresentationContext(context);

    // The AssociationSCU constructor will negotiate a connection through
    // the readSCU and writeSCU stream reader and writer
    imebra::AssociationSCU scu(in.source.aet, in.target.aet, 1, 1, presentationContexts, readSCU, writeSCU, 10);

    // The DIMSE service will use the negotiated association to send and receive
    // DICOM commands
    imebra::DimseService dimse(scu);

    // Let's prepare a dataset to store on the SCP
    imebra::MutableDataSet payload; // We will use the negotiated transfer syntax
    for (std::vector<ns::sTag>::iterator it = in.tags.begin(); it != in.tags.end(); ++it) {
        auto tag = (*it);
        payload.setString(TagId((tagId_t)std::stoi(tag.key, 0, 16)), tag.value);
    }


    imebra::CFindCommand command( abstractSyntax,
        dimse.getNextCommandID(),
        dimseCommandPriority_t::medium,
        abstractSyntax,
        payload);
    dimse.sendCommandOrResponse(command);

    try
    {
        json outJson = json::array();
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
                json v = json::object();
                for (imebra::tagsIds_t::iterator it = allTags.begin() ; it != allTags.end(); ++it) {
                    imebra::TagId tag(*it);
                    std::string value = data.getString(tag, 0);
                    std::string keyName =  int_to_hex(tag.getGroupId()) + int_to_hex(tag.getTagId());
                    imebra::tagVR_t tagVr = imebra::DicomDictionary::getTagType(tag);
                    std::string vr = ns::tagVrName(tagVr);
                    if (tagVr == imebra::tagVR_t::PN) {
                    v[keyName] = { 
                        {"Value", json::array({ json{{"Alphabetic", value}} }) },
                        {"vr", vr}
                    };
                    } else {
                    v[keyName] = { 
                        {"Value", json::array({value})},
                        {"vr", vr}
                    };
                    }
                }
                outJson.push_back(v);
            }
            catch (std::exception & e)
            {
                SetErrorJson("Exception: " + std::string(e.what()));
            }
        }
        else
        {
            SetErrorJson("Find-scu request failed");
            break;
        }
        }
        _jsonOutput = outJson.dump();
    }
    catch (const StreamEOFError & error)
    {
        // The association has been closed
        SetErrorJson("Association was closed: " + std::string(error.what()));
    }
}
