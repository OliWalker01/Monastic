#pragma once

#include "pch.h"

using namespace std;

class MonkDetails
{
public:
	MonkDetails();
	~MonkDetails();
	string getName();
	void setName(string);
	string getDesc();
	void setDesc(string);
	int getHealth();
	void setHealth(int);
	int getMaxHealth();
	void setMaxHealth(int);
	int getAttackPoints();
	void setAttackPoints(int);
	void takeDamage(int);
	void heal();
	int getDifficulty();
	void setDifficulty(int);
	double getPoints();
	void setPoints(int);
	int getUpgradesLeft();
	void setUpgradesLeft(int);
	int getHealsLeft();
	void setHealsLeft(int);
	bool getCanHeal();
	void setCanHeal(bool);
	bool getCanUpgrade();
	void setCanUpgrade(bool);
	int getPointsRequired();
	void setPointsRequired(int);

private:
	string name, desc;
	int health, maxHealth, attackPoints, difficulty, upgradesLeft, healsLeft, pointsRequired;
	double points;
	bool canHeal, canUpgrade;
};