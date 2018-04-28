#ifndef ENTITY_CREATOR_H
#define ENTITY_CREATOR_H
#pragma once
#include "IEntityCreator.h"

class EntityCreator :
	public IEntityCreator
{
public:
	EntityCreator();
	static Entity *getEntity(EntityType type);
	

	virtual ~EntityCreator();
};
#endif // !ENTITY_CREATOR_H