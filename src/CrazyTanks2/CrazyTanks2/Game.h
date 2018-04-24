#ifndef GAME_H
#define GAME_H
#pragma once
#include"Entity.h"
#include"Tank.h"
#include"Wall.h"
#include"Gold.h"
#include "EnemyTank.h"
#include <windows.h>
#include"IObsever.h"

class Game: public IObsever
{
public:
	Game();

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
	void stopGame();
	
	void setPlayers(std::vector<IEntity *> players);
	std::vector<IEntity *> getPlayers();
	
	void update();
	void render();
	
	void addEntity(IEntity &entity);
	void onEntityDestroyed(Entity &entity);
	void onPlayerDestroyed();
	void gameOver();
	std::vector<IEntity *> getEntities();

	void handleEvent(Signal sig, IEntity &sender);

	~Game();

private:
	std::vector<IEntity *> entities;
	std::vector<IEntity *> players;
	std::vector<IEntity *> enemies;
	std::vector<IEntity *> neutral;

	COORD genPosition(int maxX, int maxY);
	bool exit_ = false;

	void setWalls();
	
};


#endif // !GAME_H;
