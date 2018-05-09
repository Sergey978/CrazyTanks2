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
#include <map>
#include <ctime>

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
		
	void update();
	void render();
	
	void addEntity(Entity &entity);
	void onEntityDestroyed(Entity &entity);
	void onPlayerDestroyed();
	void gameOver();
	bool checkIsTarget(std::vector<Group> Targets, Group entityTarget);
	std::map<int, Entity *> getEntities();
	void handleEvent(Signal sig, Entity &sender);

	~Game();

private:
	int playerLife_;
	int  score_, minutes_, seconds_;

	std::map<int, Entity *> entities;
	std::vector<Entity *> newEntities;
	std::vector<int > diedEntityId;
	
	COORD genPosition(int maxX, int maxY);
	bool exit_ = false;

	void setWalls_();
	void setEnemies_();
	void setCastle_();

	bool isAvailablePosition_(int x, int y, int length, Direction direct);
	bool isAvailableArea_(int x, int y, int distance);
	void Game::SetWindow_(int Width, int Height);

	void drawBorders_();

	void drawParamsGame();

};


#endif // !GAME_H;
