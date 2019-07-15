#pragma once

#include "DataElementTag.h"
#include "DataElementHeader.h"

#include "Generic/InStream.h"

namespace n_DICOM
{


/******************************************************************************
// c_InStream

This class adds functionality on top of the n_Generic::c_InStream class for
reading higher level data according to DICOM specifications.
-----------------------------------------------------------------------------*/
class c_InStream
	: public n_Generic::c_InStream
{
	//--- Public Methods ------------------------------------------------------
	public:
		c_InStream(std::istream& r_Stream);
		c_InStream(n_Generic::c_InStream& r_InStream, const uint64_t Length);

		bool ReadFileHeader();

		uint16_t ReadUInt16();
		uint32_t ReadUInt32();

		s_DataElementTag ReadDataElementTag();
		s_DataElementHeader ReadDataElementHeader();
};

/*****************************************************************************/


}  // n_DICOM
