#pragma once

#include "DataElementTag.h"
#include "ValueRepresentation.h"

namespace n_DICOM
{


/*****************************************************************************/
// s_DataElementHeader

struct s_DataElementHeader
{
	s_DataElementTag Tag;
	c_ValueRepresentation ValueRepresentation;
	uint32_t ValueLength = 0;
};

/*****************************************************************************/


}  // n_DICOM
