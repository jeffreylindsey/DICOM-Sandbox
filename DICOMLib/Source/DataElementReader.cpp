#include "DataElementReader.h"
#include "ValueRepresentation.h"

#include <cassert>  // assert

namespace n_DICOM
{


/*****************************************************************************/
// c_DataElementReader

/*=============================================================================
	Static

	This is the only public way to construct an object of this type.
-----------------------------------------------------------------------------*/
c_DataElementReader c_DataElementReader::ReadFrom(c_InStream& r_In)
{
	return c_DataElementReader(r_In);
}

/*===========================================================================*/
const s_DataElementHeader& c_DataElementReader::Header() const
{
	return m_Header;
}

/*===========================================================================*/
c_InStream& c_DataElementReader::ValueSegment()
{
	return m_ValueSegment;
}

/*=============================================================================
	Returns true only if the number of bytes for the value of this element has
	been specified.  In other words, the length of the value is not
	unidentified.
-----------------------------------------------------------------------------*/
bool c_DataElementReader::IsValueLengthIdentified() const
{
	return m_ValueSegment.IsLengthIdentified();
}

/*=============================================================================
	Returns true only if this data element contains a sequence of items.
-----------------------------------------------------------------------------*/
bool c_DataElementReader::IsSequenceOfItems() const
{
	return m_Header.ValueRepresentation == c_ValueRepresentation::VR_SQ
		|| (m_Header.Tag == s_DataElementTag::PixelData
			&& !IsValueLengthIdentified()
		);
}

/*===========================================================================*/
uint16_t c_DataElementReader::ReadUnsignedShort()
{
	assert(m_Header.ValueRepresentation == c_ValueRepresentation::VR_US);
	assert(m_Header.ValueLength == 2);
	assert(m_ValueSegment.IsLengthIdentified());

	return m_ValueSegment.ReadUInt16();
}

/*===========================================================================*/
uint32_t c_DataElementReader::ReadUnsignedLong()
{
	assert(m_Header.ValueRepresentation == c_ValueRepresentation::VR_UL);
	assert(m_Header.ValueLength == 4);
	assert(m_ValueSegment.IsLengthIdentified());

	return m_ValueSegment.ReadUInt32();
}

/*===========================================================================*/
s_Date c_DataElementReader::ReadDate()
{
	assert(m_Header.ValueRepresentation == c_ValueRepresentation::VR_DA);
	assert(m_Header.ValueLength == 8);
	assert(m_ValueSegment.IsLengthIdentified());

	char ValueBuffer[8] = {0};
	m_ValueSegment.ReadRaw(ValueBuffer);

	s_Date Date;

	Date.Year = std::string(ValueBuffer + 0, 4);
	Date.Month = std::string(ValueBuffer + 4, 2);
	Date.Day = std::string(ValueBuffer + 6, 2);

	return Date;
}

/*===========================================================================*/
s_Time c_DataElementReader::ReadTime()
{
	assert(m_Header.ValueRepresentation == c_ValueRepresentation::VR_TM);
	assert(m_Header.ValueLength <= 14);
	assert(m_ValueSegment.IsLengthIdentified());

	const int ValueLength = m_Header.ValueLength;

	char ValueBuffer[14];
	m_ValueSegment.Read(ValueBuffer, ValueLength);

	s_Time Time;

	if (ValueLength >= 2)
		Time.Hour = std::string(ValueBuffer + 0, 2);
	if (ValueLength >= 4)
		Time.Minute = std::string(ValueBuffer + 2, 2);
	if (ValueLength >= 6)
	{
		Time.Second
			= std::string(ValueBuffer + 4, static_cast<size_t>(ValueLength) - 4);
	}

	return Time;
}

/*===========================================================================*/
s_Age c_DataElementReader::ReadAgeString()
{
	assert(m_Header.ValueRepresentation == c_ValueRepresentation::VR_AS);
	assert(m_Header.ValueLength == 4);
	assert(m_ValueSegment.IsLengthIdentified());

	char ValueBuffer[4] = {};
	m_ValueSegment.ReadRaw(ValueBuffer);

	s_Age Age;

	Age.Number = std::string(ValueBuffer, 3);

	switch (ValueBuffer[3])
	{
		case 'D':
			Age.Units = "days";
		break;

		case 'W':
			Age.Units = "weeks";
		break;

		case 'M':
			Age.Units = "months";
		break;

		case 'Y':
			Age.Units = "years";
		break;
	}

	return Age;
}

/*===========================================================================*/
std::string c_DataElementReader::ReadString()
{
	assert(m_ValueSegment.IsLengthIdentified());

	std::string String;
	String.resize(m_Header.ValueLength);

	m_ValueSegment.Read(String.data(), m_Header.ValueLength);

	// Note: This code has no consideration of text encoding.

	return String;
}

/*===========================================================================*/
uint64_t c_DataElementReader::DetermineStreamLength
( const s_DataElementHeader& DataElementHeader
)
{
	static const uint32_t UnidentifiedLength = 0xFFFFFFFF;

	if (DataElementHeader.ValueLength == UnidentifiedLength)
		return c_InStream::UnidentifiedLength;

	return DataElementHeader.ValueLength;
}

/*===========================================================================*/
c_DataElementReader::c_DataElementReader(c_InStream& r_In)
	: m_Header(r_In.ReadDataElementHeader())
	, m_ValueSegment(r_In, DetermineStreamLength(m_Header))
{
}

/*===========================================================================*/


}  // n_DICOM
