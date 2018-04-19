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

vector<IEntity *> Entity::getTargets()
{
	return targets;
}

void Entity::setTargets(vector<IEntity *> value)
{
	targets = value;
}

vector<IEntity*> Entity::getGroup()
{
	return group;
}

void Entity::setGroup(vector<IEntity*> value)
{
	group = value;
}

Entity::~Entity()
{
}

