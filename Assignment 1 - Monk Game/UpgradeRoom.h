#pragma once

#include "pch.h"

using namespace std;

class UpgradeRoom
{
public:
	UpgradeRoom();
	~UpgradeRoom();
	void UpgradeHealth();
	void UpgradeAttackPoints();
	void PlayerUpgrades();
	void InputOption();
private:
	int option;
};