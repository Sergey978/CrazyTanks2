#include "stdafx.h"
#include "EntityCreator.h"

EntityCreator::EntityCreator()
{
}

Entity *EntityCreator::getEntity(EntityType entName)
{
	Entity *result;
	
	switch (entName)
	{
	case EntityType::BulletInst:
		result = new Bullet();
		break;
	
	case EntityType::EnemyTankInst:
		result = new EnemyTank();
		break;
	
	case EntityType::TankInst:
		result = new Tank();
		break;

	case EntityType::GoldInst:
		result = new Gold();
		break;
			
	case EntityType::WallInst:
		result = new Wall();
		break;
	default:
		result = nullptr;	
	}

	return result;
}



EntityCreator::~EntityCreator()
{
}
