#include "pch.h"
#include "MainMenu.h"
#include "FightMonster.h"
#include "Test.h"

using namespace std;

int main()
{
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

    MainMenu MainMenu;
    Test test;

    MainMenu.printMainMenu();
}
