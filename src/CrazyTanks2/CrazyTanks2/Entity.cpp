#include "stdafx.h"
#include"Entity.h"
#include<map>

int Entity::lastId = 0;

Entity::Entity()
{
	body = new Body(this);
	id = lastId;
	Entity::lastId++;
}

int Entity::getId()
{
	return id;
}

void Entity::destroy()
{
	notifyObservers(Signal::DestroyEntity, this);
}

void Entity::update()
{
	Command command = control->getCommand();

	switch (command)
	{
	case Command::left:
	{
		body->setDirection(Direction::Left);
		break;
	}
	case Command::right:
	{
		body->setDirection(Direction::Right);
		break;
	}
	case Command::up:
	{
		body->setDirection(Direction::Up);
		break;
	}
	case Command::down:
	{
		body->setDirection(Direction::Down);
		break;
	}


	case Command::shoot:
	{
		weapon->shoot();
		return;
	}


	default:
		break;
	}

	
	if (command != Nothing)
	{
		physics->move();

	}


}

void Entity::render()
{
	view->render();
}

Body *Entity::getBody() const
{

	return body;
}

void Entity::setBody(Body *value_)
{
	body = value_;
}

void Entity::addObserver(IObserver *o)
{
	observer = o;
}

void Entity::removeObserver(IObserver *o)
{

}

void Entity::notifyObservers(Signal sig, Entity *entity)
{
	observer->handleEvent(sig, *entity);
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

View * Entity::getView() const
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
	this->weapon = weapon;
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

std::vector<Group> Entity::getTargets()
{
	return targets;
}

void Entity::setTargets(std::vector<Group > &value)
{
	targets = value;
}

Group Entity::getGroup()
{
	return group;
}

EntityType Entity::getEntityType()
{
	return type;;
}

void Entity::setGroup(Group value)
{
	group = value;
}

