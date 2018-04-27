#include "stdafx.h"
#include"Entity.h"
#include"Body.h"




Entity::Entity()
{
	body = new Body(this);
}

void Entity::destroy()
{
}

void Entity::update()
{
	
}

void Entity::render()
{
	
}

 Body *Entity::getBody() const 
{
	
	return body;
}


void Entity::setBody(Body *value_)
{
	body = value_;
}

Signal Entity::getSignal()
{
	return Signal();
}

void Entity::setSignal(Signal value)
{
}

void Entity::setHealth(Health * health)
{
	this->health = health;
}

Health * Entity::getHealth() const
{
	return health;
}

void Entity::setView(View * view)
{
	this->view = view;
}

View * Entity::getview() const
{
	return view;
}

void Entity::setControl(IControl *contr)
{
	this->control = contr;
}

IControl * Entity::getControl() const
{
	return control;
}

void Entity::setWeapon(IWeapon * weapon)
{
	this -> weapon = weapon;
}

IWeapon * Entity::getWeapon() const
{
	return weapon;
}

void Entity::setPhysics(IMovable * physics)
{
	this->physics = physics;
}

IMovable *Entity::getPhysics() const
{
	return physics;
}

void Entity::setType(EntityType t)
{
	type = t;
}

EntityType Entity::getType()
{
	return type;
}

std::vector<IEntity *> Entity::getTargets()
{
	return targets;
}

void Entity::setTargets(std::vector<IEntity *> value)
{
	targets = value;
}

std::vector<IEntity*> Entity::getGroup()
{
	return group;
}

void Entity::setGroup(std::vector<IEntity*> value)
{
	group = value;
}

Entity::~Entity()
{
}

