#pragma once

#include "pch.h"

using namespace std;

class GameController
{
public:
	GameController();
	~GameController();

	string getMonkName();
	void setMonkName(string *);
	string getMonkDesc();
	void setMonkDesc(string *);
	int getMonkHealth();
	void setMonkHealth(int);
	int getMonkMaxHealth();
	void setMonkMaxHealth(int);
	int getMonkAttackPoints();
	void setMonkAttackPoints(int);
	void monkTakeDamage();
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

	int getGoblinHealth();
	void setGoblinHealth(int);
	int getGoblinMaxHealth();
	void setGoblinMaxHealth(int);
	int getGoblinAttackPoints();
	void setGoblinAttackPoints(int);
	void goblinTakeDamage();

	int getDifficulty();
	void setDifficulty(int);

	bool movePicker();
	void goblinMovePicker();

	double getPoints();
	void setPoints(int);

	void openMainMenu();
	void startFight();
	void openPrayerRoom();
	void openUpgradeRoom();
	void openCorridor();
	void openTreasureRoom();

	void updateScoresFile();

private:
	int goblinHP, goblinAP, goblinMaxHP;
	int difficulty, chance;
	double points;
};