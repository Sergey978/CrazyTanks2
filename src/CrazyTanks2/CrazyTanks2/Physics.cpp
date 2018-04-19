#include "stdafx.h"
#include "Physics.h"


Physics::Physics(IEntity * ent)
{
	this->entity = ent;
}

void Physics::move(Direction direct)
{
	int curX_, curY_ , oldX_, oldY_; //current x, y
	curX_ = entity->getBody()->getX();
	curY_ = entity->getBody()->getY();
	oldX_ = curX_;
	oldY_ = curY_;

	switch (direct)
	{
	case Direction::Left:
	{
		
		entity->getBody()->setX(--curX_);
		break;

	}

	case Direction::Right:
	{
		
		entity->getBody()->setX(++curX_);
		break;

	}

	case Direction::Up:
	{
		 
		entity->getBody()->setY(--curY_);
		break;

	}

	case Direction::Down:
	{
		entity->getBody()->setY(++curY_);
		break;

	}

	
	}

	

}


Physics::~Physics()
{
}
