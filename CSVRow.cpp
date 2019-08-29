#include <sstream>
#include "CSVRow.h"

std::map<std::string, std::string> elements;

CSVRow::CSVRow(std::vector<std::string> ColumnNames, std::string line)
{
	int row_length = ColumnNames.size();
	elements = ConvertStringToMap(line, ColumnNames);

}

std::map<std::string, std::string> CSVRow::ConvertStringToMap(std::string& line, std::vector<std::string> ColumnNames)
{
	std::stringstream stream(line);
	std::string elem;

	//Temporary elements is a vector of strings that will be used later for us to create our map
	std::vector<std::string> temp_elements;
	while (std::getline(stream, elem, ','))
	{
		temp_elements.push_back(elem);
	}

	std::map<std::string, std::string> local_map_elements;

	if (temp_elements.size() != ColumnNames.size())
	{
		std::stringstream stream;
		stream << "The number of ColumnNames (" << ColumnNames.size() << ") Does not match the number of elements in the string (" << temp_elements.size() << ")";
		throw stream.str();
	}
	else
	{
		for (unsigned int i = 0; i < temp_elements.size(); i++)
		{
			local_map_elements.emplace(ColumnNames[i], temp_elements[i]);
		}
	}

	return local_map_elements;
}
