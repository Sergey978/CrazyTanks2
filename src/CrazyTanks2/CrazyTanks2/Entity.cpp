#include "stdafx.h"
#include"Entity.h"
#include"Game.h"





Entity::Entity()
{
	body = new Body(this);
}

void Entity::destroy()
{
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
	}


	default:
		break;
	}

	int oldX_ = this->getBody()->getX();
	int	oldY_ = this->getBody()->getY();

	

	if (command != Nothing )
	{
		physics->move();

	}




	//testCollision with other Entities
	bool isCollision = false;

	std::vector<IEntity *> otherEntities;
	otherEntities = getTargets();
	std::vector<IEntity *> group = getGroup();
	otherEntities.insert(otherEntities.end(), group.begin(), group.end());

	for each (Entity *ent in otherEntities)
	{
		//skip check colision with yourself
		if (ent != this)
		{
			if (getBody()->testCollision(*ent))
			{
				isCollision = true;
			}

		}

	}

	if (isCollision)
	{
		body->setX(oldX_);
		body->setY(oldY_);
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

Signal Entity::getSignal()
{
	return Signal();
}

void Entity::setSignal(Signal value)
{
}

void Entity::addObserver(IObserver *o)
{
	observers.push_back(o);
}

void Entity::removeObserver(IObserver *o)
{
	
}

void Entity::notifyObservers()
{
	
	
	std::vector<IObserver *>::iterator iter;

	iter = observers.begin();
	while (iter != observers.end())
	{
		(*iter)->handleEvent(signal, createdEntity);
		iter++;
	}
		
	
	
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

Entity * Entity::getCreatedEntity() const
{
	return this->createdEntity;
}

void Entity::setCreatedEntity(Entity * ent)
{
	this->createdEntity = ent;
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

