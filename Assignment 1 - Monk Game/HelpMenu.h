#pragma once

#include "pch.h"
#include "MainMenu.h"

using namespace std;

class HelpMenu
{
public:
	HelpMenu();
	~HelpMenu();
	void printHelpMenu();

private:
	int helpOption;
};