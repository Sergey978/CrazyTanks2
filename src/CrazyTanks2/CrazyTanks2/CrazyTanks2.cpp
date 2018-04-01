// CrazyTanks2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


class Game
{
public:
	static const int ENEMIES = 5;
	static const int WALLS = 10;
	static const int FIELD_SIZE  = 30;

	//maximum length of walls
	const unsigned int MAX_LENGTH_OF_WALL = 10;
	//game options   chance 1/n
	const unsigned int CHANCE_CHANGE_DIRECRION = 2;
	const unsigned int CHANCE_ENEMY_MOVE = 2;
	const unsigned int CHANCE_SHOOT_ENEMY = 10;

	void gameStart();
	void gameStop();

	void gameInitialize();

private:
	bool isWin;
	bool isLose;




};

int main()
{
    return 0;
}

