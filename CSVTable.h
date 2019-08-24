#pragma once

#include <fstream>
#include <string>
#include "CSVRow.h"
#include "CSVColumn.h"

class CSVTable
{
public:
	CSVTable(std::ifstream CSVFileStream);
	std::string GetElement(int column_id, int row_id );
	CSVRow GetRow(int row_id);
	CSVColumn GetColumn(int column_id);

};

