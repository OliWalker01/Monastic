#pragma once

#include "pch.h"

using namespace std;

class GoblinDetails
{
public:
	GoblinDetails();
	~GoblinDetails();
	int getHealth();
	void setHealth(int);
	int getMaxHealth();
	void setMaxHealth(int);
	int getAttackPoints();
	void setAttackPoints(int);
	void takeDamage(int);

private:
	int health, maxHealth, attackPoints;
};