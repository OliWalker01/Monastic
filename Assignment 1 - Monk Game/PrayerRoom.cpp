#include "pch.h"
#include "PrayerRoom.h"
#include "GameController.h"

// Constructor
PrayerRoom::PrayerRoom()
{

}

// Deconstructor
PrayerRoom::~PrayerRoom()
{

}

// Heal Player
void PrayerRoom::HealPlayer()
{
	GameController gameController;

    system("color 01");

	timer = 15;

	do
	{
		system("cls");

		cout << R"(
=================================================================================================
 _____    _____           __    __   _____    _____      _____    ______    ______    ___    ___
|  _  |  |  ___|   /\     \ \  / /  |  ___|  | ____|    |  ___|  |  __  |  |  __  |  |   \  /   |
| |_| |  | |      /  \     \ \/ /   | |__    | |        | |      | |  | |  | |  | |  | |\ \/ /| |
|  ___|  | |     / /\ \     \  /    |  __|   | |        | |      | |  | |  | |  | |  | | \  / | |
| |      | |    / /==\ \    / /     | |___   | |        | |      | |__| |  | |__| |  | |  \/  | |
|_|      |_|   /_/    \_\  /_/      |_____|  |_|        |_|      |______|  |______|  |_|      |_|

=================================================================================================
                                     
                                                _|_
                                                 | 
                                                 |
                                                / \
                                               //_\\
                                              //(_)\\
                                               |/^\|
                                               ||_||
                                               // \\
                                              //   \\
                                             // === \\
                                            // =-=-= \\
                                           //   ===   \\
                                          //|         |\\
                                            |         |
                                            |  __ __  |
                                            | |  |  | |
                                            | | -|- | |
                                            |_|__|__|_|
                                          /`  =======  `\
                                        /`    =======    `\)" << endl << endl << endl; 

		cout << "Wait While Monk Prays and Restores it's Health!" << endl << endl;

		cout << "Time Remaining: " << timer << endl << endl;

		Sleep(1000);
		timer--;
	} while (timer >= 0);

	gameController.setMonkHealth(gameController.getMonkMaxHealth());

	cout << "Monk Healed!" << endl << endl;

	cout << "Monk Health: " << gameController.getMonkHealth() << endl;
	cout << "Monk Attack Points: " << gameController.getMonkAttackPoints() << endl << endl;

	system("pause");

    gameController.setHealsLeft(gameController.getHealsLeft() - 1);
    gameController.setCanHeal(false);
    gameController.openCorridor();
}