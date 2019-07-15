#pragma once

#include <sstream>  // std::stringstream
#include <string>  // std::string

namespace n_Generic
{


/*===========================================================================*/
template<typename t_Value>
std::string ToString(const t_Value& Value)
{
	std::stringstream StringStream;

	StringStream << Value;

	return StringStream.str();
}

/*****************************************************************************/


}  // n_Generic
