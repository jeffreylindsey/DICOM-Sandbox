#pragma once

#include <cstdint>  // UINT64_MAX
#include <istream>  // std::istream

namespace n_Generic
{


/******************************************************************************
// c_InStream

Encapsulates an input (binary) data stream for easy reading.  This is designed
for a single pass, meaning once the data is read, it cannot be read again
unless you start over.

This class can also be used to isolates a specific length of an existing input
stream.  This restricts reading to the length (in bytes) that is given on
construction, and will skip any unread data up to that length upon destruction.

This class assumes no data will be consumed from the given input stream
outside of this object for the lifetime of this object.  Otherwise this object
won't know how many bytes have been read.
-----------------------------------------------------------------------------*/
class c_InStream
{
	//--- Public Static Members -----------------------------------------------
	public:
		static const uint64_t UnidentifiedLength = UINT64_MAX;

	//--- Public Methods ------------------------------------------------------
	public:
		c_InStream(std::istream& r_Stream);
		c_InStream(c_InStream& r_InStream, const uint64_t Length);
		~c_InStream();

		bool EncounteredError() const;
		bool IsAtEnd() const;
		bool IsLengthIdentified() const;

		uint64_t RemainingLength() const;

		void Skip(const uint64_t Length);

		void Read(void* p_Buffer, const uint64_t Length);

		template<typename t_Value>
		void ReadRaw(t_Value& r_Value);

	//--- Private Methods -----------------------------------------------------
	private:
		void OnBytesConsumed(const uint64_t Length);

	//--- Private Members -----------------------------------------------------
	private:
		std::istream& m_r_Stream;

		c_InStream* m_p_Source = nullptr;

		uint64_t m_RemainingLength = UnidentifiedLength;

		bool m_Error = false;
};

/*=============================================================================
	Reads a number of bytes equal to the size of the given value object from
	the input stream directly into the given value object.
-----------------------------------------------------------------------------*/
template<typename t_Value>
void c_InStream::ReadRaw(t_Value& r_Value)
{
	Read(&r_Value, sizeof(r_Value));
}

/*****************************************************************************/


}  // n_Generic
