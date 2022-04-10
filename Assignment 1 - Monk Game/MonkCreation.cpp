#include "pch.h"
#include "MonkCreation.h"
#include "GameController.h"

// Constructor
MonkCreation::MonkCreation()
{
	
}

// Deconstructor
MonkCreation::~MonkCreation()
{

}

// Allows the Player to Create a Monk
void MonkCreation::createMonk()
{
	GameController gameController;

	system("cls");

	system("color 06");

	cout << R"(
==========================================================================================================
 _____    _____    _____              _______    _____      ___    ___    _______    ___     _    _   _
|  ___|	 |  ___|  |  ___|      /\    |__   __|  |  ___|    |   \  /   |  |  ___  |  |   \   | |  | | / /
| |      | |      | |__       /  \      | |     | |__      | |\ \/ /| |  | |   | |  | |\ \  | |  | |/ /
| |      | |      |  __|     / /\ \     | |     |  __|     | | \  / | |  | |   | |  | | \ \ | |  |   
| |___   | |      | |___    / /==\ \    | |     | |___     | |  \/  | |  | |___| |  | |  \ \| |  | |\ \
|_____|  |_|      |_____|  /_/    \_\   |_|     |_____|    |_|      |_|  |_______|  |_|   \___|  |_| \_\

==========================================================================================================)" << endl << endl;

	// Asks Player to Name Monk
	cout << "Enter Monk Name: ";
	cin >> monkName;

	getline(cin, blank);

	// Asks Player to describe the Monk
	cout << "Enter a Short Description of your Monk: ";
	getline(cin, monkDescription);

	// Assigns Monks Name and Description
	gameController.setMonkName(&monkName);
	gameController.setMonkDesc(&monkDescription);

	// Prints out the Monks Information
	cout << "\n\nMonk Name: " << gameController.getMonkName().c_str() << endl;
	cout << "Monk Description: " << gameController.getMonkDesc().c_str() << endl << endl;

	// Asks Player to Confirm this Information
	confirmDetails();

	// Asks Player for the Difficulty They Want to Play on
	setDifficulty();

	// Start Game
	gameController.openCorridor();
}

// Asks Player to Confirm Monk Details
void MonkCreation::confirmDetails()
{
	cout << "Please Confirm These Details (Y/N): ";
	cin >> confirm;

	// If 'Y' or 'y' is entered then details are confirmed
	if (confirm == 'Y' || confirm == 'y')
	{
		cout << "\nDetails Confirmed!" << endl << endl;
	}
	// If 'N' or 'n' is entered it asks the player to input the details again
	else if (confirm == 'N' || confirm == 'n')
	{
		createMonk();
	} 
	else
	{
		cout << "\nInvalid Entry!" << endl;
		confirmDetails();
	}
}

// Allows the Player to Select the Difficulty
void MonkCreation::setDifficulty()
{
	GameController gameController;

	cout << "----------------------------" << endl;
	cout << " Difficulty Level Selection" << endl;
	cout << "----------------------------" << endl << endl;

	cout << "1. Easy  2. Medium  3. Hard" << endl << endl;

	// Asks player to choose a difficulty
	cout << "Enter your selection (1, 2 or 3): ";
	cin >> difficulty;

	// Assigns Goblin's and Player's Stats Depending on Difficulty Chosen
	gameController.setDifficulty(difficulty);
	
	cout << "\nDifficulty Mode " << gameController.getDifficulty() << " selected." << endl << endl;

	// Prints out the Goblin's Stats
	cout << "Monster's Health: " << gameController.getGoblinMaxHealth() << endl;
	cout << "Monster Hit Points: " << gameController.getGoblinAttackPoints() << endl << endl;

	// Prints out the Monk's Stats
	cout << "Monk Max Health: " << gameController.getMonkHealth() << endl;
	cout << "Monk Attack Points: " << gameController.getMonkAttackPoints() << endl << endl;

	system("pause");
}