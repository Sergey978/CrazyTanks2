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
	static const int PLAYERS_LIFE = 3;
	static const int FIELD_LENGTH = 30;
	static const int FIELD_WIDTH = 30;
	static const  int NUMBER_OF_ENEMY = 5;
	static const  int NUMBER_OF_WALL = 20;
	static const  int MAX_LENGTH_OF_WALL = 10;
	//game options   chance 1/n	
	static const  int CHANCE_ENEMY_ACTION = 2;
	
	void startGame();
	void stopGame();
	void setIsPause(bool val);
	bool getIsPause();
	void update();
	void render();

	
	void addEntity(Entity &entity);
	void onEntityDestroyed(Entity &entity);

	void gameOver();
	bool checkIsTarget(std::vector<Group> Targets, Group entityTarget);
	std::map<int, Entity *> getEntities();
	void handleEvent(Signal sig, Entity &sender);

	~Game();

private:
	int playerLife_ = PLAYERS_LIFE;
	int enemyTanks_ = NUMBER_OF_ENEMY;
	bool isWin_ = false;
	bool isPause_ = false;
	std::string message_ = "";
	int  score_ = 0, minutes_ = 0, seconds_ = 0;
	

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

	void drawMessage_();

};


#endif // !GAME_H;
