#include "DataElementTag.h"
#include "DataElementDictionary.h"

#include <iomanip>  // std::setw
#include <sstream>  // std::stringstream

namespace n_DICOM
{


/*****************************************************************************/
// s_DataElementTag

/*===========================================================================*/
bool s_DataElementTag::operator==(const s_DataElementTag& Right) const
{
	return GroupNumber == Right.GroupNumber
		&& ElementNumber == Right.ElementNumber;
}

/*===========================================================================*/
bool s_DataElementTag::operator!=(const s_DataElementTag& Right) const
{
	return !(*this == Right);
}

/*===========================================================================*/
bool s_DataElementTag::operator<(const s_DataElementTag& Right) const
{
	return GroupNumber < Right.GroupNumber
		|| (GroupNumber == Right.GroupNumber
			&& ElementNumber < Right.ElementNumber
		);
}

/*===========================================================================*/
bool s_DataElementTag::operator>(const s_DataElementTag& Right) const
{
	return (Right < *this);
}

/*===========================================================================*/
bool s_DataElementTag::operator<=(const s_DataElementTag& Right) const
{
	return !(*this > Right);
}

/*===========================================================================*/
bool s_DataElementTag::operator>=(const s_DataElementTag& Right) const
{
	return !(*this < Right);
}

/*===========================================================================*/
std::optional<std::string> s_DataElementTag::Name() const
{
	const auto FoundIter = DataElementDictionary.find(*this);

	if (FoundIter == DataElementDictionary.end())
		return std::nullopt;

	return FoundIter->second.Name;
}

/*===========================================================================*/
std::string s_DataElementTag::NumbersForDisplay() const
{
	std::stringstream StringStream;

	StringStream << std::hex << std::setfill('0') << "("
		<< std::setw(4) << GroupNumber << ","
		<< std::setw(4) << ElementNumber << ")";

	return StringStream.str();
}

/*===========================================================================*/

// Group 0002
const s_DataElementTag s_DataElementTag::FileMetaInformationGroupLength = {0x0002, 0x0000};
const s_DataElementTag s_DataElementTag::FileMetaInformationVersion = {0x0002, 0x0001};
const s_DataElementTag s_DataElementTag::MediaStorageSOPClassUID = {0x0002, 0x0002};
const s_DataElementTag s_DataElementTag::MediaStorageSOPInstanceUID = {0x0002, 0x0003};
const s_DataElementTag s_DataElementTag::TransferSyntaxUID = {0x0002, 0x0010};
const s_DataElementTag s_DataElementTag::ImplementationClassUID = {0x0002, 0x0012};
const s_DataElementTag s_DataElementTag::ImplementationVersionName = {0x0002, 0x0013};
const s_DataElementTag s_DataElementTag::SourceApplicationEntityTitle = {0x0002, 0x0016};
const s_DataElementTag s_DataElementTag::SendingApplicationEntityTitle = {0x0002, 0x0017};
const s_DataElementTag s_DataElementTag::ReceivingApplicationEntityTitle = {0x0002, 0x0018};
const s_DataElementTag s_DataElementTag::PrivateInformationCreatorUID = {0x0002, 0x0100};
const s_DataElementTag s_DataElementTag::PrivateInformation = {0x0002, 0x0102};

// Group 0008
const s_DataElementTag s_DataElementTag::SpecificCharacterSet = {0x0008, 0x0005};
const s_DataElementTag s_DataElementTag::ImageType = {0x0008, 0x0008};
const s_DataElementTag s_DataElementTag::InstanceCreationDate = {0x0008, 0x0012};
const s_DataElementTag s_DataElementTag::InstanceCreationTime = {0x0008, 0x0013};
const s_DataElementTag s_DataElementTag::InstanceCreatorUID = {0x0008, 0x0014};
const s_DataElementTag s_DataElementTag::SOPClassUID = {0x0008, 0x0016};
const s_DataElementTag s_DataElementTag::SOPInstanceUID = {0x0008, 0x0018};
const s_DataElementTag s_DataElementTag::StudyDate = {0x0008, 0x0020};
const s_DataElementTag s_DataElementTag::SeriesDate = {0x0008, 0x0021};
const s_DataElementTag s_DataElementTag::AcquisitionDate = {0x0008, 0x0022};
const s_DataElementTag s_DataElementTag::ContentDate = {0x0008, 0x0023};
const s_DataElementTag s_DataElementTag::StudyTime = {0x0008, 0x0030};
const s_DataElementTag s_DataElementTag::SeriesTime = {0x0008, 0x0031};
const s_DataElementTag s_DataElementTag::AcquisitionTime = {0x0008, 0x0032};
const s_DataElementTag s_DataElementTag::ContentTime = {0x0008, 0x0033};
const s_DataElementTag s_DataElementTag::AccessionNumber = {0x0008, 0x0050};
const s_DataElementTag s_DataElementTag::Modality = {0x0008, 0x0060};
const s_DataElementTag s_DataElementTag::Manufacturer = {0x0008, 0x0070};
const s_DataElementTag s_DataElementTag::ReferringPhysicianName = {0x0008, 0x0090};
const s_DataElementTag s_DataElementTag::CodeValue = {0x0008, 0x0100};
const s_DataElementTag s_DataElementTag::CodingSchemeDesignator = {0x0008, 0x0102};
const s_DataElementTag s_DataElementTag::CodeMeaning = {0x0008, 0x0104};
const s_DataElementTag s_DataElementTag::TimezoneOffsetFromUTC = {0x0008, 0x0201};
const s_DataElementTag s_DataElementTag::StudyDescription = {0x0008, 0x1030};
const s_DataElementTag s_DataElementTag::ProcedureCodeSequence = {0x0008, 0x1032};
const s_DataElementTag s_DataElementTag::SeriesDescription = {0x0008, 0x103E};
const s_DataElementTag s_DataElementTag::ReferencedPerformedProcedureStepSequence = {0x0008, 0x1111};
const s_DataElementTag s_DataElementTag::ReferencedSOPClassUID = {0x0008, 0x1150};
const s_DataElementTag s_DataElementTag::ReferencedSOPInstanceUID = {0x0008, 0x1155};

// Group 0010
const s_DataElementTag s_DataElementTag::PatientName = {0x0010, 0x0010};
const s_DataElementTag s_DataElementTag::PatientID = {0x0010, 0x0020};
const s_DataElementTag s_DataElementTag::PatientBirthDate = {0x0010, 0x0030};
const s_DataElementTag s_DataElementTag::PatientSex = {0x0010, 0x0040};
const s_DataElementTag s_DataElementTag::PatientAge = {0x0010, 0x1010};

// Group 0018
const s_DataElementTag s_DataElementTag::ContrastBolusAgent = {0x0018, 0x0010};
const s_DataElementTag s_DataElementTag::BodyPartExamined = {0x0018, 0x0015};
const s_DataElementTag s_DataElementTag::ScanOptions = {0x0018, 0x0022};
const s_DataElementTag s_DataElementTag::SliceThickness = {0x0018, 0x0050};
const s_DataElementTag s_DataElementTag::KVP = {0x0018, 0x0060};
const s_DataElementTag s_DataElementTag::SpacingBetweenSlices = {0x0018, 0x0088};
const s_DataElementTag s_DataElementTag::DataCollectionDiameter = {0x0018, 0x0090};
const s_DataElementTag s_DataElementTag::ProtocolName = {0x0018, 0x1030};

// Group 0020
const s_DataElementTag s_DataElementTag::StudyInstanceUID = {0x0020, 0x000D};
const s_DataElementTag s_DataElementTag::SeriesInstanceUID = {0x0020, 0x000E};
const s_DataElementTag s_DataElementTag::StudyID = {0x0020, 0x0010};
const s_DataElementTag s_DataElementTag::SeriesNumber = {0x0020, 0x0011};
const s_DataElementTag s_DataElementTag::InstanceNumber = {0x0020, 0x0013};
const s_DataElementTag s_DataElementTag::PatientOrientation = {0x0020, 0x0020};
const s_DataElementTag s_DataElementTag::ImagePositionPatient = {0x0020, 0x0032};
const s_DataElementTag s_DataElementTag::ImageOrientationPatient = {0x0020, 0x0037};
const s_DataElementTag s_DataElementTag::FrameReferenceUID = {0x0020, 0x0052};
const s_DataElementTag s_DataElementTag::SliceLocation = {0x0020, 0x1041};
const s_DataElementTag s_DataElementTag::ImageComments = {0x0020, 0x4000};

// Group 0028
const s_DataElementTag s_DataElementTag::SamplesPerPixel = {0x0028, 0x0002};
const s_DataElementTag s_DataElementTag::PhotometricInterpretation = {0x0028, 0x0004};
const s_DataElementTag s_DataElementTag::Rows = {0x0028, 0x0010};
const s_DataElementTag s_DataElementTag::Columns = {0x0028, 0x0011};
const s_DataElementTag s_DataElementTag::PixelSpacing = {0x0028, 0x0030};
const s_DataElementTag s_DataElementTag::BitsAllocated = {0x0028, 0x0100};
const s_DataElementTag s_DataElementTag::BitsStored = {0x0028, 0x0101};
const s_DataElementTag s_DataElementTag::HighBit = {0x0028, 0x0102};
const s_DataElementTag s_DataElementTag::PixelRepresentation = {0x0028, 0x0103};
const s_DataElementTag s_DataElementTag::PixelSpacingCalibrationType = {0x0028, 0x0A02};
const s_DataElementTag s_DataElementTag::PixelSpacingCalibrationDescription = {0x0028, 0x0A04};
const s_DataElementTag s_DataElementTag::WindowCenter = {0x0028, 0x1050};
const s_DataElementTag s_DataElementTag::WindowWidth = {0x0028, 0x1051};
const s_DataElementTag s_DataElementTag::RescaleIntercept = {0x0028, 0x1052};
const s_DataElementTag s_DataElementTag::RescaleSlope = {0x0028, 0x1053};
const s_DataElementTag s_DataElementTag::LossyImageCompression = {0x0028, 0x2110};
const s_DataElementTag s_DataElementTag::LossyImageCompressionRatio = {0x0028, 0x2112};

// Group 0040
const s_DataElementTag s_DataElementTag::ScheduledProcedureStepDescription = {0x0040, 0x0007};
const s_DataElementTag s_DataElementTag::ScheduledProtocolCodeSequence = {0x0040, 0x0008};
const s_DataElementTag s_DataElementTag::ScheduledProcedureStepID = {0x0040, 0x0009};
const s_DataElementTag s_DataElementTag::PerformedProcedureStepDescription = {0x0040, 0x0254};
const s_DataElementTag s_DataElementTag::PerformedProtocolCodeSequence = {0x0040, 0x0260};
const s_DataElementTag s_DataElementTag::RequestAttributesSequence = {0x0040, 0x0275};
const s_DataElementTag s_DataElementTag::RequestedProcedureID = {0x0040, 0x1001};

// Group 7FE0
const s_DataElementTag s_DataElementTag::PixelData = {0x7FE0, 0x0010};

// Group FFFE
const s_DataElementTag s_DataElementTag::Item = {0xFFFE, 0xE000};
const s_DataElementTag s_DataElementTag::ItemDeliminationItem = {0xFFFE, 0xE00D};
const s_DataElementTag s_DataElementTag::SequenceDeliminationItem = {0xFFFE, 0xE0DD};


}  // n_DICOM
