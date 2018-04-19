#ifndef BODY_H
#define BODY_H
#include "stdafx.h"
#include"IEntity.h"

class IEntity;

class Body
{
public:
	Body(IEntity *entity);
	bool testCollision(IEntity &otherEntity);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	Direction getDirection();
	void setDirection(Direction direct);
	virtual ~Body();


private:
	IEntity *entity;
	int x, y;
	Direction direct;

};

#endif
