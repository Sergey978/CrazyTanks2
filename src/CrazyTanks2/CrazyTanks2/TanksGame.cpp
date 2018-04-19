#include "stdafx.h"
#include "TanksGame.h"


TanksGame::TanksGame()
{
}


void TanksGame::startGame() {

	//set gold
	Gold *gold = new Gold;
	players.push_back(gold);
	gold->setGroup(players);
	addEntity(*gold);

	setWalls();

	Tank *playerTank = new Tank;
	vector<IEntity *> targets = enemies;

	//targets for Player's tank vector enemies and neutral
	targets.insert(targets.end(), neutral.begin(), neutral.end());

	playerTank->setTargets(targets);
	playerTank->setGroup(players);
	players.push_back(playerTank);
	addEntity(*playerTank);

	EnemyTank *enemyT = new EnemyTank;

	enemyT->getBody()->setX(20);
	enemyT->getBody()->setY(20);

	targets = players;
	//targets for Enemy tank's vector players and neutral
	targets.insert(targets.end(), neutral.begin(), neutral.end());
	enemyT->setTargets(targets);
	enemies.push_back(enemyT);
	addEntity(*enemyT);

	update();
	render();
}

void TanksGame::onPlayerDestroyed() {
}

void TanksGame::gameOver() {
}

void TanksGame::restart() {
}

void TanksGame::stopGame() {
}

void TanksGame::udate() {

	Game::update();
	/*
	if (enemies.size() == 0)
	{
		gameOver();
	}

	*/

}

void TanksGame::setPlayers(vector<IEntity *>)
{
}

vector<IEntity *> TanksGame::getPlayers()
{
	return vector<IEntity *>();
}

void TanksGame::setTargets(vector<IEntity *>)
{
}

vector<IEntity *> TanksGame::getTargets()
{
	return vector<IEntity *>();
}




TanksGame::~TanksGame()
{
}

COORD TanksGame::genPosition(int maxX, int maxY)
{
	COORD pos;
	pos.X = rand() % (maxX + 1);
	pos.Y = rand() % (maxY + 1);
	return pos;
}

void TanksGame::setWalls()
{
	//set walls
	int wallsNumb_ = 0; // current generated number of walls
	vector <IEntity *> wall_;
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


