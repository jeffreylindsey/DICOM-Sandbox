#pragma once

#include <string>  // std::string
#include <string_view>  // std::string_view

namespace n_DICOM
{


/*===========================================================================*/
constexpr uint16_t MakeVRValue(const char Chars[2])
{
	return Chars[0] + (static_cast<uint16_t>(Chars[1]) << 8);
}

/*****************************************************************************/
// c_ValueRepresentation

class c_ValueRepresentation
{
	//--- Public Types --------------------------------------------------------
	public:
		enum ValueRepresentationEnum : uint16_t
			{ VR_AE = MakeVRValue("AE")  // Application Entity
			, VR_AS = MakeVRValue("AS")  // Age String
			, VR_AT = MakeVRValue("AT")  // Attribute Tag
			, VR_CS = MakeVRValue("CS")  // Code String
			, VR_DA = MakeVRValue("DA")  // Date
			, VR_DS = MakeVRValue("DS")  // Decimal String
			, VR_DT = MakeVRValue("DT")  // Date Time
			, VR_FL = MakeVRValue("FL")  // Floating Point Single
			, VR_FD = MakeVRValue("FD")  // Floating Point Double
			, VR_IS = MakeVRValue("IS")  // Integer String
			, VR_LO = MakeVRValue("LO")  // Long String
			, VR_LT = MakeVRValue("LT")  // Long Text
			, VR_OB = MakeVRValue("OB")  // Other Byte
			, VR_OD = MakeVRValue("OD")  // Other Double
			, VR_OF = MakeVRValue("OF")  // Other Float
			, VR_OL = MakeVRValue("OL")  // Other Long
			, VR_OV = MakeVRValue("OV")  // Other 64-bit Very Long
			, VR_OW = MakeVRValue("OW")  // Other Word
			, VR_PN = MakeVRValue("PN")  // Person Name
			, VR_SH = MakeVRValue("SH")  // Short String
			, VR_SL = MakeVRValue("SL")  // Signed Long
			, VR_SQ = MakeVRValue("SQ")  // Sequence of Items
			, VR_SS = MakeVRValue("SS")  // Signed Short
			, VR_ST = MakeVRValue("ST")  // Short Text
			, VR_SV = MakeVRValue("SV")  // Signed 64-bit Very Long
			, VR_TM = MakeVRValue("TM")  // Time
			, VR_UC = MakeVRValue("UC")  // Unlimited Characters
			, VR_UI = MakeVRValue("UI")  // Unique Identifier (UID)
			, VR_UL = MakeVRValue("UL")  // Unsigned Long
			, VR_UN = MakeVRValue("UN")  // Unknown
			, VR_UR = MakeVRValue("UR")  // URI/URL
			, VR_US = MakeVRValue("US")  // Unsigned Short
			, VR_UT = MakeVRValue("UT")  // Unlimited Text
			, VR_UV = MakeVRValue("UV")  // Unsigned 64-bit Very Long
			};

	//--- Public Methods ------------------------------------------------------
	public:
		c_ValueRepresentation() = default;
		c_ValueRepresentation(const ValueRepresentationEnum ValueRepresentation);

		operator char*();
		operator std::string_view() const;
		operator ValueRepresentationEnum() const;

		std::string Name() const;
		bool HasReservedBytes() const;
		bool IsValueCharacters() const;

	//--- Private Members -----------------------------------------------------
	private:
		union
		{
			uint16_t AsInt = 0;
			char AsChars[2];
		} m_Value;
};


/*****************************************************************************/


}  // n_DICOM
