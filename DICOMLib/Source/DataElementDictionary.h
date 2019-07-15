#pragma once

#include "DataElementTag.h"

#include <map>  // std::map

namespace n_DICOM
{


/*****************************************************************************/
// s_DataElementDefinition

struct s_DataElementDefinition
{
	s_DataElementTag Tag;
	std::string Name;
};

/*****************************************************************************/

extern const std::map<s_DataElementTag, s_DataElementDefinition>
	DataElementDictionary;


}  // n_DICOM
