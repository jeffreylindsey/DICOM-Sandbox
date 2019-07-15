#include "Reader.h"

#include "DICOM/InStream.h"

#include <fstream>  // std::ifstream
#include <iostream>  // std::cout
#include <string>  // std::string

/*===========================================================================*/
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Usage: ConsoleReader.exe <file-name>\n";
		return 1;
	}

	const std::string FileName = argv[1];

	std::ifstream FileStream(FileName, std::ios::in | std::ios::binary);
	if (!FileStream)
	{
		std::cout << "Failed to open file " << FileName << "\n";
		return 1;
	}

	n_DICOM::c_InStream DICOMFileStream(FileStream);

	if (!DICOMFileStream.ReadFileHeader())
	{
		std::cout << "Not a valid DICOM file.\n";
		return 1;
	}

	c_Reader Reader;
	Reader.ReadAndDisplayDataSet(DICOMFileStream);

	return 0;
}

/*===========================================================================*/
