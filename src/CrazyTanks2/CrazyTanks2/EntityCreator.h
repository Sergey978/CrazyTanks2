#ifndef ENTITY_CREATOR_H
#define ENTITY_CREATOR_H
#pragma once
#include "IEntityCreator.h"
class EntityCreator :
	public IEntityCreator
{
public:
	EntityCreator();
	IEntity *getEntity(EntityType type);
	IEntity *newTank();
	IEntity *newEnemyTank();
	IEntity *newBullet();
	IEntity *newWall();
	IEntity *newGold();

	virtual ~EntityCreator();
};
#endif // !ENTITY_CREATOR_H