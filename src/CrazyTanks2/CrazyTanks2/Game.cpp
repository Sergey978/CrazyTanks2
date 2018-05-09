#include "stdafx.h"
#include "Game.h"

Game::Game()
{
}

void Game::stopGame() {
}

void Game::update() {

	seconds_ = (clock() / 1000) % 60;
	minutes_ = (clock() / 1000) / 60;


	int oldX_;
	int	oldY_;

	std::map<int, Entity *>::iterator it;
	std::map<int, Entity *>::iterator it2;
	for (it = entities.begin(); it != entities.end(); it++)
	{
		oldX_ = it->second->getBody()->getX();
		oldY_ = it->second->getBody()->getY();

		it->second->update();

		//testCollision with other Entities
		bool isCollision = false;

		for (it2 = entities.begin(); it2 != entities.end(); it2++)
		{
			//skip check colision with yourself
			if (it->second != it2->second)
			{
				if (it->second->getBody()->testCollision(*it2->second))
				{
					isCollision = true;
					// if other entity in targetGroup collision take damage
					if (checkIsTarget(it->second->getTargets(), it2->second->getGroup()))
					{
						it->second->getBody()->collisionAct(*it2->second);
					}

					if (it->second->getType() == EntityType::BulletInst)
					{

						it->second->notifyObservers(Signal::DestroyEntity, it->second);
					}

				}

			}

		}

		if (isCollision)
		{
			it->second->getBody()->setX(oldX_);
			it->second->getBody()->setY(oldY_);
		}
	}


	//add new entities in map
	for each (Entity *newEnt in newEntities)
	{
		addEntity(*newEnt);

	}
	newEntities.clear();

	//remove died entities from map
	for each (int diedId in diedEntityId)
	{

		delete(entities[diedId]);
		entities.erase(diedId);

	}
	diedEntityId.clear();

}

void Game::render() {

	drawParamsGame();

	std::map<int, Entity *>::iterator it;
	for (it = entities.begin(); it != entities.end(); it++)
	{
		it->second->render();
	}
}

void Game::startGame() {

	drawBorders_();
	setCastle_();
	setWalls_();

	Entity *playerTank = EntityCreator::getEntity(EntityType::TankInst);
	playerTank->addObserver(this);
	playerTank->setGroup(Group::Players);
	playerTank->setTargets(std::vector<Group>{ Group::Enemies, Group::Neutrals });

	addEntity(*playerTank);
	playerTank->getBody()->setX(5);
	playerTank->getBody()->setY(5);

	//set enemy tanks
	setEnemies_();


	update();
	render();
}

void Game::addEntity(Entity &entity) {
	entities[entity.getId()] = &entity;
}

void Game::onEntityDestroyed(Entity &entity) {

	//add  id of entities which destryed to vector 
	entity.getView()->clear();
	diedEntityId.push_back(entity.getId());

}

void Game::onPlayerDestroyed()
{
}

void Game::gameOver()
{
}

bool Game::checkIsTarget(std::vector<Group> Targets, Group entityTarget)
{
	bool result = false;

	for each(Group target in Targets)
	{
		if (target == entityTarget)
		{
			result = true;
		}
	}
	return result;
}

std::map<int, Entity*> Game::getEntities()
{
	return entities;
}

void Game::handleEvent(Signal sig, Entity & sender)
{
	switch (sig)
	{
	case Signal::CreateEntity:
	{
		if (&sender != nullptr)
		{
			sender.addObserver(this);
			addEntity(sender);
		}
		break;
	}
	case Signal::DestroyEntity:
	{
		onEntityDestroyed(sender);
		break;

	}

	default:
	{


	}
	}
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

		int length = rand() % (MAX_LENGTH_OF_WALL)+1;
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
					Entity *wall = EntityCreator::getEntity(EntityType::WallInst);
					wall->addObserver(this);
					wall->getBody()->setX(x);
					wall->getBody()->setY(y);
					wall->setGroup(Group::Neutrals);
					addEntity(*wall);

				}

			}
			wallsNumb_++;
		}

	}


}

void Game::setEnemies_()
{
	int enemyNumb_ = 0; // current generated number of walls

	while (enemyNumb_ <= NUMBER_OF_ENEMY)
	{

		Direction direct = static_cast <Direction>(rand() % 2);
		COORD newCoord = genPosition(FIELD_WIDTH, FIELD_LENGTH);

		if (isAvailableArea_(newCoord.X, newCoord.Y, 2))
		{

			Entity *enemyT = EntityCreator::getEntity(EntityType::EnemyTankInst);
			enemyT->addObserver(this);
			enemyT->getBody()->setX(newCoord.X);
			enemyT->getBody()->setY(newCoord.Y);
			enemyT->setGroup(Group::Enemies);
			enemyT->setTargets(std::vector<Group>{ Group::Players, Group::Neutrals });
			addEntity(*enemyT);						
			enemyNumb_++;
		}

	}

}

void Game::setCastle_()
{
	//set gold
	Entity *gold = EntityCreator::getEntity(EntityType::GoldInst);
	gold->addObserver(this);
	int x = Game::FIELD_WIDTH / 2;
	int y = Game::FIELD_LENGTH - 1;
	gold->getBody()->setX(x);
	gold->getBody()->setY(y);
	gold->setGroup(Group::Players);
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
			Entity *wall = EntityCreator::getEntity(EntityType::WallInst);
			wall->addObserver(this);
			wall->getBody()->setX(xw);
			wall->getBody()->setY(yw);
			wall->setGroup(Group::Neutrals);
			addEntity(*wall);


		}

	}


}

bool Game::isAvailablePosition_(int x, int y, int length, Direction direct)
{
	int x2 = 0, y2 = 0; // calculated coordinates for area

	if (x < 1 || y < 1)
	{
		return false;
	}

	if (direct == Direction::Right)
	{
		x2 = x + length; y2 = y;
		if (Game::FIELD_WIDTH <= x2)
		{
			return false;
		}

	}
	if (direct == Direction::Down)
	{
		x2 = x; y2 = y + length;

		if (Game::FIELD_LENGTH <= y2)
		{
			return false;
		}

	}

	//check if other entity busy this place
	std::map<int, Entity *>::iterator it;
	for (int xe = x; xe <= x2; xe++)
	{
		for (int ye = y; ye <= y2; ye++)
		{
			for (it = entities.begin(); it != entities.end(); it++)
			{
				if (it->second->getBody()->getX() == xe && it->second->getBody()->getY() == ye)
				{
					return false;
				}
			}
		}


	}

	return true;

}

bool Game::isAvailableArea_(int x, int y, int distance)
{
	if (x - distance < 1 || y - distance < 1 || y + distance > Game::FIELD_LENGTH || x + distance > Game::FIELD_WIDTH)
	{
		return false;
	}


	//check if other entity busy this area
	std::map<int, Entity *>::iterator it;
	for (int xe = x - distance; xe <= x + distance; xe++)
	{
		for (int ye = y - distance; ye <= y + distance; ye++)
		{
			for (it = entities.begin(); it != entities.end(); it++)
			{
				if (it->second->getBody()->getX() == xe && it->second->getBody()->getY() == ye)
				{
					return false;
				}
			}
		}
	}

	return true;

}

void Game::SetWindow_(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}

void Game::drawBorders_()
{

	HANDLE hOut;
	COORD Position;

	SetWindow_(80, 40);

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);


	for (int x = 0; x < FIELD_WIDTH + 2; x++)
	{
		for (int y = 0; y < FIELD_LENGTH + 2; y++)
		{
			if (x == 0 || y == 0 || x == FIELD_WIDTH + 1 || y == FIELD_LENGTH + 1)
			{

				Position.X = x;
				Position.Y = y;

				SetConsoleCursorPosition(hOut, Position);

				std::cout << '8';
			}

		}
	}

}

void Game::drawParamsGame()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = Game::FIELD_WIDTH + 5;
	Position.Y = Game::FIELD_LENGTH /2 - 5;
	SetConsoleCursorPosition(hOut, Position);

	std::cout << " Lives   " << playerLife_ << std::endl;

	Position.Y = Game::FIELD_LENGTH / 2 - 3;

	SetConsoleCursorPosition(hOut, Position);
	std::cout << " Score   " << score_ << std::endl;

	Position.Y = Game::FIELD_LENGTH / 2 - 1;

	SetConsoleCursorPosition(hOut, Position);
	std::cout << " Score   " << score_ << std::endl;

	Position.Y = Game::FIELD_LENGTH / 2 + 1;

	SetConsoleCursorPosition(hOut, Position);

	std::cout << " Time   " << minutes_ << " : " << seconds_ << ' ' << std::endl;
}

Game::~Game()
{
}
