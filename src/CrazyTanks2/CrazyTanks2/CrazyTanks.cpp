
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
	while (1)
	{
		game.update();
		game.render();
		Sleep(50);

	}

	getchar();
	return 0;
}

