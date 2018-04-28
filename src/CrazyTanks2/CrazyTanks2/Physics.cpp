#include "stdafx.h"
#include "Physics.h"
#include"Game.h"


Physics::Physics(Entity * ent)
{
	this->entity = ent;
}

void Physics::move()
{
	int curX_, curY_ ; //current x, y
	curX_ = entity->getBody()->getX();
	curY_ = entity->getBody()->getY();
	Direction direct = entity->getBody()->getDirection();

	switch (direct)
	{
	case Direction::Left:
	{
		if (curX_ > 1)
		{
			entity->getBody()->setX(--curX_);
		}
		
		break;

	}

	case Direction::Right:
	{
		if (curX_ < Game::FIELD_WIDTH )
		{
			entity->getBody()->setX(++curX_);
		}
		
		break;

	}

	case Direction::Up:
	{
		 
		if (curY_ > 1)
		{
			entity->getBody()->setY(--curY_);
		}

		break;

	}

	case Direction::Down:
	{
		
		if (curY_ < Game::FIELD_LENGTH )
		{
			entity->getBody()->setY(++curY_);
		}
		break;

	}

	
	}

	

}


Physics::~Physics()
{
}
