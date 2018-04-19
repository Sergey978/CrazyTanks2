#pragma once
#include "IMovable.h"
#include"IEntity.h"
class Physics :
	public IMovable
{
public:
	
	Physics(IEntity *ent);
	void move(Direction direct);
	virtual ~Physics();

private:
	IEntity *entity;
};

