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

IEntity * EntityCreator::newTank()
{
	return nullptr;
}

IEntity * EntityCreator::newEnemyTank()
{
	return nullptr;
}

IEntity * EntityCreator::newBullet()
{
	return nullptr;
}

IEntity * EntityCreator::newWall()
{
	return nullptr;
}

IEntity * EntityCreator::newGold()
{
	return nullptr;
}


EntityCreator::~EntityCreator()
{
}
