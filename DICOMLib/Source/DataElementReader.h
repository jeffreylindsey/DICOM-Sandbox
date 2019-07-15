#pragma once

#include "DataElementHeader.h"
#include "InStream.h"

#include <string>  // std::string

namespace n_DICOM
{


/******************************************************************************
// s_Date

Note: this structure is for demonstration purposes only.  It's not a great way
to describe a date.
-----------------------------------------------------------------------------*/
struct s_Date
{
	std::string Year;
	std::string Month;
	std::string Day;
};

/******************************************************************************
// s_Time

Note: this structure is for demonstration purposes only.  It's not a great way
to describe a time.
-----------------------------------------------------------------------------*/
struct s_Time
{
	std::string Hour;
	std::string Minute;
	std::string Second;
};

/******************************************************************************
// s_Age

Note: this structure is for demonstration purposes only.  It's not a great way
to describe an age.
-----------------------------------------------------------------------------*/
struct s_Age
{
	std::string Number;
	std::string Units;
};

/******************************************************************************
// c_DataElementReader

This class facilitates reading a complete data element from a stream.  This
class cannot be created directly, but use the static ReadFrom method to get an
instance of this class.  When the instance of this class is destroyed, the
input stream will be advanced to the end of the data element, regardless of
whether the data in the element was read or not.
-----------------------------------------------------------------------------*/
class c_DataElementReader
{
	//--- Public Static Methods -----------------------------------------------
	public:
		static c_DataElementReader ReadFrom(c_InStream& r_In);

	//--- Public Methods ------------------------------------------------------
	public:
		c_DataElementReader(const c_DataElementReader&) = delete;
		c_DataElementReader(c_DataElementReader&&) = delete;

		c_DataElementReader& operator=(const c_DataElementReader&) = delete;
		c_DataElementReader& operator=(c_DataElementReader&&) = delete;

		const s_DataElementHeader& Header() const;
		c_InStream& ValueSegment();

		bool IsValueLengthIdentified() const;
		bool IsSequenceOfItems() const;

		uint16_t ReadUnsignedShort();
		uint32_t ReadUnsignedLong();
		s_Date ReadDate();
		s_Time ReadTime();
		s_Age ReadAgeString();
		std::string ReadString();

	//--- Private Static Methods ----------------------------------------------
	private:
		static uint64_t DetermineStreamLength
			( const s_DataElementHeader& DataElementHeader
			);

	//--- Private Methods -----------------------------------------------------
	private:
		explicit c_DataElementReader(c_InStream& r_In);

	//--- Private Members -----------------------------------------------------
	private:
		s_DataElementHeader m_Header;

		c_InStream m_ValueSegment;
};

/*****************************************************************************/


}  // n_DICOM
