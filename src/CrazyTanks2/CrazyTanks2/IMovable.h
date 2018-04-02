#pragma once
#include "AGameObject.h"

class IMovable
{
public:
	virtual bool isEnemy() = 0;
	virtual void move(Position position) = 0;

	IMovable();
	~IMovable();
};

