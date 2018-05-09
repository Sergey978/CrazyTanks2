#include"stdafx.h"
#include "body.h"


Body::Body(Entity *ent)
{
	this->entity = ent;
	x = 0;
	y = 0;
	direct = Up;

}

// return true if point not available
bool Body::testCollision(Entity &otherEntity)
{
	int oX_ = otherEntity.getBody()->getX();
	int oY_ = otherEntity.getBody()->getY();


	if (x == oX_ && y == oY_)
	{
		return true;
	}

	return false;
}

int Body::getX()
{
	return this->x;
}

void Body::setX(int x_)
{
	x = x_;
}

int Body::getY()
{
	return y;
}

void Body::setY(int y_)
{
	y = y_;
}

void Body::setDamage(int dmg)
{
	damage = dmg;
}

int Body::getDamage()
{
	return damage;
}

void Body::collisionAct(Entity & otherEntity)
{
	if (otherEntity.getHealth())
	{
		otherEntity.getHealth()->hit(damage);
	}
}



Direction Body::getDirection()
{
	return this->direct;
}

void Body::setDirection(Direction direct)
{
	this->direct = direct;
}




Body::~Body()
{
}
