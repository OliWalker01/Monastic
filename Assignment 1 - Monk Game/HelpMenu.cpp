#include "pch.h"
#include "MainMenu.h"
#include "HelpMenu.h"

// Constructor
HelpMenu::HelpMenu()
{

}

// Deconstructor
HelpMenu::~HelpMenu()
{

}

// Prints the Help Menu
void HelpMenu::printHelpMenu()
{
	MainMenu mainMenu;

	system("cls");

	cout << R"(
==================================================================================
 _    _    _____    _       _____     ___    ___    _____    ___     _    _     _
| |  | |  |  ___|  | |     |  _  |   |   \  /   |  |  ___|  |   \   | |  | |   | |
| |__| |  | |__    | |     | |_| |   | |\ \/ /| |  | |__    | |\ \  | |  | |   | |
|  __  |  |  __|   | |     |  ___|   | | \  / | |  |  __|   | | \ \ | |  | |   | |
| |  | |  | |___   | |__   | |       | |  \/  | |  | |___   | |  \ \| |  | |___| |
|_|  |_|  |_____|  |____|  |_|       |_|      |_|  |_____|  |_|   \___|  |_______|

==================================================================================)" << endl << endl;

	cout << "Welcome to The Monk Game!" << endl << endl;

	cout << R"(The Monk Game is an RPG where you control a Monk.
You as the Player must explore a dungeon in order to
reach the tresure room.)" << endl << endl;

	cout << R"(Randomly generated dungeons will be spawned and you
must fight off monsters that live within them.)" << endl << endl;

	cout << R"(On you travels you will come across an empty room. In
this room you will be able to heal your Monks Health.)" << endl << endl;

	cout << R"(Within the upgrade room you will be able to upgrade
the monks abilites. You will have to choose between
increasing your health by 5 or increasing the amount
of damage the Monk can deal by 2.)" << endl << endl;

	cout << R"(In the Monster Room you must fight! Using a turn-based
combat mode you as the player must choose between two
actions to perform. Attack the Monster or Heal one
health point.)" << endl << endl;

	cout << "The game is won when you reach the tresure room!" << endl << endl;

	cout << "Good Luck!" << endl << endl;

	cout << "To Return to the Main Menu Enter 1: ";
	cin >> helpOption;

	if (helpOption == 1)
	{
		mainMenu.printMainMenu();
	}
	else
	{
		do
		{
			cout << "\nError! Invalid Input. Enter 1 to return to the Main Menu: ";
			cin >> helpOption;
		} while (helpOption != 1);

		mainMenu.printMainMenu();
	}
}