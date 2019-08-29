// FantasyFootballAssistantCLI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "CSVTable.h"

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
	bool exit_requested = false;
	string user_request;
	while (!exit_requested)
	{
		cout << "Type the name of the player someone else has picked, 'myturn' if you want a suggestion and 'exit' if you're done." << endl;
		cin >> user_request;
		
		if (user_request == "myturn")
		{
			SuggestAPlayer(csv);
		}

		else if (user_request == "exit")
		{
			exit_requested = true;
		}

		else
		{
			LogAPick(csv);
		}

	}



}
