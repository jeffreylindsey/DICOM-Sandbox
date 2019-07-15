#include "DataElementDictionary.h"

namespace n_DICOM
{


/*****************************************************************************/
// Local Functions

/*===========================================================================*/
std::pair<s_DataElementTag, s_DataElementDefinition>
	MakeDataElementDictionaryEntry(const s_DataElementTag Tag, std::string Name)
{
	return std::make_pair(Tag, s_DataElementDefinition{Tag, std::move(Name)});
}

/*****************************************************************************/

const std::map<s_DataElementTag, s_DataElementDefinition> DataElementDictionary
	// Group 0002
	{ MakeDataElementDictionaryEntry
		( s_DataElementTag::FileMetaInformationGroupLength
		, "File Meta Information Group Length"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::FileMetaInformationVersion
		, "File Meta Information Version"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::MediaStorageSOPClassUID
		, "Media Storage SOP Class UID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::MediaStorageSOPInstanceUID
		, "Media Storage SOP Instance UID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::TransferSyntaxUID
		, "Transfer Syntax UID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ImplementationClassUID
		, "Implementation Class UID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ImplementationVersionName
		, "Implementation Version Name"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SourceApplicationEntityTitle
		, "Source Application Entity Title"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SendingApplicationEntityTitle
		, "Sending Application Entity Title"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ReceivingApplicationEntityTitle
		, "Receiving Application Entity Title"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PrivateInformationCreatorUID
		, "Private Information Creator UID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PrivateInformation
		, "Private Information"
		)

	// Group 0008
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SpecificCharacterSet
		, "Specific Character Set"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ImageType
		, "Image Type"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::InstanceCreationDate
		, "Instance Creation Date"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::InstanceCreationTime
		, "Instance Creation Time"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::InstanceCreatorUID
		, "Instance Creator UID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SOPClassUID
		, "SOP Class UID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SOPInstanceUID
		, "SOP Instance UID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::StudyDate
		, "Study Date"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SeriesDate
		, "Series Date"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::AcquisitionDate
		, "Acquisition Date"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ContentDate
		, "Content Date"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::StudyTime
		, "Study Time"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SeriesTime
		, "Series Time"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::AcquisitionTime
		, "Acquisition Time"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ContentTime
		, "Content Time"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::AccessionNumber
		, "Accession Number"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::Modality
		, "Modality"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::Manufacturer
		, "Manufacturer"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ReferringPhysicianName
		, "Referring Physician's Name"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::CodeValue
		, "Code Value"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::CodingSchemeDesignator
		, "Coding Scheme Designator"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::CodeMeaning
		, "Code Meaning"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::TimezoneOffsetFromUTC
		, "Timezone Offset From UTC"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::StudyDescription
		, "Study Description"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ProcedureCodeSequence
		, "Procedure Code Sequence"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SeriesDescription
		, "Series Description"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ReferencedPerformedProcedureStepSequence
		, "Referenced Performed Procedure Step Sequence"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ReferencedSOPClassUID
		, "Referenced SOP Class UID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ReferencedSOPInstanceUID
		, "Referenced SOP Instance UID"
		)

	// Group 0010
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PatientName
		, "Patient's Name"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PatientID
		, "Patient ID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PatientBirthDate
		, "Patient's Birth Date"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PatientSex
		, "Patient's Sex"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PatientAge
		, "Patient's Age"
		)

	// Group 0018
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ContrastBolusAgent
		, "Contrast/Bolus Agent"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::BodyPartExamined
		, "Body Part Examined"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ScanOptions
		, "Scan Options"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SliceThickness
		, "Slice Thickness"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::KVP
		, "KVP"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SpacingBetweenSlices
		, "Spacing Between Slices"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::DataCollectionDiameter
		, "Data Collection Diameter"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ProtocolName
		, "Protocol Name"
		)

	// Group 0020
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::StudyInstanceUID
		, "Study Instance UID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SeriesInstanceUID
		, "Series Instance UID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::StudyID
		, "Study ID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SeriesNumber
		, "Series Number"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::InstanceNumber
		, "Instance Number"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PatientOrientation
		, "Patient Orientation"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ImagePositionPatient
		, "Image Position (Patient)"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ImageOrientationPatient
		, "Image Orientation (Patient)"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::FrameReferenceUID
		, "Frame Reference UID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SliceLocation
		, "Slice Location"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ImageComments
		, "Image Comments"
		)

	// Group 0028
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SamplesPerPixel
		, "Samples per Pixel"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PhotometricInterpretation
		, "Photometric Interpretation"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::Rows
		, "Rows"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::Columns
		, "Columns"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PixelSpacing
		, "Pixel Spacing"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::BitsAllocated
		, "Bits Allocated"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::BitsStored
		, "Bits Stored"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::HighBit
		, "High Bit"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PixelRepresentation
		, "Pixel Representation"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PixelSpacingCalibrationType
		, "Pixel Spacing Calibration Type"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PixelSpacingCalibrationDescription
		, "Pixel Spacing Calibration Description"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::WindowCenter
		, "Window Center"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::WindowWidth
		, "Window Width"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::RescaleIntercept
		, "Rescale Intercept"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::RescaleSlope
		, "Rescale Slope"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::LossyImageCompression
		, "Lossy Image Compression"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::LossyImageCompressionRatio
		, "Lossy Image Compression Ratio"
		)

	// Group 0040
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ScheduledProcedureStepDescription
		, "Scheduled Procedure Step Description"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ScheduledProtocolCodeSequence
		, "Scheduled Protocol Code Sequence"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ScheduledProcedureStepID
		, "Scheduled Procedure Step ID"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PerformedProcedureStepDescription
		, "Performed Procedure Step Description"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PerformedProtocolCodeSequence
		, "Performed Protocol Code Sequence"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::RequestAttributesSequence
		, "Request Attributes Sequence"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::RequestedProcedureID
		, "Requested Procedure ID"
		)

	// Group 7FE0
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::PixelData
		, "Pixel Data"
		)

	// Group FFFE
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::Item
		, "Item"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::ItemDeliminationItem
		, "Item Delimitation Item"
		)
	, MakeDataElementDictionaryEntry
		( s_DataElementTag::SequenceDeliminationItem
		, "Sequence Delimitation Item"
		)
	};


}  // n_DICOM
