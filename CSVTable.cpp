#include <sstream>
#include "CSVTable.h"
#include "CSVRow.h"

std::vector<CSVRow> rows;

CSVTable::CSVTable(std::ifstream &CSVFileStream)
{
	std::string name_line;
	std::getline(CSVFileStream, name_line);

	std::vector<std::string> ColumnNames = ConvertColumnNamesStringToVector(name_line);

	std::string line;
	while (std::getline(CSVFileStream, line))
	{
		CSVRow row = CSVRow::CSVRow(ColumnNames, line);
		rows.push_back(row);
	}
}

std::vector<std::string> CSVTable::ConvertColumnNamesStringToVector(std::string column_name_line)
{
	std::stringstream stream(column_name_line);
	std::string single_element;

	std::vector<std::string> elements;
	while (std::getline(stream, single_element, ','))
	{
		elements.push_back(single_element);
	}

	return elements;
}