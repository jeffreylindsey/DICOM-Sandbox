#pragma once

#include <optional>  // std::optional
#include <string>  // std::string

namespace n_DICOM
{


/*****************************************************************************/
// s_DataElementTag

struct s_DataElementTag
{
	//--- Members -------------------------------------------------------------

	uint16_t GroupNumber = 0;
	uint16_t ElementNumber = 0;

	//--- Methods -------------------------------------------------------------

	bool operator==(const s_DataElementTag& Right) const;
	bool operator!=(const s_DataElementTag& Right) const;
	bool operator<(const s_DataElementTag& Right) const;
	bool operator>(const s_DataElementTag& Right) const;
	bool operator<=(const s_DataElementTag& Right) const;
	bool operator>=(const s_DataElementTag& Right) const;

	std::optional<std::string> Name() const;
	std::string NumbersForDisplay() const;

	//--- Static Instances ----------------------------------------------------

	// Group 0002
	static const s_DataElementTag FileMetaInformationGroupLength;  // (0002,0000)
	static const s_DataElementTag FileMetaInformationVersion;  // (0002,0001)
	static const s_DataElementTag MediaStorageSOPClassUID;  // (0002,0002)
	static const s_DataElementTag MediaStorageSOPInstanceUID;  // (0002,0003)
	static const s_DataElementTag TransferSyntaxUID;  // (0002,0010)
	static const s_DataElementTag ImplementationClassUID;  // (0002,0012)
	static const s_DataElementTag ImplementationVersionName;  // (0002,0013)
	static const s_DataElementTag SourceApplicationEntityTitle;  // (0002,0016)
	static const s_DataElementTag SendingApplicationEntityTitle;  // (0002,0017)
	static const s_DataElementTag ReceivingApplicationEntityTitle;  // (0002,0018)
	static const s_DataElementTag PrivateInformationCreatorUID;  // (0002,0100)
	static const s_DataElementTag PrivateInformation;  // (0002,0102)

	// Group 0008
	static const s_DataElementTag SpecificCharacterSet;  // (0008,0005)
	static const s_DataElementTag ImageType;  // (0008,0008)
	static const s_DataElementTag InstanceCreationDate;  // (0008,0012)
	static const s_DataElementTag InstanceCreationTime;  // (0008,0013)
	static const s_DataElementTag InstanceCreatorUID;  // (0008,0014)
	static const s_DataElementTag SOPClassUID;  // (0008,0016)
	static const s_DataElementTag SOPInstanceUID;  // (0008,0018)
	static const s_DataElementTag StudyDate;  // (0008,0020)
	static const s_DataElementTag SeriesDate;  // (0008,0021)
	static const s_DataElementTag AcquisitionDate;  // (0008,0022)
	static const s_DataElementTag ContentDate;  // (0008,0023)
	static const s_DataElementTag StudyTime;  // (0008,0030)
	static const s_DataElementTag SeriesTime;  // (0008,0031)
	static const s_DataElementTag AcquisitionTime;  // (0008,0032)
	static const s_DataElementTag ContentTime;  // (0008,0033)
	static const s_DataElementTag AccessionNumber;  // (0008,0050)
	static const s_DataElementTag Modality;  // (0008,0060)
	static const s_DataElementTag Manufacturer;  // (0008,0070)
	static const s_DataElementTag ReferringPhysicianName;  // (0008,0090)
	static const s_DataElementTag CodeValue;  // (0008,0100)
	static const s_DataElementTag CodingSchemeDesignator;  // (0008,0102)
	static const s_DataElementTag CodeMeaning;  // (0008,0104)
	static const s_DataElementTag TimezoneOffsetFromUTC;  // (0008,0201)
	static const s_DataElementTag StudyDescription;  // (0008,1030)
	static const s_DataElementTag ProcedureCodeSequence;  // (0008,1032)
	static const s_DataElementTag SeriesDescription;  // (0008,103E)
	static const s_DataElementTag ReferencedPerformedProcedureStepSequence;  // (0008,1111)
	static const s_DataElementTag ReferencedSOPClassUID;  // (0008,1150)
	static const s_DataElementTag ReferencedSOPInstanceUID;  // (0008,1155)

	// Group 0010
	static const s_DataElementTag PatientName;  // (0010,0010)
	static const s_DataElementTag PatientID;  // (0010,0020)
	static const s_DataElementTag PatientBirthDate;  // (0010,0030)
	static const s_DataElementTag PatientSex;  // (0010,0040)
	static const s_DataElementTag PatientAge;  // (0010,1010)

	// Group 0018
	static const s_DataElementTag ContrastBolusAgent;  // (0018,0010)
	static const s_DataElementTag BodyPartExamined;  // (0018,0015)
	static const s_DataElementTag ScanOptions;  // (0018,0022)
	static const s_DataElementTag SliceThickness;  // (0018,0050)
	static const s_DataElementTag KVP;  // (0018,0060)
	static const s_DataElementTag SpacingBetweenSlices;  // (0018,0088)
	static const s_DataElementTag DataCollectionDiameter;  // (0018,0090)
	static const s_DataElementTag ProtocolName;  // (0018,1030)

	// Group 0020
	static const s_DataElementTag StudyInstanceUID;  // (0020,000D)
	static const s_DataElementTag SeriesInstanceUID;  // (0020,000E)
	static const s_DataElementTag StudyID;  // (0020,0010)
	static const s_DataElementTag SeriesNumber;  // (0020,0011)
	static const s_DataElementTag InstanceNumber;  // (0020,0013)
	static const s_DataElementTag PatientOrientation;  // (0020,0020)
	static const s_DataElementTag ImagePositionPatient;  // (0020,0032)
	static const s_DataElementTag ImageOrientationPatient;  // (0020,0037)
	static const s_DataElementTag FrameReferenceUID;  // (0020,0052)
	static const s_DataElementTag SliceLocation;  // (0020,1041)
	static const s_DataElementTag ImageComments;  // (0020,4000)

	// Group 0028
	static const s_DataElementTag SamplesPerPixel;  // (0028,0002)
	static const s_DataElementTag PhotometricInterpretation;  // (0028,0004)
	static const s_DataElementTag Rows;  // (0028,0010)
	static const s_DataElementTag Columns;  // (0028,0011)
	static const s_DataElementTag PixelSpacing;  // (0028,0030)
	static const s_DataElementTag BitsAllocated;  // (0028,0100)
	static const s_DataElementTag BitsStored;  // (0028,0101)
	static const s_DataElementTag HighBit;  // (0028,0102)
	static const s_DataElementTag PixelRepresentation;  // (0028,0103)
	static const s_DataElementTag PixelSpacingCalibrationType;  // (0028,0A02)
	static const s_DataElementTag PixelSpacingCalibrationDescription;  // (0028,0A04)
	static const s_DataElementTag WindowCenter;  // (0028,1050)
	static const s_DataElementTag WindowWidth;  // (0028,1051)
	static const s_DataElementTag RescaleIntercept;  // (0028,1052)
	static const s_DataElementTag RescaleSlope;  // (0028,1053)
	static const s_DataElementTag LossyImageCompression;  // (0028,2110)
	static const s_DataElementTag LossyImageCompressionRatio;  // (0028,2112)

	// Group 0040
	static const s_DataElementTag ScheduledProcedureStepDescription;  // (0040,0007)
	static const s_DataElementTag ScheduledProtocolCodeSequence;  // (0040,0008)
	static const s_DataElementTag ScheduledProcedureStepID;  // (0040,0009)
	static const s_DataElementTag PerformedProcedureStepDescription;  // (0040,0254)
	static const s_DataElementTag PerformedProtocolCodeSequence;  // (0040,0260)
	static const s_DataElementTag RequestAttributesSequence;  // (0040,0275)
	static const s_DataElementTag RequestedProcedureID;  // (0040,1001)

	// Group 7FE0
	static const s_DataElementTag PixelData;  // (7FE0,0010)

	// Group FFFE
	static const s_DataElementTag Item;  // (FFFE,E000)
	static const s_DataElementTag ItemDeliminationItem;  // (FFFE,E00D)
	static const s_DataElementTag SequenceDeliminationItem;  // (FFFE,E0DD)
};

/*****************************************************************************/


}  // n_DICOM
