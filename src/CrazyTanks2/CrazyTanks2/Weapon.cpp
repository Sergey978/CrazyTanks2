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
	
	bullet->setTargets(entity->getTargets());
	bullet->setGroup(entity->getGroup());

	bullet->getBody()->setX(entity->getBody()->getX());
	bullet->getBody()->setY(entity->getBody()->getY());
	bullet->getBody()->setDirection(entity->getBody()->getDirection());
	entity->notifyObservers(Signal::CreateEntity, bullet);
	
}

Weapon::~Weapon()
{
}
