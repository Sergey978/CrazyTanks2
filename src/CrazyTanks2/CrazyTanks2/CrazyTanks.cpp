
#include "stdafx.h"
#include"TanksGame.h"
#include"Tank.h"
#include <iostream>
#include<Windows.h>
#include <ctime>

int main()
{
	srand((unsigned)time(0)); //So random numbers will be always random.
	TanksGame game;

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

