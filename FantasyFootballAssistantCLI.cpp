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
	cin >> file_path;
	ifstream CSVFileStream;
	CSVFileStream.open(file_path);
	CSVTable csv(CSVFileStream);
	cout << "File loaded." << endl;
	cout << endl;

	vector<string> picked_positions;
	bool exit_requested = false;
	string user_request;
	while (!exit_requested)
	{
		cout << "Type the name of the player someone else has picked, 'myturn' if you want a suggestion and 'exit' if you're done." << endl;
		cin >> user_request;
		
		if (user_request == "myturn")
		{
			SuggestAPlayer(csv, picked_positions);
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

void SuggestAPlayer(CSVTable& csv, vector<string>& picked_positions)
{

}

void LogAPick(CSVTable& csv, string input)
{
	int count = 0;
	for (CSVRow row : csv.rows)
	{
		string player_name = row.elements["Name"];
		if (player_name == input)
		{
			csv.rows.erase(csv.rows.begin() + count);
		}
		else
		{
			count++;
		}
	}
}
