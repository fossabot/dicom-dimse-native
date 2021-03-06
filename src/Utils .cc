#include "Utils.h"

using json = nlohmann::json;

namespace ns {

    std::string tagVrName(imebra::tagVR_t tagVr) {

        switch(tagVr)
            {
            case imebra::tagVR_t::AE:
                return "AE";

            case imebra::tagVR_t::AS:
                return "AS";

            case imebra::tagVR_t::CS:
                return "CS";

            case imebra::tagVR_t::DS:
                return "DS";

            case imebra::tagVR_t::IS:
                return "IS";

            case imebra::tagVR_t::UR:
                return "UR";

            case imebra::tagVR_t::LO:
                return "LO";

            case imebra::tagVR_t::LT:
                return "LT";

            case imebra::tagVR_t::PN:
                return "PN";

            case imebra::tagVR_t::SH:
                return "SH";

            case imebra::tagVR_t::ST:
                return "ST";

            case imebra::tagVR_t::UC:
                return "UC";

            case imebra::tagVR_t::UI:
                return "UI";

            case imebra::tagVR_t::UT:
                return "UT";

            case imebra::tagVR_t::OB:
                return "OB";

            case imebra::tagVR_t::OL:
                return "OL";

            case imebra::tagVR_t::SB:
                return "SB";

            case imebra::tagVR_t::UN:
                return "UN";

            case imebra::tagVR_t::OW:
                return "OW";

            case imebra::tagVR_t::AT:
                return "AT";

            case imebra::tagVR_t::FL:
                return "FL";

            case imebra::tagVR_t::OF:
                return "OF";

            case imebra::tagVR_t::FD:
                return "DF";

            case imebra::tagVR_t::OD:
                return "OD";

            case imebra::tagVR_t::SL:
                return "SL";

            case imebra::tagVR_t::SS:
                return "SS";

            case imebra::tagVR_t::UL:
                return "UL";

            case imebra::tagVR_t::US:
                return "US";

            case imebra::tagVR_t::DA:
                return "DA";

            case imebra::tagVR_t::DT:
                return "DT";

            case imebra::tagVR_t::TM:
                return "TM";

            case imebra::tagVR_t::SQ:
                return "SQ";
            default:
                return "UN";
            }
            return "UN";
    }

    std::vector<std::string> dcmLongSCUStorageSOPClassUIDs()
    {
    return {
    imebra::uidAmbulatoryECGWaveformStorage_1_2_840_10008_5_1_4_1_1_9_1_3,
    imebra::uidArterialPulseWaveformStorage_1_2_840_10008_5_1_4_1_1_9_5_1,
    imebra::uidAutorefractionMeasurementsStorage_1_2_840_10008_5_1_4_1_1_78_2,
    imebra::uidBasicStructuredDisplayStorage_1_2_840_10008_5_1_4_1_1_131,
    imebra::uidBasicTextSRStorage_1_2_840_10008_5_1_4_1_1_88_11,
    imebra::uidBasicVoiceAudioWaveformStorage_1_2_840_10008_5_1_4_1_1_9_4_1,
    imebra::uidBlendingSoftcopyPresentationStateStorage_1_2_840_10008_5_1_4_1_1_11_4,
    imebra::uidBreastTomosynthesisImageStorage_1_2_840_10008_5_1_4_1_1_13_1_3,
    imebra::uidCardiacElectrophysiologyWaveformStorage_1_2_840_10008_5_1_4_1_1_9_3_1,
    imebra::uidChestCADSRStorage_1_2_840_10008_5_1_4_1_1_88_65,
    imebra::uidColonCADSRStorage_1_2_840_10008_5_1_4_1_1_88_69,
    imebra::uidColorSoftcopyPresentationStateStorage_1_2_840_10008_5_1_4_1_1_11_2,
    imebra::uidComprehensive3DSRStorage_1_2_840_10008_5_1_4_1_1_88_34,
    imebra::uidComprehensiveSRStorage_1_2_840_10008_5_1_4_1_1_88_33,
    imebra::uidComputedRadiographyImageStorage_1_2_840_10008_5_1_4_1_1_1,
    imebra::uidCTImageStorage_1_2_840_10008_5_1_4_1_1_2,
    imebra::uidDeformableSpatialRegistrationStorage_1_2_840_10008_5_1_4_1_1_66_3,
    imebra::uidDigitalIntraOralXRayImageStorageForPresentation_1_2_840_10008_5_1_4_1_1_1_3,
    imebra::uidDigitalIntraOralXRayImageStorageForProcessing_1_2_840_10008_5_1_4_1_1_1_3_1,
    imebra::uidDigitalMammographyXRayImageStorageForPresentation_1_2_840_10008_5_1_4_1_1_1_2,
    imebra::uidDigitalMammographyXRayImageStorageForProcessing_1_2_840_10008_5_1_4_1_1_1_2_1,
    imebra::uidDigitalXRayImageStorageForPresentation_1_2_840_10008_5_1_4_1_1_1_1,
    imebra::uidDigitalXRayImageStorageForProcessing_1_2_840_10008_5_1_4_1_1_1_1_1,
    imebra::uidEncapsulatedCDAStorage_1_2_840_10008_5_1_4_1_1_104_2,
    imebra::uidEncapsulatedPDFStorage_1_2_840_10008_5_1_4_1_1_104_1,
    imebra::uidEnhancedCTImageStorage_1_2_840_10008_5_1_4_1_1_2_1,
    imebra::uidEnhancedMRColorImageStorage_1_2_840_10008_5_1_4_1_1_4_3,
    imebra::uidEnhancedMRImageStorage_1_2_840_10008_5_1_4_1_1_4_1,
    imebra::uidEnhancedPETImageStorage_1_2_840_10008_5_1_4_1_1_130,
    imebra::uidEnhancedSRStorage_1_2_840_10008_5_1_4_1_1_88_22,
    imebra::uidEnhancedUSVolumeStorage_1_2_840_10008_5_1_4_1_1_6_2,
    imebra::uidEnhancedXAImageStorage_1_2_840_10008_5_1_4_1_1_12_1_1,
    imebra::uidEnhancedXRFImageStorage_1_2_840_10008_5_1_4_1_1_12_2_1,
    imebra::uidGeneralAudioWaveformStorage_1_2_840_10008_5_1_4_1_1_9_4_2,
    imebra::uidGeneralECGWaveformStorage_1_2_840_10008_5_1_4_1_1_9_1_2,
    imebra::uidGrayscaleSoftcopyPresentationStateStorage_1_2_840_10008_5_1_4_1_1_11_1,
    imebra::uidHemodynamicWaveformStorage_1_2_840_10008_5_1_4_1_1_9_2_1,
//  UID_ImplantationPlanSRDocumentStorage,
    imebra::uidIntraocularLensCalculationsStorage_1_2_840_10008_5_1_4_1_1_78_8,
    imebra::uidIntravascularOpticalCoherenceTomographyImageStorageForPresentation_1_2_840_10008_5_1_4_1_1_14_1,
    imebra::uidIntravascularOpticalCoherenceTomographyImageStorageForProcessing_1_2_840_10008_5_1_4_1_1_14_2,
    imebra::uidKeratometryMeasurementsStorage_1_2_840_10008_5_1_4_1_1_78_3,
    imebra::uidKeyObjectSelectionDocumentStorage_1_2_840_10008_5_1_4_1_1_88_59,
    imebra::uidLegacyConvertedEnhancedCTImageStorage_1_2_840_10008_5_1_4_1_1_2_2,
    imebra::uidLegacyConvertedEnhancedMRImageStorage_1_2_840_10008_5_1_4_1_1_4_4,
    imebra::uidLegacyConvertedEnhancedPETImageStorage_1_2_840_10008_5_1_4_1_1_128_1,
    imebra::uidLensometryMeasurementsStorage_1_2_840_10008_5_1_4_1_1_78_1,
    imebra::uidMacularGridThicknessandVolumeReportStorage_1_2_840_10008_5_1_4_1_1_79_1,
    imebra::uidMammographyCADSRStorage_1_2_840_10008_5_1_4_1_1_88_50,
    imebra::uidMRImageStorage_1_2_840_10008_5_1_4_1_1_4,
    imebra::uidMRSpectroscopyStorage_1_2_840_10008_5_1_4_1_1_4_2,
    imebra::uidMultiframeGrayscaleByteSecondaryCaptureImageStorage_1_2_840_10008_5_1_4_1_1_7_2,
    imebra::uidMultiframeGrayscaleWordSecondaryCaptureImageStorage_1_2_840_10008_5_1_4_1_1_7_3,
    imebra::uidMultiframeSingleBitSecondaryCaptureImageStorage_1_2_840_10008_5_1_4_1_1_7_1,
    imebra::uidMultiframeTrueColorSecondaryCaptureImageStorage_1_2_840_10008_5_1_4_1_1_7_4,
    imebra::uidNuclearMedicineImageStorage_1_2_840_10008_5_1_4_1_1_20,
    imebra::uidOphthalmicAxialMeasurementsStorage_1_2_840_10008_5_1_4_1_1_78_7,
    imebra::uidOphthalmicPhotography16BitImageStorage_1_2_840_10008_5_1_4_1_1_77_1_5_2,
    imebra::uidOphthalmicPhotography8BitImageStorage_1_2_840_10008_5_1_4_1_1_77_1_5_1,
    imebra::uidOphthalmicThicknessMapStorage_1_2_840_10008_5_1_4_1_1_81_1,
    imebra::uidOphthalmicTomographyImageStorage_1_2_840_10008_5_1_4_1_1_77_1_5_4,
    imebra::uidOphthalmicVisualFieldStaticPerimetryMeasurementsStorage_1_2_840_10008_5_1_4_1_1_80_1,
    imebra::uidPositronEmissionTomographyImageStorage_1_2_840_10008_5_1_4_1_1_128,
    imebra::uidProcedureLogStorage_1_2_840_10008_5_1_4_1_1_88_40,
    imebra::uidPseudoColorSoftcopyPresentationStateStorage_1_2_840_10008_5_1_4_1_1_11_3,
    imebra::uidRawDataStorage_1_2_840_10008_5_1_4_1_1_66,
    imebra::uidRealWorldValueMappingStorage_1_2_840_10008_5_1_4_1_1_67,
    imebra::uidRespiratoryWaveformStorage_1_2_840_10008_5_1_4_1_1_9_6_1,
    imebra::uidRTBeamsDeliveryInstructionStorageTrial_1_2_840_10008_5_1_4_34_1,
    imebra::uidRTBeamsTreatmentRecordStorage_1_2_840_10008_5_1_4_1_1_481_4,
    imebra::uidRTBrachyTreatmentRecordStorage_1_2_840_10008_5_1_4_1_1_481_6,
    imebra::uidRTDoseStorage_1_2_840_10008_5_1_4_1_1_481_2,
    imebra::uidRTImageStorage_1_2_840_10008_5_1_4_1_1_481_1,
    imebra::uidRTIonBeamsTreatmentRecordStorage_1_2_840_10008_5_1_4_1_1_481_9,
    imebra::uidRTIonPlanStorage_1_2_840_10008_5_1_4_1_1_481_8,
    imebra::uidRTPlanStorage_1_2_840_10008_5_1_4_1_1_481_5,
    imebra::uidRTStructureSetStorage_1_2_840_10008_5_1_4_1_1_481_3,
    imebra::uidRTTreatmentSummaryRecordStorage_1_2_840_10008_5_1_4_1_1_481_7,
    imebra::uidSecondaryCaptureImageStorage_1_2_840_10008_5_1_4_1_1_7,
    imebra::uidSegmentationStorage_1_2_840_10008_5_1_4_1_1_66_4,
    imebra::uidSpatialFiducialsStorage_1_2_840_10008_5_1_4_1_1_66_2,
    imebra::uidSpatialRegistrationStorage_1_2_840_10008_5_1_4_1_1_66_1,
    imebra::uidSpectaclePrescriptionReportStorage_1_2_840_10008_5_1_4_1_1_78_6,
    imebra::uidStereometricRelationshipStorage_1_2_840_10008_5_1_4_1_1_77_1_5_3,
    imebra::uidSubjectiveRefractionMeasurementsStorage_1_2_840_10008_5_1_4_1_1_78_4,
    imebra::uidSurfaceScanMeshStorage_1_2_840_10008_5_1_4_1_1_68_1,
    imebra::uidSurfaceScanPointCloudStorage_1_2_840_10008_5_1_4_1_1_68_2,
    imebra::uidSurfaceSegmentationStorage_1_2_840_10008_5_1_4_1_1_66_5,
    //UID_TwelveLeadECGWaveformStorage,
    imebra::uidUltrasoundImageStorage_1_2_840_10008_5_1_4_1_1_6_1,
    imebra::uidUltrasoundMultiframeImageStorage_1_2_840_10008_5_1_4_1_1_3_1,
    imebra::uidVideoEndoscopicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_1_1,
    imebra::uidVideoMicroscopicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_2_1,
    imebra::uidVideoPhotographicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_4_1,
    imebra::uidVisualAcuityMeasurementsStorage_1_2_840_10008_5_1_4_1_1_78_5,
    imebra::uidVLEndoscopicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_1,
    imebra::uidVLMicroscopicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_2,
    imebra::uidVLPhotographicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_4,
    imebra::uidVLSlideCoordinatesMicroscopicImageStorage_1_2_840_10008_5_1_4_1_1_77_1_3,
    imebra::uidVLWholeSlideMicroscopyImageStorage_1_2_840_10008_5_1_4_1_1_77_1_6,
    imebra::uidXAXRFGrayscaleSoftcopyPresentationStateStorage_1_2_840_10008_5_1_4_1_1_11_5,
    imebra::uidXRay3DAngiographicImageStorage_1_2_840_10008_5_1_4_1_1_13_1_1,
    imebra::uidXRay3DCraniofacialImageStorage_1_2_840_10008_5_1_4_1_1_13_1_2,
    imebra::uidXRayAngiographicImageStorage_1_2_840_10008_5_1_4_1_1_12_1,
    imebra::uidXRayRadiationDoseSRStorage_1_2_840_10008_5_1_4_1_1_88_67,
    imebra::uidXRayRadiofluoroscopicImageStorage_1_2_840_10008_5_1_4_1_1_12_2,
    // retired
    imebra::uidHardcopyColorImageStorageSOPClass_1_2_840_10008_5_1_1_30,
    imebra::uidHardcopyGrayscaleImageStorageSOPClass_1_2_840_10008_5_1_1_29,
    imebra::uidNuclearMedicineImageStorageRetired_1_2_840_10008_5_1_4_1_1_5,
    imebra::uidStandaloneCurveStorage_1_2_840_10008_5_1_4_1_1_9,
    imebra::uidStandaloneModalityLUTStorage_1_2_840_10008_5_1_4_1_1_10,
    imebra::uidStandaloneOverlayStorage_1_2_840_10008_5_1_4_1_1_8,
    imebra::uidStandalonePETCurveStorage_1_2_840_10008_5_1_4_1_1_129,
    imebra::uidStandaloneVOILUTStorage_1_2_840_10008_5_1_4_1_1_11,
    imebra::uidStoredPrintStorageSOPClass_1_2_840_10008_5_1_1_27,
    imebra::uidUltrasoundImageStorageRetired_1_2_840_10008_5_1_4_1_1_6,
    imebra::uidVLImageStorageTrial_1_2_840_10008_5_1_4_1_1_77_1,
    imebra::uidVLMultiframeImageStorageTrial_1_2_840_10008_5_1_4_1_1_77_2,
    imebra::uidXRayAngiographicBiPlaneImageStorage_1_2_840_10008_5_1_4_1_1_12_3
    };
    }

    std::string createJsonResponse(eStatus status, const std::string& message, const json& j) 
    {
        std::string meaning = "success";
        if (status == PENDING) {
            meaning = "pending";
        }
        if (status == FAILURE) {
            meaning = "failure";
        }
        json v = json::object();
        v["container"] = j;
        v["messsage"] = message;
        v["code"] = (int)status;
        v["status"] = meaning;
        return v.dump();
    }

}