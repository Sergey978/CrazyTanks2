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


	//draw borders

	HANDLE hOut;
	COORD Position;
	for (int x = 0; x < FIELD_WIDTH + 2; x++)
	{
		for (int y = 0; y < FIELD_LENGTH + 2; y++)
		{
			if (x == 0 || y == 0 || x == FIELD_WIDTH + 1 || y == FIELD_LENGTH + 1)
			{


				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				Position.X = x;
				Position.Y = y;

				SetConsoleCursorPosition(hOut, Position);

				std::cout << '8';
			}

		}
	}


	setCastle_();

	setWalls_();

	IEntity *playerTank = EntityCreator::getEntity(EntityType::TankInst);
	playerTank->setGroup(players);
	players.push_back(playerTank);
	addEntity(*playerTank);
	playerTank->getBody()->setX(5);
	playerTank->getBody()->setY(5);

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

void Game::setWalls_()
{
	//set walls
	int wallsNumb_ = 0; // current generated number of walls
	
	while (wallsNumb_ < NUMBER_OF_WALL)
	{

		int length = rand() % (MAX_LENGTH_OF_WALL ) + 1;
		Direction direct = static_cast <Direction>(rand() % 2);
		COORD newCoord = genPosition(FIELD_WIDTH, FIELD_LENGTH);

		int x2 = 0, y2 = 0;
		if (isAvailablePosition_(newCoord.X, newCoord.Y, length, direct))
		{
			if (direct == Direction::Right)
			{
				x2 = newCoord.X + length; y2 = newCoord.Y;

			}
			else if (direct = Direction::Down)
			{
				y2 = newCoord.Y + length; x2 = newCoord.X;
			}

			for (int x = newCoord.X; x <= x2; x++)
			{
				for (int y = newCoord.Y; y <= y2; y++)
				{
					IEntity *wall = EntityCreator::getEntity(EntityType::WallInst);
					wall->getBody()->setX(x);
					wall->getBody()->setY(y);
					neutral.push_back(wall);
					wall->setGroup(neutral);
					addEntity(*wall);

					

				}

			}
			wallsNumb_++;
		}

	}


}

void Game::setCastle_()
{
	//set gold
	IEntity *gold = EntityCreator::getEntity(EntityType::GoldInst);
	int x = Game::FIELD_WIDTH / 2;
	int y = Game::FIELD_LENGTH - 1;
	gold->getBody()->setX(x);
	gold->getBody()->setY(y);
	players.push_back(gold);
	gold->setGroup(players);
	addEntity(*gold);

	//set walls of castle
	for (int xw = x - 1; xw <= x + 1; xw++)
	{
		for (int yw = y - 1; yw <= y + 1; yw++)
		{
			if (xw == x && yw == y)
			{
				continue;
			}
			IEntity *wall = EntityCreator::getEntity(EntityType::WallInst);
			wall->getBody()->setX(xw);
			wall->getBody()->setY(yw);
			neutral.push_back(wall);
			wall->setGroup(neutral);
			addEntity(*wall);


		}

	}


}

bool Game::isAvailablePosition_(int x, int y, int length, Direction direct )
{
	int x2 = 0, y2 = 0 ; // calculated coordinates for area

	if (x < 1 || y < 1 )
	{
		return false;
	}

	if (direct == Direction::Right )
	{
		x2 = x + length; y2 = y;
		if (Game::FIELD_WIDTH <= x2)
		{
			return false;
		}

	}
	if (direct == Direction::Down )
	{
		x2 = x; y2 = y + length;

		if (Game::FIELD_LENGTH <= y2)
		{
			return false;
		}
		
	}

	//check if other entity busy this place
	for (int xe = x; xe <= x2; xe++)
	{
		for (int ye = y; ye <= y2; ye++)
		{
			for each (IEntity *ent in entities)
			{
				if (ent->getBody()->getX() == xe && ent->getBody()->getY() == ye)
				{
					return false;
				}
			}
		}


	}

	return true;

}

Game::~Game()
{
}
