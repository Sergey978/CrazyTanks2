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
	void setDamage(int dmg);
	int getDamage();
	void collisionAct(Entity &otherEntity);
	Direction getDirection();
	void setDirection(Direction direct);
	virtual ~Body() ;


private:
	Entity *entity;
	int x, y;
	int damage = 0;
	Direction direct;

};

#endif
