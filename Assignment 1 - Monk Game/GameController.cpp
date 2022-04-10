#include "pch.h"
#include "GameController.h"
#include "MonkDetails.h"
#include "GoblinDetails.h"
#include "MainMenu.h"
#include "FightMonster.h"
#include "PrayerRoom.h"
#include "UpgradeRoom.h"
#include "ExploreDungeon.h"
#include "TreasureRoom.h"

MonkDetails monkDetails;
GoblinDetails goblinDetails;
MainMenu mainMenu;
FightMonster fightMonster;
PrayerRoom prayerRoom;
UpgradeRoom upgradeRoom;
ExploreDungeon exploreDungeon;
TreasureRoom treasureRoom;

// Constructor
GameController::GameController()
{

}

// Deconstructor
GameController::~GameController()
{

}

// Get Monk's Name
string GameController::getMonkName()
{
	return monkDetails.getName();
}

// Set Monk's Name
void GameController::setMonkName(string * name)
{
	monkDetails.setName(*name);
}

// Get Monk's Description
string GameController::getMonkDesc()
{
	return monkDetails.getDesc();
}

// Set Monk's Description
void GameController::setMonkDesc(string* desc)
{
	monkDetails.setDesc(*desc);
}

// Get Monk's Health
int GameController::getMonkHealth()
{
	return monkDetails.getHealth();
}

// Set Monk's Health
void GameController::setMonkHealth(int health)
{
	return monkDetails.setHealth(health);
}

// Get Monk's Max Health
int GameController::getMonkMaxHealth()
{
	return monkDetails.getMaxHealth();
}

// Set Monk's Max Health
void GameController::setMonkMaxHealth(int maxHealth)
{
	monkDetails.setMaxHealth(maxHealth);
}

// Get Monk's Attack Points
int GameController::getMonkAttackPoints()
{
	return monkDetails.getAttackPoints();
}

// Set Monk's Attack Points
void GameController::setMonkAttackPoints(int attackPoints)
{
	monkDetails.setAttackPoints(attackPoints);
}

// Decrease Monks Health When Damage is Taken
void GameController::monkTakeDamage()
{
	monkDetails.takeDamage(getGoblinAttackPoints());
}

// Get the Number of Upgrades Player has Left
int GameController::getUpgradesLeft()
{
	return monkDetails.getUpgradesLeft();
}

// Set the Number of Upgrades Player has Left
void GameController::setUpgradesLeft(int upgradesLeft)
{
	monkDetails.setUpgradesLeft(upgradesLeft);
}

// Get the Number of Heals Player has left
int GameController::getHealsLeft()
{
	return monkDetails.getHealsLeft();
}

// Set the Number of Heals Player has left
void GameController::setHealsLeft(int healsLeft)
{
	monkDetails.setHealsLeft(healsLeft);
}

// Get Can Player Heal
bool GameController::getCanHeal()
{
	return monkDetails.getCanHeal();
}

// Set Can Player Heal
void GameController::setCanHeal(bool canHeal)
{
	monkDetails.setCanHeal(canHeal);
}

// Get Can Player Upgrade
bool GameController::getCanUpgrade()
{
	return monkDetails.getCanUpgrade();
}

// Set can Player Upgrade
void GameController::setCanUpgrade(bool canUpgrade)
{
	monkDetails.setCanUpgrade(canUpgrade);
}

// Get Points Required to Unlock Treasure Room
int GameController::getPointsRequired()
{
	return monkDetails.getPointsRequired();
}

// Set Points Required to Unlock Treasure Room
void GameController::setPointsRequired(int pointsRequired)
{
	monkDetails.setPointsRequired(pointsRequired);
}

// Get Goblin's Health
int GameController::getGoblinHealth()
{
	return goblinDetails.getHealth();
}

// Set Goblin's Health
void GameController::setGoblinHealth(int health)
{
	goblinDetails.setHealth(health);
}

// Get Goblin's Max Health
int GameController::getGoblinMaxHealth()
{
	return goblinDetails.getMaxHealth();
}

// Set Goblin's Max Health
void GameController::setGoblinMaxHealth(int maxHealth)
{
	goblinDetails.setMaxHealth(maxHealth);
}

// Get Goblin's Attack Points
int GameController::getGoblinAttackPoints()
{
	return goblinDetails.getAttackPoints();
}

// Set the Goblin's Attack Points
void GameController::setGoblinAttackPoints(int attackPoints)
{
	goblinDetails.setAttackPoints(attackPoints);
}

// Decrease Goblin's Health When Damage is Taken
void GameController::goblinTakeDamage()
{
	goblinDetails.takeDamage(getGoblinAttackPoints());
}

// Get Game Difficulty
int GameController::getDifficulty()
{
	return monkDetails.getDifficulty();
}

// Set Game Difficulty
void GameController::setDifficulty(int difficulty)
{
	switch (difficulty)
	{
	case(1):
		// Easy Mode
		setPointsRequired(750);
		setHealsLeft(4);
		setUpgradesLeft(4);
		break;

	case(2):
		//Medium Mode
		setPointsRequired(1000);
		setHealsLeft(3);
		setUpgradesLeft(3);
		break;

	case(3):
		// Hard Mode
		setPointsRequired(1500);
		setHealsLeft(2);
		setUpgradesLeft(2);
		break;
	}

	monkDetails.setHealth(15);
	monkDetails.setMaxHealth(15);
	monkDetails.setAttackPoints(3);
	monkDetails.setPoints(0);
	monkDetails.setDifficulty(difficulty);
}

// Picker for Move Landing or Not
bool GameController::movePicker()
{
	chance = rand() % 2 + 1;

	switch (chance)
	{
	case(1):
		return true;
		break;
	case(2):
		return false;
		break;
	}
}

// Random Move Picker for the Goblin
void GameController::goblinMovePicker()
{
	// Goblin can only heal if health is less then 50%
	if (getGoblinHealth() <= (getGoblinHealth() / 2))
	{
		chance = rand() % 4 + 1;

		if (chance == 1) { setGoblinHealth(getGoblinHealth() + 1); }
		else if (chance == 2, 3, 4) { monkTakeDamage(); }
	}
	else
	{
		monkTakeDamage();
	}
}

// Get Points Scored by Player
double GameController::getPoints()
{
	return monkDetails.getPoints();
}

// Set Points Scored by Player
void GameController::setPoints(int hitsTaken)
{
	monkDetails.setPoints(hitsTaken);
}

// Opens Main Menu
void GameController::openMainMenu()
{
	mainMenu.printMainMenu();
}

// Opens a Fight
void GameController::startFight()
{
	fightMonster.Fight();
}

// Opens Prayer Room
void GameController::openPrayerRoom()
{
	prayerRoom.HealPlayer();
}

// Opens Upgrade Room
void GameController::openUpgradeRoom()
{
	upgradeRoom.PlayerUpgrades();
}

// Opens Corridor
void GameController::openCorridor()
{
	exploreDungeon.Corridor();
}

// Opens Treasure Room
void GameController::openTreasureRoom()
{
	treasureRoom.printTreasureRoom();
}

// Adds Player Details and Score to Text File
void GameController::updateScoresFile()
{
	string fileName("Scores.txt");
	ofstream updateScores;

	updateScores.open(fileName, ios_base::app);
	updateScores << "Monk Name: " << getMonkName() << " | Monk Description: " << getMonkDesc() << " | Score: " << getPoints() << endl;
}