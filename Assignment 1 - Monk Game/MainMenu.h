#pragma once

#include "pch.h"
#include "MainMenu.h"
#include "HelpMenu.h"
#include "MonkCreation.h"

using namespace std;

class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void MenuOptions();
	void printMainMenu();
	void printScoreboard();

private:
	int menuOption;
};