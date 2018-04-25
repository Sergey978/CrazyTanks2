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

	if (x < 0 || y < 0 )
	{
		return false;
	}

	if (direct == Direction::Right )
	{
		x2 = x + length; y2 = y;
		if (Game::FIELD_WIDTH < x2)
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
		for (int ye = y; y <= y2; ye++)
		{
			for each (IEntity *ent in entities)
			{
				if (ent->getBody()->getX() == xe && ent->getBody()->getY == ye)
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
