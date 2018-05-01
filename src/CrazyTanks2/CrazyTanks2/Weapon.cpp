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
	Entity bullet = *EntityCreator::getEntity(BulletInst);
	std::vector<IEntity *> targets = entity->getTargets();
	bullet.setTargets(targets);
	std::vector<IEntity *> group = entity->getGroup();
	bullet.setGroup(group);

	bullet.getBody()->setX(entity->getBody()->getX());
	bullet.getBody()->setY(entity->getBody()->getY());
	bullet.getBody()->setDirection(entity->getBody()->getDirection());

	entity->setSignal(Signal::CreateEntity);
	entity->setCreatedEntity(&bullet);

	entity->notifyObservers();



}

Weapon::~Weapon()
{
}
