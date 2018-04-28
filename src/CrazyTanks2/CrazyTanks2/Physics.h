#ifndef PHYSICS_H
#define PHYSICS_H
#pragma once
#include "IMovable.h"
#include"Entity.h"
class Physics :
	public IMovable
{
public:
	
	Physics(Entity *ent);
	void move();
	virtual ~Physics();

private:
	Entity *entity;
};

#endif // !PHYSICS_H
