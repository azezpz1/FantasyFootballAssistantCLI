#pragma once
#include <vector>
#include <string>
#include <map>

class CSVRow
{
public:
	CSVRow(std::vector<std::string> ColumnNames, std::string line);
	
private:
	std::map<std::string, std::string> elements;
	std::map<std::string, std::string> ConvertStringToMap(std::string& line, std::vector<std::string> ColumnNames);
};

