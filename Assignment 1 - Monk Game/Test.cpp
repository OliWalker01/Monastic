#include "pch.h"
#include "test.h"
#include "GameController.h"

Test::Test()
{

}

Test::~Test()
{

}

void Test::RunTest()
{
	GameController gameController;

	system("cls");

	cout << "Monk Name: " << gameController.getMonkName() << endl;
	cout << "Monk Description: " << gameController.getMonkDesc() << endl;
	cout << "Monk Health: " << gameController.getMonkHealth() << endl;
	cout << "Monk Attack Points: " << gameController.getMonkAttackPoints() << endl << endl;

	cout << "Game Difficulty: " << gameController.getDifficulty() << endl;
	cout << "Monster Max Health: " << gameController.getGoblinMaxHealth() << endl;
	cout << "Monster Attack Points: " << gameController.getGoblinAttackPoints() << endl << endl;

	system("pause");
}