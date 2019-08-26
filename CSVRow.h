#pragma once
#include <vector>
#include <string>

class CSVRow
{
public:
	CSVRow(std::vector<std::string> ColumnNames, std::string line);
	
private:
	std::vector<std::string> elements;
};

