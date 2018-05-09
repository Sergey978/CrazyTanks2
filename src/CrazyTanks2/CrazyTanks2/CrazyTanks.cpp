
#include "stdafx.h"
#include"Game.h"
#include"Tank.h"
#include <iostream>
#include<Windows.h>
#include <ctime>

int main()
{
	srand((unsigned)time(0)); //So random numbers will be always random.
	Game game;

	game.startGame();
	while (!game.getIsPause())
	{
		game.update();
		game.render();
		Sleep(20);

	}

	getchar();
	return 0;
}

