#include "CSVTable.h"
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