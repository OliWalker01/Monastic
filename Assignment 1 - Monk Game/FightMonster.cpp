#include "pch.h"
#include "FightMonster.h"
#include "GameController.h"
#include "MainMenu.h"

// Constructor
FightMonster::FightMonster()
{

}

// Deconstructor
FightMonster::~FightMonster()
{

}

// Allows Player to Fight Goblin
void FightMonster::Fight()
{
	GameController gameController;

	halfOfHealth = gameController.getMonkMaxHealth() / 2;

	system("cls");

	system("color 04");

	cout << R"(
===============================================
 _____    _    _____    _    _    _______    _
|  ___|  | |  |  _  |  | |  | |  |__   __|  | |
| |__    | |  | |_| |  | |__| |     | |     | |
|  __|   | |  |___  |  |  __  |     | |     |_|
| |      | |   ___| |  | |  | |     | |      _
|_|      |_|  |_____|  |_|  | |     |_|     |_|

===============================================


             ,    ,    /\   /\
            /( /\ )\  _\ \_/ /_
            |\_||_/| < \_   _/ >
            \______/  \|0   0|/
              _\/_   _(_  ^  _)_
             ( () ) /`\|V"""V|/`\
               {}   \  \_____/  /
               ()   /\   )=(   /\
               {}  /  \_/\=/\_/  \)" << endl << endl << endl;

	HeadsOrTails();

	// Fight runs until Monk or Monster Dies
	do
	{
		system("cls");

		system("color 04");

		if (hasGameStarted == false)
		{
			gameController.setGoblinHealth(gameController.getGoblinMaxHealth());

			hasGameStarted = true;
			gameOver = false;
			hitsTaken = 0;
		}

		cout << R"(
===============================================
 _____    _    _____    _    _    _______    _
|  ___|  | |  |  _  |  | |  | |  |__   __|  | |
| |__    | |  | |_| |  | |__| |     | |     | |
|  __|   | |  |___  |  |  __  |     | |     |_|
| |      | |   ___| |  | |  | |     | |      _
|_|      |_|  |_____|  |_|  | |     |_|     |_|

===============================================


             ,    ,    /\   /\
            /( /\ )\  _\ \_/ /_
            |\_||_/| < \_   _/ >
            \______/  \|0   0|/
              _\/_   _(_  ^  _)_
             ( () ) /`\|V"""V|/`\
               {}   \  \_____/  /
               ()   /\   )=(   /\
               {}  /  \_/\=/\_/  \)" << endl << endl << endl;

		if (playersTurn == true)
		{
			// Player's turn
			PlayerFight();
			playersTurn = false;

			if (gameController.getGoblinHealth() <= 0) 
			{
				gameOver = true;
				gameLostorWon();
			}
		}

		if (playersTurn == false)
		{
			// Goblin's Turn
			GoblinFight();
			playersTurn = true;

			// Checks to see if player can heal
			if (gameController.getMonkHealth() <= halfOfHealth) { canHeal = true; }
			else { canHeal = false; }

			// Checks if Players Has Died
			if (gameController.getMonkHealth() <= 0) 
			{ 
				gameOver = true; 
				gameLostorWon();
			}
		}

		system("pause");
	} while (gameOver == false);
}

void FightMonster::HeadsOrTails()
{
	GameController gameController;

	switch (gameController.getDifficulty())
	{
	case(1):
		playersTurn = true;
		break;
	case(2):
		cout << "Play Head or Tails to Decides Who Goes First!" << endl << endl;

		HeadsOrTailsInput();

		playerFirst = gameController.movePicker();

		cout << "\nIt was ";

		if (playerFirst == true)
		{
			cout << "Heads!" << endl << endl;
			coinSide = "heads";
		}
		else if (playerFirst == false)
		{
			cout << "Tails!" << endl << endl;
			coinSide = "tails";
		}

		Sleep(1000);

		if (coinSide == "heads")
		{
			if (headsOrTails == 'H' || headsOrTails == 'h')
			{ 
				playersTurn == true;
				cout << "Your Turn First!" << endl << endl;
			}
			else if (headsOrTails == 'T' || headsOrTails == 't')
			{ 
				playersTurn == false;
				cout << "Goblin's Turn First!" << endl << endl;
			}
		}
		else if (coinSide == "tails")
		{
			if (headsOrTails == 'H' || headsOrTails == 'h')
			{ 
				playersTurn == false;
				cout << "Goblin's Turn First!" << endl << endl;
			}
			else if (headsOrTails == 'T' || headsOrTails == 't')
			{ 
				playersTurn == true; 
				cout << "Your Turn First!" << endl << endl;
			}
		}

		system("pause");
		break;
	case(3):
		playersTurn = false;
		break;
	}
}

void FightMonster::HeadsOrTailsInput()
{
	cout << "Enter H for Heads or T for Tails: ";
	cin >> headsOrTails;

	if (headsOrTails == 'H' || headsOrTails == 'h' || headsOrTails == 'T' || headsOrTails == 't') { }
	else
	{
		cout << "Invalid Entry! Enter 'H', 'h', 'T' or 't'!" << endl << endl;
		HeadsOrTailsInput();
	}
}

void FightMonster::PlayerFight()
{
	GameController gameController;

	// Player can only heal if their health is less then 50%
	if (canHeal == true)
	{
		cout << "Your Turn to Fight!" << endl;
		cout << "1. Attack	2. Heal" << endl << endl;

		cout << "Input Option: ";
		cin >> fightOption;

		switch (fightOption)
		{
		case(1):
			if (gameController.movePicker() == true) 
			{ 
				cout << "Monster Was Hit!" << endl << endl;
				gameController.goblinTakeDamage(); 
			}
			else { cout << "Player's Move Missed!" << endl << endl; }
			break;
		case(2):
			if (gameController.movePicker() == true) 
			{ 
				cout << "Player Healed!" << endl << endl;
				gameController.setMonkHealth(gameController.getMonkHealth() + 1);
			}
			else { cout << "Player's Move Missed!" << endl << endl; }
			break;
		default:
			cout << "Invalid Input. Move Skipped!" << endl << endl;
		}
	}
	else
	{
		cout << "Your Turn to Fight!" << endl;
		cout << "1. Fight" << endl << endl;

		cout << "Input Option: ";
		cin >> fightOption;

		switch (fightOption)
		{
		case(1):
			if (gameController.movePicker() == true)
			{
				cout << "Monster Was Hit!" << endl << endl;
				gameController.goblinTakeDamage();
			}
			else { cout << "Move Missed!" << endl << endl; }
			break;
		default:
			cout << "Invalid Input. Move Skipped!" << endl << endl;
		}
	}

	Sleep(1000);
}

void FightMonster::GoblinFight()
{
	GameController gameController;

	// Monsters Go is Randomly Assigned
	if (gameController.movePicker() == true)
	{
		cout << "Player was Hit!" << endl << endl;
		gameController.goblinMovePicker();
		hitsTaken++;
	}
	else { cout << "Monster's Move Missed!" << endl << endl; }

	if (gameController.getMonkHealth() <= 0) { gameController.setMonkHealth(0); }
	if (gameController.getGoblinHealth() <= 0) { gameController.setGoblinHealth(0); }

	cout << "Monk Health: " << gameController.getMonkHealth() << endl;
	cout << "Monster Health: " << gameController.getGoblinHealth() << endl << endl;
}

void FightMonster::gameLostorWon()
{
	GameController gameController;

	if (gameController.getGoblinHealth() <= 0)
	{
		system("cls");

		cout << R"(
========================================
 _       _    _______    ___     _    _
| |  _  | |  |  ___  |  |   \   | |  | |
| | | | | |  | |   | |  | |\ \  | |  | |
| | | | | |  | |   | |  | | \ \ | |  |_|
| |_| |_| |  | |___| |  | |  \ \| |   _
|_________|  |_______|  |_|   \___|  |_|

========================================)" << endl << endl;

		gameController.setPoints(hitsTaken);

		cout << "Health Remaining: " << gameController.getMonkHealth() << endl;
		cout << "Hits Taken: " << hitsTaken << endl;

		switch (gameController.getDifficulty())
		{
		case(1):
			cout << "Difficulty Bonus: x0.5" << endl << endl;
			break;
		case(2):
			cout << "Difficulty Bonus: x1.0" << endl << endl;
			break;
		case(3):
			cout << "Difficulty Bonus: x1.5" << endl << endl;
			break;
		}

		cout << "Total Points: " << gameController.getPoints() << endl << endl;

		system("pause");

		hasGameStarted = false;

		gameController.setCanHeal(true);
		gameController.setCanUpgrade(true);
		gameController.openCorridor();
	}
	else
	{
		system("cls");

		cout << R"(
==========================================
 _       _______    _____    _______    _
| |     |  ___  |  |  ___|  |__   __|  | | 
| |     | |   | |  | |___      | |     | |
| |     | |   | |  |___  |     | |     |_|
| |___  | |___| |   ___| |     | |      _
|_____| |_______|  |_____|     |_|     |_|

==========================================)" << endl << endl;

		cout << "Total Points: " << gameController.getPoints() << endl << endl;

		cout << "1. Main Menu    2. Exit Game" << endl << endl;

		hasGameStarted = false;

		lostMenuInput();
	}
}

void FightMonster::lostMenuInput()
{
	GameController gameController;
	MainMenu mainMenu;

	cout << "Input 1 or 2: ";

	cin >> option;

	switch (option)
	{
	case(1):
		mainMenu.printMainMenu();
		break;
	case(2):
		exit(0);
		break;
	default:
		cout << "\nInavlid Input! Try Again!" << endl << endl;
		lostMenuInput();
	}
}