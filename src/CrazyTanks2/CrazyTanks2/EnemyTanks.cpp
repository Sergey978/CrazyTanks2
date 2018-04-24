#include "stdafx.h"
#include "EnemyTank.h"
#include "View.h"
#include"Game.h"


EnemyTank::EnemyTank()
{
	Body *body = new Body(this);
	body->setDirection(Up);
	setBody(body);

	view = new View(this);
	view->setSymbol('W');

	physics = new Physics(this);

}


void EnemyTank::update()
{
	view->setSymbol(' ');//clear old position
	render();

	Direction direct = getBody()->getDirection();

	int oldX_ = this->getBody()->getX();
	int	oldY_ = this->getBody()->getY();



	if (rand() % Game::CHANCE_ENEMY_MOVE == 1)
	{
		if (rand() % Game::CHANCE_CHANGE_DIRECRION == 1)
		{
			direct = static_cast <Direction>(rand() % (Down + 1));
		}

		physics->move(direct);
	}

	bool movePosible = true;
	std::vector<IEntity *> otherEntities;
	otherEntities = getTargets();
	std::vector<IEntity *> group = getGroup();
	otherEntities.insert(otherEntities.end(), group.begin(), group.end());

	for each (IEntity *ent in otherEntities)
	{
		//skip check colision with yourself
		if (ent != this)
		{
			if (getBody()->testCollision(*ent))
			{
				movePosible = false;
			}
		}

	}

	int newX_ = this->getBody()->getX();
	int	newY_ = this->getBody()->getY();


	if (newX_ >= 30 || newX_ == 0 || newY_ >= 30 || newY_ == 0)
	{
		movePosible = false;
	}

	if (movePosible == false)
	{
		getBody()->setX(oldX_);
		getBody()->setY(oldY_);
	}

	view->setSymbol('W'); //set symbol in new position

}

void EnemyTank::onDied(Entity &entity)
{
}



void EnemyTank::render()
{

	view->render();
}

void EnemyTank::setView(IView *view_)
{
	view = view_;
}

IView *EnemyTank::getView() const
{
	return view;
}



void EnemyTank::setPhysics(IMovable * phys)
{
	physics = phys;
}

IMovable * EnemyTank::getPhysics() const
{
	return physics;
}



EnemyTank::~EnemyTank()
{
}
