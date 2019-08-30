// FantasyFootballAssistantCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "FantasyFootballAssistantCLI.h"
#include "CSVTable.h"
#include "CSVRow.h"

using namespace std;

int main()
{
	string file_path;
	
	cout << "Provide the path to the beersheets csv file: ";
	getline(cin, file_path);
	ifstream CSVFileStream;
	CSVFileStream.open(file_path);
	CSVTable csv(CSVFileStream);
	cout << "File loaded." << endl;
	cout << endl;

	//position, count
	map<string, size_t> picked_positions = { {"QB", 0}, {"WR", 0}, {"RB", 0}, {"TE", 0}, {"K", 0}, {"DEF", 0 } };
	map<string, size_t> desired_positions = { {"QB", 2}, {"WR", 5}, {"RB", 4}, {"TE", 2}, {"K", 1}, {"DEF", 1 } };
	
	bool exit_requested = false;
	string user_request;
	while (!exit_requested)
	{
		cout << "Type the name of the player someone else has picked, 'myturn' if you want a suggestion and 'exit' if you're done." << endl;
		getline(cin, user_request);
		
		if (user_request == "myturn")
		{
			SuggestAPlayer(csv, picked_positions, desired_positions);
		}

		else if (user_request == "exit")
		{
			exit_requested = true;
		}

		else
		{
			LogAPick(csv, user_request);
		}

	}

}

void SuggestAPlayer(CSVTable& csv, map<string, size_t>& picked_positions, map<string, size_t>& desired_positions)
{
	double highest_value = 0.0;
	string best_player;
	string best_position;

	for (CSVRow row : csv.rows)
	{
		if (stod(row.elements["Mean Value"]) > highest_value)
		{
			// this is the best player we've seen so far
			if (desired_positions[row.elements["Position"]] > 0)
			{
				// and it's in a position we need
				best_player = row.elements["Name"];
				best_position = row.elements["Position"];
			}
		}
	}

	cout << "You should pick: " << best_player << " (" << best_player << ")" <<endl;
	picked_positions[best_position]++;
	desired_positions[best_position]--;
}

void LogAPick(CSVTable& csv, string input)
{
	int count = 0;
	bool player_found = false;
	vector<CSVRow> original_rows = csv.rows;
	vector<CSVRow> editable_rows = csv.rows;
	for (CSVRow row : original_rows)
	{
		if (!player_found)
		{
			string player_name = row.elements["Name"];
			if (player_name == input)
			{
				editable_rows.erase(csv.rows.begin() + count);
				player_found = true;
			}
			else
			{
				count++;
			}
		}
	}
	csv.rows = editable_rows;
}
