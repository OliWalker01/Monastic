#include "pch.h"
#include "MainMenu.h"
#include "HelpMenu.h"
#include "MonkCreation.h"

HelpMenu helpMenu;
MonkCreation monkCreation;

// Constructor
MainMenu::MainMenu()
{

}

// Deconstructor
MainMenu::~MainMenu()
{

}

// Prints all the Main Menu
void MainMenu::printMainMenu()
{
	system("cls");

	system("color 0F");

	cout << R"(
===========================================================================================
 ___    ___                _    ___     _      ___    ___    _____    ___     _    _     _
|   \  /   |      /\      | |  |   \   | |    |   \  /   |  |  ___|  |   \   | |  | |   | |
| |\ \/ /| |     /  \     | |  | |\ \  | |    | |\ \/ /| |  | |__    | |\ \  | |  | |   | |
| | \  / | |    / /\ \    | |  | | \ \ | |    | | \  / | |  |  __|   | | \ \ | |  | |   | |
| |  \/  | |   / /==\ \   | |  | |  \ \| |    | |  \/  | |  | |___   | |  \ \| |  | |___| |
|_|      |_|  /_/    \_\  |_|  |_|   \___|    |_|      |_|  |_____|  |_|   \___|  |_______|

===========================================================================================
)" << endl << endl;

	cout << R"(             
					     _,._      
				 .||,       /_ _\\     
				\.`',/      |'L'| |    
				= ,. =      | -,| L    
				/ || \    ,-'\"/,'`.   
				  ||     ,'   `,,. `.  
				  ,|____,' , ,;' \| |  
				 (3|\    _/|/'   _| |  
				  ||/,-''  | >-'' _,\\ 
				  ||'      ==\ ,-'  ,' 
				  ||       |  V \ ,|   
				  ||       |    |` |   
				  ||       |    |   \  
				  ||       |    \    \ 
				  ||       |     |    \
				  ||       |      \_,-'
				  ||       |___,,--")_\
				  ||         |_|   ccc/
				  ||        ccc/       
				  ||                   )" << endl << endl << endl << endl;

	// Asks Player for Menu Option Selection
	cout << "1. Play Game            2. Help            3.Scoreboard            4. Exit" << endl << endl;

	MenuOptions();
}

// Prints the Menu Options
void MainMenu::MenuOptions()
{
	cout << "Input Option: ";

	cin >> menuOption;

	switch (menuOption)
	{
	case(1):
		// Starts Game
		monkCreation.createMonk();
		break;
	case(2):
		// Help Menu
		helpMenu.printHelpMenu();
		break;
	case(3):
		// Scoreboard
		printScoreboard();
		break;
	case(4):
		// Quits Game
		exit(0);
		break;
	default:
		cout << "\nInvalid Option!" << endl << endl;
		MenuOptions();
		break;
	}
}

// Prints the Scoreboard
void MainMenu::printScoreboard()
{
	system("cls");

	string line;
	ifstream scoreFile("Scores.txt");

	if (scoreFile.is_open())
	{
		while (getline(scoreFile, line))
		{
			cout << line << endl;
		}
		cout << "\n";
		scoreFile.close();
	}

	else { cout << "Unable to Open File!" << endl; }

	system("Pause");

	printMainMenu();
}