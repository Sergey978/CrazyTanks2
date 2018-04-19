#include "stdafx.h"
#include "Tank.h"
#include"View.h"
#include"Physics.h"



Tank::Tank()
{
	Body *body = new Body(this);
	body->setX(10);
	body->setY(10);
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
	move();
	view->setSymbol('#');


}

void Tank::onDied(Entity &entity)
{
}

void Tank::move()
{
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
	vector<IEntity *> targets_ = getTargets();
	for each (IEntity *ent in targets_)
	{
		if (getBody()->testCollision(*ent))
		{
			movePosible = false;
		}

	}


	if (movePosible == false)
	{
		getBody()->setX(oldX_);
		getBody()->setY(oldY_);
	}
	
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



Tank::~Tank()
{
}
