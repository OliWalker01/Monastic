#pragma once

#include "pch.h"

using namespace std;

class ExploreDungeon
{
public:
	ExploreDungeon();
	~ExploreDungeon();
	void Corridor();
	void inputOption();
	void confirmationInput();

private:
	int input, confirmation;
	bool validEntry;
};