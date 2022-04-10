#include "pch.h"
#include "GoblinDetails.h"

// Constructor
GoblinDetails::GoblinDetails()
{
	this->maxHealth = 10;
	this->attackPoints = 2;
}

// Deconstructor
GoblinDetails::~GoblinDetails()
{

}

// Get Goblin's Health
int GoblinDetails::getHealth()
{
	return health;
}

// Set Goblin's Health
void GoblinDetails::setHealth(int health)
{
	this->health = health;
}

// Get Goblin's Max Health
int GoblinDetails::getMaxHealth()
{
	return maxHealth;
}

// Set Goblin's Max Health
void GoblinDetails::setMaxHealth(int maxHealth)
{
	this->maxHealth = maxHealth;
}

// Get Goblin's Attack Points
int GoblinDetails::getAttackPoints()
{
	return attackPoints;
}

// Set Goblin's Attack Points
void GoblinDetails::setAttackPoints(int attackPoints)
{
	this->attackPoints = attackPoints;
}

// Decrease Goblin's Health When Damage is Taken
void GoblinDetails::takeDamage(int damage)
{
	this->health -= damage;
}