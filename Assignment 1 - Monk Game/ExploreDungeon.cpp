#include "pch.h"
#include "ExploreDungeon.h"
#include "GameController.h"
#include "FightMonster.h"
#include "MainMenu.h"

// Constructor
ExploreDungeon::ExploreDungeon()
{

}

//Deconstructor
ExploreDungeon::~ExploreDungeon()
{

}

// Allows Player to Explore the Dungeon
void ExploreDungeon::Corridor()
{
    GameController gameController;

	system("cls");

    system("color 03");

	cout << R"(
===============================================================
 _____              _____    _        ______    _____    _____
|  ___|  __    __  |  _  |  | |      |  __  |  |  ___|  |  ___|
| |__    \ \  / /  | |_| |  | |      | |  | |  | |      | |__
|  __|    \ \/ /   |  ___|  | |      | |  | |  | |      |  __|
| |___    / /\ \   | |      | |___   | |__| |  | |      | |___
|_____|  /_/  \_\  |_|      |_____|  |______|  |_|      |_____|

===============================================================

                         \_______/
                     `.,-'\_____/`-.,'
                      /`..'\ _ /`.,'\
                     /  /`.,' `.,'\  \
                    /__/__/     \__\__\__
                    \  \  \     /  /  /
                     \  \,'`._,'`./  /
                      \,'`./___\,'`./
                     ,'`-./_____\,-'`.
                         /       \            )" << endl << endl << endl;

    cout << "===============================================================" << endl << endl;

    cout << "Stats" << endl << endl;

    cout << "Current Health: " << gameController.getMonkHealth() << endl;
    cout << "Current Attack Points: " << gameController.getMonkAttackPoints() << endl << endl;

    cout << "Current Points: " << gameController.getPoints() << endl << endl;

    cout << "===============================================================" << endl << endl;

    cout << "Where would you like to explore next?" << endl << endl;

    cout << "1. Monster Room" << endl;
    cout << "2. Upgrade Room (Upgrades Remaining: " << gameController.getUpgradesLeft() << ")" << endl;
    cout << "3. Empty Room (Heals Left: " << gameController.getHealsLeft() << ")" << endl;
    cout << "4. Treasure Room ";

    if (gameController.getPoints() < gameController.getPointsRequired())
    {
        cout << "(DOOR LOCKED " << gameController.getPoints() << "/" << gameController.getPointsRequired() << " Points Earnt)" << endl;
    }
    else
    {
        cout << "(DOOR UNLOCKED)" << endl;
    }

    cout << "5. Leave" << endl << endl;

    inputOption();
}

void ExploreDungeon::inputOption()
{
    GameController gameController;
    FightMonster fightMonster;
    MainMenu mainMenu;

    cout << "Input 1, 2, 3 or 4 to choose where to go: ";
    cin >> input;

    switch (input)
    {
    case(1):
        fightMonster.Fight();
        break;
    case(2):
        if (gameController.getUpgradesLeft() > 0) 
        {
            if (gameController.getCanUpgrade() == true) { gameController.openUpgradeRoom(); }
            else
            {
                cout << "\nYou Can Only Perform an Upgrade Once a Fight Has Been Completed! Try Again!" << endl << endl;
                inputOption();
            }
        }
        else
        {
            cout << "\nNo Upgrades Left! Try Another Option!" << endl << endl;
            inputOption();
        }
        break;
    case(3):
        if (gameController.getHealsLeft() > 0)
        { 
            if (gameController.getCanHeal() == true){ gameController.openPrayerRoom(); }
            else
            {
                cout << "\nYou Can Only Heal Once a Fight Has Been Completed! Try Again!" << endl << endl;
                inputOption();
            }
            
        }
        else
        {
            cout << "\nNo Heals Left! Try Another Option!" << endl << endl;
            inputOption();
        }
        break;
    case(4):
        if (gameController.getPoints() > gameController.getPointsRequired()) { gameController.openTreasureRoom(); }
        else
        {
            cout << "\nYou Must Earn At Least " << gameController.getPointsRequired() << " Points to Unlock the Treasure Room." << endl;
            cout << "Try Another Option!" << endl << endl;
            inputOption();
        }
    case(5):
        system("cls");

        cout << "Are You Sure You Want To Quit?" << endl << endl;

        cout << "1. Yes       2. No" << endl << endl;

        confirmationInput();

        break;
    default:
        cout << "Invalid Entry! Entry of 1-5 Must Be Entered. Try Again!" << endl << endl;
        inputOption();
        break;
    }
}

void ExploreDungeon::confirmationInput()
{
    MainMenu mainMenu;

    cout << "Input: ";
    cin >> confirmation;

    switch (confirmation)
    {
    case(1):
        mainMenu.printMainMenu();
        break;
    case(2):
        Corridor();
        break;
    default:
        cout << "Invalid Entry! Try Again!" << endl << endl;
        confirmationInput();
        break;
    }
}