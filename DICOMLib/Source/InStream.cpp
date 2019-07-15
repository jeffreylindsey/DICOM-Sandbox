#include "InStream.h"

#include <string_view>  // std::string_view

namespace n_DICOM
{


/*****************************************************************************/
// c_InStream

/*===========================================================================*/
c_InStream::c_InStream(std::istream& r_Stream)
	: n_Generic::c_InStream(r_Stream)
{
}

/*===========================================================================*/
c_InStream::c_InStream(n_Generic::c_InStream& r_InStream, const uint64_t Length)
	: n_Generic::c_InStream(r_InStream, Length)
{
}

/*=============================================================================
	Reads the stream as if it is the very beginning of a DICOM file on disk.
	Returns true only if this is a valid DICOM file.
-----------------------------------------------------------------------------*/
bool c_InStream::ReadFileHeader()
{
	// File Preamble
	//
	// A fixed 128 byte field available for Application Profile or
	// implementation specified use.  If not used by an Application Profile or
	// a specific implementation all bytes shall be set to 00H.
	//
	// File-set Readers or Updaters shall not rely on the content of this
	// Preamble to determine that this File is or is not a DICOM File.
	Skip(128);

	// DICOM Prefix
	char DICOMPrefix[4] = {};
	ReadRaw(DICOMPrefix);

	// Note: Documentation says this uses ISO 8859 G0 Character Repertoire,
	// which for these letters is comparable to ASCII.
	return (std::string_view(DICOMPrefix, 4) == "DICM");
}

/*===========================================================================*/
uint16_t c_InStream::ReadUInt16()
{
	uint16_t Value = 0;
	ReadRaw(Value);

	// Note: This function currently assumes the endianness of the hardware
	// matches the endianness of the data in the stream.

	return Value;
}

/*===========================================================================*/
uint32_t c_InStream::ReadUInt32()
{
	uint32_t Value = 0;
	ReadRaw(Value);

	// Note: This function currently assumes the endianness of the hardware
	// matches the endianness of the data in the stream.

	return Value;
}

/*===========================================================================*/
s_DataElementTag c_InStream::ReadDataElementTag()
{
	s_DataElementTag DataElementTag;

	// Data Element Tag
	//
	// An ordered pair of 16-bit unsigned integers representing the Group
	// Number followed by Element Number.
	//
	// Note: For files, these values are always stored in Little Endian byte
	// order.
	DataElementTag.GroupNumber = ReadUInt16();
	DataElementTag.ElementNumber = ReadUInt16();

	return DataElementTag;
}

/*===========================================================================*/
s_DataElementHeader c_InStream::ReadDataElementHeader()
{
	s_DataElementHeader DataElementHeader;

	DataElementHeader.Tag = ReadDataElementTag();

	// Value Representation (VR)
	//
	// Two single byte characters containing the VR of the Data Element.  The
	// VR for a given Data Element Tag shall be as defined by the Data
	// Dictionary as specified in PS3.6.  The two byte VR shall be encoded
	// using only upper case letters from the DICOM default character set.
	//
	// Note: VR is not optional in the file format.
	ReadRaw(DataElementHeader.ValueRepresentation);

	const bool HasReservedBytes
		= DataElementHeader.ValueRepresentation.HasReservedBytes();

	// Skip past reserved bytes that may exist after the VR.
	if (HasReservedBytes)
		Skip(2);

	// Value Length
	if (HasReservedBytes)
		DataElementHeader.ValueLength = ReadUInt32();
	else
		DataElementHeader.ValueLength = ReadUInt16();

	return DataElementHeader;
}

/*===========================================================================*/


}  // n_DICOM
