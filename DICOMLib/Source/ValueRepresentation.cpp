#include "ValueRepresentation.h"

namespace n_DICOM
{


/*****************************************************************************/
// c_ValueRepresentation

/*===========================================================================*/
c_ValueRepresentation::c_ValueRepresentation
( const ValueRepresentationEnum ValueRepresentation
)
	: m_Value{ValueRepresentation}
{
}

/*===========================================================================*/
c_ValueRepresentation::operator char*()
{
	return m_Value.AsChars;
}

/*===========================================================================*/
c_ValueRepresentation::operator std::string_view() const
{
	return std::string_view(m_Value.AsChars, sizeof(m_Value.AsChars));
}

/*===========================================================================*/
c_ValueRepresentation::operator ValueRepresentationEnum() const
{
	return static_cast<ValueRepresentationEnum>(m_Value.AsInt);
}

/*===========================================================================*/
std::string c_ValueRepresentation::Name() const
{
	switch (m_Value.AsInt)
	{
		case VR_AE:
		return "Application Entity";

		case VR_AS:
		return "Age String";

		case VR_AT:
		return "Attribute Tag";

		case VR_CS:
		return "Code String";

		case VR_DA:
		return "Date";

		case VR_DS:
		return "Decimal String";

		case VR_DT:
		return "Date Time";

		case VR_FL:
		return "Floating Point Single";

		case VR_FD:
		return "Floating Point Double";

		case VR_IS:
		return "Integer String";

		case VR_LO:
		return "Long String";

		case VR_LT:
		return "Long Text";

		case VR_OB:
		return "Other Byte";

		case VR_OD:
		return "Other Double";

		case VR_OF:
		return "Other Float";

		case VR_OL:
		return "Other Long";

		case VR_OV:
		return "Other 64-bit Very Long";

		case VR_OW:
		return "Other Word";

		case VR_PN:
		return "Person Name";

		case VR_SH:
		return "Short String";

		case VR_SL:
		return "Signed Long";

		case VR_SQ:
		return "Sequence of Items";

		case VR_SS:
		return "Signed Short";

		case VR_ST:
		return "Short Text";

		case VR_SV:
		return "Signed 64-bit Very Long";

		case VR_TM:
		return "Time";

		case VR_UC:
		return "Unlimited Characters";

		case VR_UI:
		return "Unique Identifier (UID)";

		case VR_UL:
		return "Unsigned Long";

		case VR_UN:
		return "Unknown";

		case VR_UR:
		return "URI/URL";

		case VR_US:
		return "Unsigned Short";

		case VR_UT:
		return "Unlimited Text";

		case VR_UV:
		return "Unsigned 64-bit Very Long";

		default:
		return "(unknown)";
	}
}

/*=============================================================================
	Returns true only if the 16 bits following the given two byte VR Field are
	reserved for use by later versions of the DICOM Standard.
-----------------------------------------------------------------------------*/
bool c_ValueRepresentation::HasReservedBytes() const
{
	switch (m_Value.AsInt)
	{
		case VR_OB:
		case VR_OD:
		case VR_OF:
		case VR_OL:
		case VR_OV:
		case VR_OW:
		case VR_SQ:
		case VR_SV:
		case VR_UC:
		case VR_UN:
		case VR_UR:
		case VR_UT:
		case VR_UV:
		return true;

		default:
		return false;
	}
}

/*===========================================================================*/
bool c_ValueRepresentation::IsValueCharacters() const
{
	switch (m_Value.AsInt)
	{
		case VR_AE:
		case VR_AS:
		case VR_CS:
		case VR_DA:
		case VR_DS:
		case VR_DT:
		case VR_IS:
		case VR_LO:
		case VR_LT:
		case VR_PN:
		case VR_SH:
		case VR_ST:
		case VR_TM:
		case VR_UC:
		case VR_UI:
		case VR_UR:
		case VR_UT:
		return true;

		default:
		return false;
	}
}

/*===========================================================================*/


}  // n_DICOM
