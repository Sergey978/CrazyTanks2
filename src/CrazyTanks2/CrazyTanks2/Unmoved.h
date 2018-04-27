#ifndef UNMOVED_H
#define UNMOVED_H
#pragma once
#include "IMovable.h"
#include "IEntity.h"

class Unmoved :
	public IMovable
{
public:
	Unmoved(IEntity *ent);
	void move(Direction direct);
	virtual ~Unmoved();

private:
	IEntity *entity;
};

#endif // !UNMOVED_H