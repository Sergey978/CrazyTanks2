#pragma once
#include "IGameObject.h"


class AGameObject :
	public IGameObject
{
public:

	void setPosition(Position position);
	Position getPosition();
	virtual Position generatePosition(int maxX, int maxY, int maxLength);
	void setIdObject(int id);
	int getIdObject();
	int checkColision(Position position, int distance);

	AGameObject();
	~AGameObject();

protected:
	Position position;
	int health;
	int idObject;
};

