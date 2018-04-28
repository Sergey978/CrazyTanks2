#ifndef UNMOVED_H
#define UNMOVED_H
#pragma once
#include "IMovable.h"
#include "Entity.h"

class Unmoved :
	public IMovable
{
public:
	Unmoved(Entity *ent);
	void move();
	virtual ~Unmoved();

private:
	Entity *entity;
};

#endif // !UNMOVED_H