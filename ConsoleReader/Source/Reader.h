#pragma once

#include "DICOM/DataElementTag.h"
#include "DICOM/DataElementHeader.h"
#include "DICOM/InStream.h"

#include <string>  // std::string

namespace n_DICOM
{
	class c_DataElementReader;
}

/******************************************************************************
// c_Reader

Reads the contents of a DICOM data stream, and displays the interpreted
contents to standard output stream.
-----------------------------------------------------------------------------*/
class c_Reader
{
	//--- Public Methods ------------------------------------------------------
	public:
		void ReadAndDisplayDataSet(n_DICOM::c_InStream& r_In);

	//--- Private Types -------------------------------------------------------
	private:
		using c_DataElementReader = n_DICOM::c_DataElementReader;
		using c_InStream = n_DICOM::c_InStream;

	//--- Private Methods -----------------------------------------------------
	private:
		void ReadAndDisplaySequenceOfItems(c_DataElementReader& r_DataElement);

		void ReadAndDisplayBasicOffsetTable(c_InStream& r_In);
		void ReadAndDisplayPixelData(c_InStream& r_In);

		std::string ReadValueForDisplay(c_DataElementReader& r_DataElement);
		std::string ReadUnsignedShortValueForDisplay
			( c_DataElementReader& r_DataElement
			);
		std::string ReadUnsignedLongValueForDisplay
			( c_DataElementReader& r_DataElement
			);
		std::string ReadDateValueForDisplay(c_DataElementReader& r_DataElement);
		std::string ReadTimeValueForDisplay(c_DataElementReader& r_DataElement);
		std::string ReadAgeStringValueForDisplay
			( c_DataElementReader& r_DataElement
			);
		std::string ReadStringValueForDisplay
			( c_DataElementReader& r_DataElement
			);
		std::string ReadBinaryValueForDisplay
			( c_DataElementReader& r_DataElement
			);

	//--- Private Methods -----------------------------------------------------
	private:
		// This is used to indent nested data sets, such as sequences of items
		// that may contain items with additional sequences of items.
		int m_NestingLevel = 0;
};

/*****************************************************************************/
