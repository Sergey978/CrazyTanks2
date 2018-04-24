#include "stdafx.h"
#include "Game.h"

Game::Game()
{
}

void Game::stopGame() {
}


void Game::update() {
	for each(IEntity *player in players)
	{

		std::vector<IEntity *> targets = enemies;
		targets.insert(targets.end(), neutral.begin(), neutral.end());
		player->setTargets(targets);
	}

	for each(IEntity *enemy in enemies)
	{
		std::vector<IEntity *> targets = players;
		targets.insert(targets.end(), neutral.begin(), neutral.end());
		enemy->setTargets(targets);
	}

	for each (Entity *ent in entities)
	{
		ent->update();

	}
}

void Game::render() {
	for each (Entity *ent in entities)
	{
		ent->render();

	}
}

void Game::startGame() {

	//set gold
	Gold *gold = new Gold;
	players.push_back(gold);
	gold->setGroup(players);
	addEntity(*gold);

	setWalls();

	Tank *playerTank = new Tank;
	playerTank->setGroup(players);
	players.push_back(playerTank);
	addEntity(*playerTank);

	EnemyTank *enemyT = new EnemyTank;

	enemyT->getBody()->setX(20);
	enemyT->getBody()->setY(20);
	enemies.push_back(enemyT);
	addEntity(*enemyT);

	update();
	render();
}



void Game::addEntity(IEntity &entity) {
	entities.push_back(&entity);
}

void Game::onEntityDestroyed(Entity &entity) {
	// remove destroyed entity
}

void Game::onPlayerDestroyed()
{
}

void Game::gameOver()
{
}

std::vector<IEntity*> Game::getEntities()
{
	return entities;
}

void Game::handleEvent(Signal sig, IEntity & sender)
{
}


void Game::setPlayers(std::vector<IEntity *> players)
{
	this->players = players;
}

std::vector<IEntity *> Game::getPlayers()
{
	return players;
}



COORD Game::genPosition(int maxX, int maxY)
{
	COORD pos;
	pos.X = rand() % (maxX + 1);
	pos.Y = rand() % (maxY + 1);
	return pos;
}

void Game::setWalls()
{
	//set walls
	int wallsNumb_ = 0; // current generated number of walls
	std::vector <IEntity *> wall_;
	while (wallsNumb_ < NUMBER_OF_WALL)
	{

		int length = rand() % (MAX_LENGTH_OF_WALL + 1);
		int direct = rand() % 2;
		COORD newCoord = genPosition(FIELD_WIDTH, FIELD_LENGTH);

		if (direct == 1) //horizont position
		{
			for (int x = newCoord.X; x <= newCoord.X + length; x++)
			{
				if (x <= FIELD_WIDTH) {

					Wall *newWall_ = new Wall(x, newCoord.Y);
					wall_.push_back(newWall_);
				}


			}
		}
		else if (direct == 0) //vertical position
		{

			for (int y = newCoord.Y; y <= newCoord.Y + length; y++)
			{

				if (y <= FIELD_WIDTH) {

					Wall *newWall_ = new Wall(newCoord.X, y);
					wall_.push_back(newWall_);

				}

			}


		}
		bool collision = false;
		for each (IEntity *ent in getEntities())
		{
			//check collision with other entities

			for each (IEntity *wall in wall_)
			{

				collision = ent->getBody()->testCollision(*wall);
			}

		}
		if (collision == false)
		{
			wallsNumb_++;
			for each (IEntity *wall in wall_)
			{
				neutral.push_back(wall);
				wall->setGroup(neutral);
				addEntity(*wall);
			}


		}
		wall_.clear();

	}


}





Game::~Game()
{
}
