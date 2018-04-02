#pragma once
#include "AGameObject.h"
#include "IMovable.h"


class AMovableGameObject :
	public AGameObject, public IMovable
{
public:
	AMovableGameObject();
	~AMovableGameObject();

	void move(Position position);
	bool isEnemy();
	void setIsEnemy();

private:
	bool isEnemy;
};

