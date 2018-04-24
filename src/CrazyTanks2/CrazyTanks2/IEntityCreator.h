#ifndef IENTITYCREATOR_H
#define IENTITYCREATOR_H
#pragma once
#include "IEntity.h"
#include "Enums.h"
#include"Bullet.h"
#include"EnemyTank.h"
#include"Tank.h"
#include"Gold.h"
#include"Wall.h"



class IEntityCreator
{
public:
	
	virtual IEntity *getEntity(EntityType type)  = 0;

	virtual ~IEntityCreator() {}
	
};
#endif
