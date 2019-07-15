#include "Reader.h"

#include "DICOM/DataElementReader.h"
#include "DICOM/ValueRepresentation.h"

#include "Generic/ToString.h"

#include <cassert>  // assert
#include <iostream>  // std::cout

using n_DICOM::s_DataElementTag;
using n_DICOM::c_ValueRepresentation;

using n_Generic::ToString;

/*****************************************************************************/
// c_Reader

/*===========================================================================*/
void c_Reader::ReadAndDisplayDataSet(c_InStream& r_In)
{
	// Create a string for indenting to the current nesting level.
	const std::string Indent(m_NestingLevel, '\t');

	// Iterate through the data elements.
	while (!r_In.EncounteredError() && !r_In.IsAtEnd())
	{
		// Read the next data element.
		c_DataElementReader DataElement = c_DataElementReader::ReadFrom(r_In);

		const auto& DataElementHeader = DataElement.Header();
		const auto& Tag = DataElementHeader.Tag;
		const auto& ValueRepresentation = DataElementHeader.ValueRepresentation;

		const std::optional<std::string>& TagName = Tag.Name();

		if (TagName.has_value())
			std::cout << Indent << TagName.value();
		else
		{
			std::cout << Indent << Tag.NumbersForDisplay() << " "
				<< ValueRepresentation.Name();
		}

		if (DataElement.IsSequenceOfItems())
		{
			std::cout << "\n";

			// This will recursively call back into this function for each
			// item in the sequence.
			ReadAndDisplaySequenceOfItems(DataElement);
		}
		else
			std::cout << ": " << ReadValueForDisplay(DataElement) << "\n";
	}
}

/*===========================================================================*/
void c_Reader::ReadAndDisplaySequenceOfItems
( c_DataElementReader& r_DataElement
)
{
	c_InStream& r_In = r_DataElement.ValueSegment();

	const bool IsUnidentifiedLength = !r_DataElement.IsValueLengthIdentified();
	const bool IsPixelData
		= (r_DataElement.Header().Tag == s_DataElementTag::PixelData);

	++m_NestingLevel;

	// Create a string for indenting to the current nesting level.
	const std::string Indent(m_NestingLevel, '\t');

	int ItemNumber = 1;

	while (!r_In.EncounteredError() && !r_In.IsAtEnd())
	{
		const bool IsBasicOffsetTable = (IsPixelData && ItemNumber == 1);

		const s_DataElementTag ItemTag = r_In.ReadDataElementTag();

		if (ItemTag != s_DataElementTag::Item
			&& ItemTag != s_DataElementTag::ItemDeliminationItem
			&& ItemTag != s_DataElementTag::SequenceDeliminationItem
		)
		{
			std::cout << "Expected Item but encountered something else.\n";

			// Note: We are unable to assume any more meaningful data from
			// this data element, but we should at least be able to skip to
			// the end of this data element and move on to the next.
			break;
		}

		const uint32_t ItemLength = r_In.ReadUInt32();

		// Note: We have reached the end of the item set with an unidentified
		// length when we encounter an item with length 0.
		if (IsUnidentifiedLength && ItemLength == 0 && !IsBasicOffsetTable)
			break;

		// Isolate the data in the stream for this item.
		c_InStream ItemData(r_In, ItemLength);

		if (IsBasicOffsetTable)
		{
			std::cout << Indent << "[Basic Offset Table]\n";
			ReadAndDisplayBasicOffsetTable(ItemData);
		}
		else if (IsPixelData)
		{
			std::cout << Indent << "[Frame " << ItemNumber - 1 << "]\n";
			ReadAndDisplayPixelData(ItemData);
		}
		else
		{
			std::cout << Indent << "[Item " << ItemNumber << "]\n";
			ReadAndDisplayDataSet(ItemData);
		}

		++ItemNumber;
	}

	--m_NestingLevel;
}

/*===========================================================================*/
void c_Reader::ReadAndDisplayBasicOffsetTable(c_InStream& r_In)
{
	// Create a string for indenting to the current nesting level.
	const std::string Indent(m_NestingLevel, '\t');

	// When the Item Value is present, the Basic Offset Table Item Value shall
	// contain concatenated 32-bit unsigned integer values that are byte
	// offsets to the first byte of the Item Tag of the first fragment for
	// each frame in the Sequence of Items.  These offsets are measured from
	// the first byte of the first Item Tag following the Basic Offset Table
	// item.

	int FrameNumber = 1;

	while (!r_In.EncounteredError() && !r_In.IsAtEnd())
	{
		const uint32_t Offset = r_In.ReadUInt32();

		std::cout << Indent << "Frame " << FrameNumber << " offset: "
			<< Offset << " bytes\n";

		++FrameNumber;
	}
}

/*===========================================================================*/
void c_Reader::ReadAndDisplayPixelData(c_InStream& r_In)
{
	// Create a string for indenting to the current nesting level.
	const std::string Indent(m_NestingLevel, '\t');

	std::cout << Indent << r_In.RemainingLength() << " bytes of pixel data\n";
}

/*=============================================================================
	Returns the string representation of the value.
-----------------------------------------------------------------------------*/
std::string c_Reader::ReadValueForDisplay(c_DataElementReader& r_DataElement)
{
	switch (r_DataElement.Header().ValueRepresentation)
	{
		case c_ValueRepresentation::VR_US:
		return ReadUnsignedShortValueForDisplay(r_DataElement);

		case c_ValueRepresentation::VR_UL:
		return ReadUnsignedLongValueForDisplay(r_DataElement);

		case c_ValueRepresentation::VR_DA:
		return ReadDateValueForDisplay(r_DataElement);

		case c_ValueRepresentation::VR_TM:
		return ReadTimeValueForDisplay(r_DataElement);

		case c_ValueRepresentation::VR_AS:
		return ReadAgeStringValueForDisplay(r_DataElement);

		default:
		{
			if (r_DataElement.Header().ValueRepresentation.IsValueCharacters())
				return ReadStringValueForDisplay(r_DataElement);
			else
				return ReadBinaryValueForDisplay(r_DataElement);
		}
	}
}

/*===========================================================================*/
std::string c_Reader::ReadUnsignedShortValueForDisplay
( c_DataElementReader& r_DataElement
)
{
	if (r_DataElement.Header().ValueLength != 2)
		return "Invalid value length.  Expected a length of 2.";

	const uint16_t Value = r_DataElement.ReadUnsignedShort();

	return ToString(Value);
}

/*===========================================================================*/
std::string c_Reader::ReadUnsignedLongValueForDisplay
( c_DataElementReader& r_DataElement
)
{
	if (r_DataElement.Header().ValueLength != 4)
		return "Invalid value length.  Expected a length of 4.";

	const uint32_t Value = r_DataElement.ReadUnsignedLong();

	return ToString(Value);
}

/*===========================================================================*/
std::string c_Reader::ReadDateValueForDisplay
( c_DataElementReader& r_DataElement
)
{
	// This is a special case that was discovered through sample data.
	if (r_DataElement.Header().ValueLength == 0)
		return {};

	if (r_DataElement.Header().ValueLength != 8)
		return "Invalid value length.  Expected a length of 8.";

	const n_DICOM::s_Date Date = r_DataElement.ReadDate();

	// Print as YYYY-MM-DD.
	return Date.Year + "-" + Date.Month + "-" + Date.Day;
}

/*===========================================================================*/
std::string c_Reader::ReadTimeValueForDisplay
( c_DataElementReader& r_DataElement
)
{
	if (r_DataElement.Header().ValueLength > 14)
		return "Invalid value length.  Expected a length of 14 or less.";

	const n_DICOM::s_Time Time = r_DataElement.ReadTime();

	// Print as HH:MM:SS.FFFFFF.
	return Time.Hour + ":" + Time.Minute + ":" + Time.Second;
}

/*===========================================================================*/
std::string c_Reader::ReadAgeStringValueForDisplay
( c_DataElementReader& r_DataElement
)
{
	if (r_DataElement.Header().ValueLength != 4)
		return "Invalid value length.  Expected a length of 4.";

	const n_DICOM::s_Age Age = r_DataElement.ReadAgeString();

	return Age.Number + " " + Age.Units;
}

/*===========================================================================*/
std::string c_Reader::ReadStringValueForDisplay
( c_DataElementReader& r_DataElement
)
{
	const std::string Value = r_DataElement.ReadString();

	const size_t DisplayLengthLimit = 70;

	if (Value.length() > DisplayLengthLimit)
		return Value.substr(0, DisplayLengthLimit) + "...";

	return Value;
}

/*===========================================================================*/
std::string c_Reader::ReadBinaryValueForDisplay
( c_DataElementReader& r_DataElement
)
{
	// We are not going to actually read the data, so we are relying on the
	// data element to skip over the data when it gets destroyed.
	assert(r_DataElement.IsValueLengthIdentified());

	return "(binary data, "
		+ ToString(r_DataElement.Header().ValueLength)
		+ " bytes)";
}

/*===========================================================================*/
