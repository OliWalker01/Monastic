#pragma once

#include "pch.h"

using namespace std;

class FightMonster
{
public:
	FightMonster();
	~FightMonster();
	void Fight();
	void HeadsOrTails();
	void HeadsOrTailsInput();
	void PlayerFight();
	void GoblinFight();
	void gameLostorWon();
	void lostMenuInput();

private:
	bool gameOver, canHeal, hasGameStarted = false, playersTurn;
	int fightOption, halfOfHealth, hitsTaken, option, playerFirst;
	char headsOrTails;
	string coinSide;
};