#ifndef GAME_H
#define GAME_H
#pragma once
#include"Entity.h"
#include"Tank.h"
#include"Wall.h"
#include"Gold.h"
#include "EnemyTank.h"
#include <windows.h>
#include"IObserver.h"
#include"EntityCreator.h"

class Game: public IObserver
{
public:
	Game();

	static const int FIELD_LENGTH = 30;
	static const int FIELD_WIDTH = 30;
	static const  int NUMBER_OF_ENEMY = 5;
	static const  int NUMBER_OF_WALL = 10;
	static const  int MAX_LENGTH_OF_WALL = 10;
	//game options   chance 1/n
	
	static const  int CHANCE_ENEMY_ACTION = 2;
	

	void startGame();
	void stopGame();
	
	void setPlayers(std::vector<IEntity *> players);
	std::vector<IEntity *> getPlayers();
	
	void update();
	void render();
	
	void addEntity(IEntity *entity);
	void onEntityDestroyed(Entity *entity);
	void onPlayerDestroyed();
	void gameOver();
	std::vector<IEntity *> getEntities();

	void handleEvent(Signal sig, Entity *sender);

	~Game();

private:
	std::vector<IEntity *> entities;
	std::vector<IEntity *> players;
	std::vector<IEntity *> enemies;
	std::vector<IEntity *> neutral;

	COORD genPosition(int maxX, int maxY);
	bool exit_ = false;

	void setWalls_();
	void setCastle_();

	bool isAvailablePosition_(int x, int y, int length, Direction direct);
	void Game::SetWindow_(int Width, int Height);

	
	
};


#endif // !GAME_H;
