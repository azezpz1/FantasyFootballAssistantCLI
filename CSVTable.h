#pragma once

#include <fstream>
#include <string>
#include <vector>
#include "CSVRow.h"

class CSVTable
{
public:
	CSVTable(std::ifstream &CSVFileStream);
	std::vector<CSVRow> rows;

private:
	std::vector<std::string> ConvertColumnNamesStringToVector(std::string);
};

