#include "pch.h"
#include "MonkDetails.h"

// Constructor
MonkDetails::MonkDetails()
{
	this->health = 15;
	this->maxHealth = 15;
	this->attackPoints = 3;
	this->points = 0;
}

// Deconstructor
MonkDetails::~MonkDetails()
{

}

// Get Monk's Name
string MonkDetails::getName()
{
	return name;
}

// Set Monk's Name
void MonkDetails::setName(string name)
{
	this->name = name;
}

// Get Monk's Desc
string MonkDetails::getDesc()
{
	return desc;
}

// Set Monk's Desc
void MonkDetails::setDesc(string desc)
{
	this->desc = desc;
}

// Get Monk's Health
int MonkDetails::getHealth()
{
	return health;
}

// Set Monk's Health
void MonkDetails::setHealth(int health)
{
	this->health = health;
}

// Get Monk's Max Health
int MonkDetails::getMaxHealth()
{
	return maxHealth;
}

// Set Monk's Max Health
void MonkDetails::setMaxHealth(int maxHealth)
{
	this->maxHealth = maxHealth;
}

// Get Monk's Attack Points
int MonkDetails::getAttackPoints()
{
	return attackPoints;
}

// Set Monk's Attack Points
void MonkDetails::setAttackPoints(int attackPoints)
{
	this->attackPoints = attackPoints;
}

// Decrease Monks Health When Damage is Taken
void MonkDetails::takeDamage(int damage)
{
	this->health -= damage;
}

// Heals Monk to Full Health
void MonkDetails::heal()
{
	this->health = maxHealth;
}

// Get Game Difficulty
int MonkDetails::getDifficulty()
{
	return difficulty;
}

// Set the Game Difficulty
void MonkDetails::setDifficulty(int difficulty)
{
	this->difficulty = difficulty;
}

// Get the Total Points Scored By The Player
double MonkDetails::getPoints()
{
	return points;
}

// Sets the Total Points Scored By The Player
void MonkDetails::setPoints(int hitsTaken)
{
	if (hitsTaken <= 0) { hitsTaken = 1; }

	switch (getDifficulty())
	{
	case(1):
		points += hitsTaken * 0.5 * 100;
		break;
	case(2):
		points += hitsTaken * 100;
		break;
	case(3):
		points += hitsTaken * 1.5 * 100;
		break;
	}
}

// Get the Number of Upgrades the Player has Left
int MonkDetails::getUpgradesLeft()
{
	return upgradesLeft;
}

// Set the Number of Upgrades the Player has Left
void MonkDetails::setUpgradesLeft(int upgradesLeft)
{
	this->upgradesLeft = upgradesLeft;
}

// Get the Number of Heals the Player has Left
int MonkDetails::getHealsLeft()
{
	return healsLeft;
}

// Set the Number of Heals the Player has Left
void MonkDetails::setHealsLeft(int healsLeft)
{
	this->healsLeft = healsLeft;
}

// Get can Player Heal
bool MonkDetails::getCanHeal()
{
	return canHeal;
}

// Set can Player Heal
void MonkDetails::setCanHeal(bool canHeal)
{
	this->canHeal = canHeal;
}

// Get can Player Upgrade
bool MonkDetails::getCanUpgrade()
{
	return canUpgrade;
}

// Set can Player Upgrade
void MonkDetails::setCanUpgrade(bool canUpgrade)
{
	this->canUpgrade = canUpgrade;
}

// Get Points Required to Open Treasure Room
int MonkDetails::getPointsRequired()
{
	return pointsRequired;
}

// Set Points Required to Open Treasure Room
void MonkDetails::setPointsRequired(int pointsRequired)
{
	this->pointsRequired = pointsRequired;
}