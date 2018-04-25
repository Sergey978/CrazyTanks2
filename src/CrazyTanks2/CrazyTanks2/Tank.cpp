#include "stdafx.h"
#include "Tank.h"
#include"View.h"
#include"Physics.h"
#include"Game.h"



Tank::Tank()
{
	Body *body = new Body(this);
	
	body->setDirection(Up);
	setBody(body);

	view = new View(this);
	view->setSymbol('#');

	//setView(view);
	physics = new Physics(this);
}

void Tank::update()
{
	view->setSymbol(' ');//clearold position
	render();


	KeyPressed key_ = Control::getKey();

	int oldX_, oldY_;

	oldX_ = this->getBody()->getX();
	oldY_ = this->getBody()->getY();

	switch (key_)
	{
	case KeyPressed::left:
	{
		physics->move(Direction::Left);
		break;


	}

	case KeyPressed::right:
	{
		physics->move(Direction::Right);
		break;

	}

	case KeyPressed::up:
	{
		physics->move(Direction::Up);
		break;

	}

	case KeyPressed::down:
	{
		physics->move(Direction::Down);
		break;

	}

	}

	// checking the ability to move
	bool movePosible = true;
	int newX_ = this->getBody()->getX();
	int	newY_ = this->getBody()->getY();


	if (newX_ >= Game::FIELD_WIDTH || newX_ == 0 || newY_ >= Game::FIELD_LENGTH || newY_ == 0)
	{
		movePosible = false;
	}
	else
	{
		std::vector<IEntity *> otherEntities = getTargets();
		std::vector<IEntity *> group = getGroup();
		otherEntities.insert(otherEntities.end(), group.begin(), group.end());
		for each (IEntity *ent in otherEntities)
		{
			if (getBody()->testCollision(*ent))
			{
				movePosible = false;
			}

		}

	}
	
	if (movePosible == false)
	{
		getBody()->setX(oldX_);
		getBody()->setY(oldY_);
	}

	view->setSymbol('#');

}

void Tank::onDied(Entity &entity)
{
}



void Tank::render()
{

	view->render();
}

void Tank::setView(IView *view_)
{
	view = view_;
}

IView *Tank::getView() const
{
	return view;
}



void Tank::setPhysics(IMovable * phys)
{
	physics = phys;
}

IMovable * Tank::getPhysics() const
{
	return physics;
}

void Tank::setHealth(IHealth * h)
{
	health = h;
}

IHealth * Tank::getHealth() const
{
	return health;
}



Tank::~Tank()
{
}
