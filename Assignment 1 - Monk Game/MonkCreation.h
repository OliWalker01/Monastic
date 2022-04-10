#pragma once

#include "pch.h"

using namespace std;

class MonkCreation
{
public:
	MonkCreation();
	~MonkCreation();
	void createMonk();
	void confirmDetails();
	void setDifficulty();

private:
	string monkName, monkDescription, blank;
	int difficulty;
	char confirm;
};