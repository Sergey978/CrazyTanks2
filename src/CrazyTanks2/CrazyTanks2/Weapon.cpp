#include "stdafx.h"
#include "Weapon.h"
#include "Bullet.h"
#include"EntityCreator.h"



Weapon::Weapon(Entity * ent)
{
	entity = ent;
}

void Weapon::shoot()
{
	Entity *bullet =  EntityCreator::getEntity(BulletInst);
	std::vector<IEntity *> targets = entity->getTargets();
	bullet->setTargets(targets);
	bullet->getBody()->setX(entity->getBody()->getX());
	bullet->getBody()->setY(entity->getBody()->getY());
	bullet->getBody()->setDirection(entity->getBody()->getDirection());

	
	

	
}

Weapon::~Weapon()
{
}
