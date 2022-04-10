#include "pch.h"
#include "UpgradeRoom.h"
#include "GameController.h"

GameController gameController;

// Constructor
UpgradeRoom::UpgradeRoom()
{

}

// Deconstructor
UpgradeRoom::~UpgradeRoom()
{

}

// Upgrades Monk Health
void UpgradeRoom::UpgradeHealth()
{
	gameController.setMonkMaxHealth(gameController.getMonkMaxHealth() + 5);
}

// Upgrades Monk Attack Points
void UpgradeRoom::UpgradeAttackPoints()
{
	gameController.setMonkAttackPoints(gameController.getMonkAttackPoints() + 2);
}

// Displays Upgrade Menu
void UpgradeRoom::PlayerUpgrades()
{
	system("cls");

	system("color 02");

	cout << R"(
======================================================================
 _     _    _____    _____    ____              _____     ______    _
| |   | |  |  _  |  |  _  |  |  __|    /\      |  __ \   |   ___|  | |
| |   | |  | |_| |  | |_| |  | |      /  \     | |  | |  |  |___   | |
| |   | |  |  ___|  |___  |  | |     / /\ \    | |  | |  |   ___|  |_|
| |___| |  | |       ___| |  | |    / /==\ \   | |__| |  |  |___    _
|_______|  |_|      |_____|  |_|   /_/    \_\  |_____/   |______|  |_| 

======================================================================

                                            .-.
                           {}               8@8
                         .::::.             888
                     @\\/W\/\/W\//@         8@8
                      \\/^\/\/^\//     _    )8(    _
                       \_O_{}_O_/     (@)__/8@8\__(@)
                  ____________________ `~"-=):(=-"~`
                 |<><><>  |  |  <><><>|     |.|
                 |<>      |  |      <>|     |S|
                 |<>      |  |      <>|     |'|
                 |<>   .--------.   <>|     |.|
                 |     |   ()   |     |     |P|
                 |_____| (O\/O) |_____|     |'|
                 |     \   /\   /     |     |.|
                 |------\  \/  /------|     |U|
                 |       '.__.'       |     |'|
                 |        |  |        |     |.|
                 :        |  |        :     |N|
                  \       |  |       /      |'|
                   \<>    |  |    <>/       |.|
                    \<>   |  |   <>/        |K|
                     `\<> |  | <>/'         |'|
                       `-.|__|.-`           \ /
                                             ^)" << endl << endl << endl;

	cout << "It's time to Upgrade!" << endl << endl;

	cout << "1. Health +5		2. Attack Points +2" << endl << endl;

	InputOption();
}

// Allows Player to Select Option to Upgrade
void UpgradeRoom::InputOption()
{
	cout << "Enter 1 to Upgrade Health or 2 to Upgrade Attack Points: ";
	
	cin >> option;

	switch (option)
	{
	case(1):
		UpgradeHealth();

		cout << "\nMonk Max Health: " << gameController.getMonkMaxHealth() << endl;
		cout << "Monk Attack Point: " << gameController.getMonkAttackPoints() << endl << endl;

		system("pause");

		gameController.setUpgradesLeft(gameController.getUpgradesLeft() - 1);
		gameController.setCanUpgrade(false);
		gameController.openCorridor();
		break;
	case(2):
		UpgradeAttackPoints();

		cout << "\nMonk Max Health: " << gameController.getMonkMaxHealth() << endl;
		cout << "Monk Attack Point: " << gameController.getMonkAttackPoints() << endl << endl;

		system("pause");

		gameController.setUpgradesLeft(gameController.getUpgradesLeft() - 1);
		gameController.setCanUpgrade(false);
		gameController.openCorridor();
		break;
	default:
		cout << "\nInput Not Valid! Try Again!" << endl << endl;
		InputOption();
		break;
	}
}