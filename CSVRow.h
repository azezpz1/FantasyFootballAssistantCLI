#pragma once
#include <vector>
#include <string>
#include <map>

class CSVRow
{
public:
	CSVRow(std::vector<std::string> ColumnNames, std::string line);
	std::map<std::string, std::string> elements;
	
private:
	std::map<std::string, std::string> ConvertStringToMap(std::string& line, std::vector<std::string> ColumnNames);
};

