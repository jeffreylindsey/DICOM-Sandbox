#include "InStream.h"

#include <cassert>  // assert

namespace n_Generic
{


/*****************************************************************************/
// c_InStream

/*===========================================================================*/
c_InStream::c_InStream(std::istream& r_Stream)
	: m_r_Stream(r_Stream)
{
}

/*===========================================================================*/
c_InStream::c_InStream(c_InStream& r_InStream, const uint64_t Length)
	: m_r_Stream(r_InStream.m_r_Stream)
	, m_p_Source(&r_InStream)
	, m_RemainingLength(Length)
{
	if (m_p_Source != nullptr)
	{
		if (m_RemainingLength > m_p_Source->m_RemainingLength)
			m_RemainingLength = m_p_Source->m_RemainingLength;
	}
}

/*===========================================================================*/
c_InStream::~c_InStream()
{
	if (IsLengthIdentified() && m_RemainingLength > 0)
		Skip(m_RemainingLength);
}

/*=============================================================================
	Returns true only if an error condition has occurred on the stream,
	meaning that no more data can be reliably read.
-----------------------------------------------------------------------------*/
bool c_InStream::EncounteredError() const
{
	return m_Error
		|| m_r_Stream.fail()
		|| (m_p_Source != nullptr && m_p_Source->EncounteredError());
}

/*=============================================================================
	Returns true only if there is no more data to read.
-----------------------------------------------------------------------------*/
bool c_InStream::IsAtEnd() const
{
	// This is to sent the eof flag on the stream if the next byte is just
	// beyond the end.
	m_r_Stream.peek();

	return m_RemainingLength == 0
		|| m_r_Stream.eof()
		|| (m_p_Source != nullptr && m_p_Source->IsAtEnd());
}

/*=============================================================================
	Returns true only if this stream only has a limited number of bytes
	remaining.  In other words, this is not a segment of unidentified length.
-----------------------------------------------------------------------------*/
bool c_InStream::IsLengthIdentified() const
{
	return (m_RemainingLength != UnidentifiedLength);
}

/*=============================================================================
	Returns the number of bytes that are remaining in this stream segment.
	This is only valid if the length is identified.
-----------------------------------------------------------------------------*/
uint64_t c_InStream::RemainingLength() const
{
	return m_RemainingLength;
}

/*=============================================================================
	Moves forward in the input stream by the given Length in bytes.  The
	skipped data is not stored anywhere.
-----------------------------------------------------------------------------*/
void c_InStream::Skip(const uint64_t Length)
{
	if (IsLengthIdentified() && Length > m_RemainingLength)
	{
		m_Error = true;
		return Skip(m_RemainingLength);
	}

	m_r_Stream.ignore(Length);
	assert(m_r_Stream);
	OnBytesConsumed(Length);
}

/*=============================================================================
	Reads the given Length number of bytes from the input stream directly into
	the memory pointer to by p_Buffer.
-----------------------------------------------------------------------------*/
void c_InStream::Read(void* p_Buffer, const uint64_t Length)
{
	if (IsLengthIdentified() && Length > m_RemainingLength)
	{
		m_Error = true;
		return Read(p_Buffer, m_RemainingLength);
	}

	m_r_Stream.read(reinterpret_cast<char*>(p_Buffer), Length);
	assert(m_r_Stream);
	OnBytesConsumed(Length);
}

/*===========================================================================*/
void c_InStream::OnBytesConsumed(const uint64_t Length)
{
	if (IsLengthIdentified())
		m_RemainingLength -= Length;

	// Make sure any segments that this segment is part of knows the number of
	// bytes that have been consumed from the input stream.
	if (m_p_Source != nullptr)
		m_p_Source->OnBytesConsumed(Length);
}

/*===========================================================================*/


}  // n_Generic
