#include "stdafx.h"
#include "EntityCreator.h"
#


EntityCreator::EntityCreator()
{
}

IEntity *EntityCreator::getEntity(EntityType entName)
{

	switch (entName)
	{
	case EntityType::BulletInst:
	{
		return new Bullet();

	}
	case EntityType::EnemyTankInst:
	{
		return new EnemyTank();

	}

	case EntityType::TankInst:
	{
		return new Tank();
	}

	case EntityType::GoldInst:
	{
		return new Gold();
	}
	case EntityType::WallInst:
	{
		return new Wall();
	}



	}

	return nullptr;
}



EntityCreator::~EntityCreator()
{
}
