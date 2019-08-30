#pragma once
#include <string>
#include <vector>
#include "CSVTable.h"

void SuggestAPlayer(CSVTable& csv, std::vector<std::string> & picked_positions);
void LogAPick(CSVTable& csv, std::string user_request);
