#ifndef BODY_H
#define BODY_H
#include "stdafx.h"
#include"Entity.h"

class Entity;

class Body
{
public:
	Body(Entity *entity);
	bool testCollision(Entity &otherEntity);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	Direction getDirection();
	void setDirection(Direction direct);
	virtual ~Body();


private:
	Entity *entity;
	int x, y;
	Direction direct;

};

#endif
