#pragma once
#include <map>
#include <string>
#include <vector>
#include "CSVTable.h"

void SuggestAPlayer(CSVTable& csv, std::map<std::string, size_t>& picked_positions, std::map<std::string, size_t>& desired_positions);
void LogAPick(CSVTable& csv, std::string user_request);
