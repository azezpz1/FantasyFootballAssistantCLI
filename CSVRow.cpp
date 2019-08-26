#include <sstream>
#include "CSVRow.h"

CSVRow::CSVRow(std::vector<std::string> ColumnNames, std::string line)
{
	int row_length = ColumnNames.size();
	elements = ConvertStringToVector(line);

}

std::vector<std::string> CSVRow::ConvertStringToVector(std::string& line)
{
	std::stringstream stream(line);
	std::string elem;
	std::vector<std::string> elements;
	while (std::getline(stream, elem, ','))
	{
		elements.push_back(elem);
	}

	return elements;
}
