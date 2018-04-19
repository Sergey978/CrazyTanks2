#if !defined(_TANKSGAME_H)
#define _TANKSGAME_H
#pragma once
#include "Game.h"
#include"Tank.h"
#include"Wall.h"
#include"Gold.h"
#include "EnemyTank.h"
#include <windows.h>

class TanksGame :
	public Game
{
public:
	TanksGame();
	static const int FIELD_LENGTH = 30;
	static const int FIELD_WIDTH = 30;
	static const  int NUMBER_OF_ENEMY = 5;
	static const  int NUMBER_OF_WALL = 10;
	static const  int MAX_LENGTH_OF_WALL = 10;
	//game options   chance 1/n
	static const  int CHANCE_CHANGE_DIRECRION = 2;
	static const  int CHANCE_ENEMY_MOVE = 2;
	static const  int CHANCE_SHOOT_ENEMY = 10;
	
	void startGame();
	void onPlayerDestroyed();
	void gameOver();
	void restart();
	void stopGame();
	void udate();
	void setPlayers(vector<IEntity *>);
	vector<IEntity *> getPlayers();
	void setTargets(vector<IEntity *>);
	vector<IEntity *> getTargets();
	virtual ~TanksGame();

private:
	vector<IEntity *> players;
	vector<IEntity *> enemies;
	vector<IEntity *> neutral;

	COORD genPosition(int maxX, int maxY);
	bool exit_ = false;

	void setWalls();

};

#endif  //_TANKSGAME_