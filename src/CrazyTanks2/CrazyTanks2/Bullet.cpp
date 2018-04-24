#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
	Body *body = new Body(this);

	body->setDirection(Up);
	setBody(body);

	view = new View(this);
	view->setSymbol('o');

	//setView(view);
	physics = new Physics(this);
}



void Bullet::update()
{
	view->setSymbol(' ');//clear old position
	render();

	Direction direct = getBody()->getDirection();

	int oldX_ = this->getBody()->getX();
	int	oldY_ = this->getBody()->getY();

	physics->move(direct);

	bool movePosible = true;
	std::vector<IEntity *> targets;
	targets = getTargets();


	for each (IEntity *ent in getTargets())
	{

		if (getBody()->testCollision(*ent))
		{
			movePosible = false;
			EntityType type = ent->getType();

			switch (type)
			{
			case EntityType::GoldInst:
			{
				static_cast<Gold *>(ent)->destroy();
				break;
			}

			case EntityType::EnemyTankInst:
			{
				static_cast<EnemyTank *>(ent)->destroy();
				break;
			}

			case EntityType::TankInst:
			{
				static_cast<Tank *>(ent)->getHealth()->hit(1);
				break;
			}

			case EntityType::WallInst:
			{
				static_cast<Wall *>(ent)->destroy();
				break;
			}

			case EntityType::BulletInst:
			{
				static_cast<Bullet *>(ent)->destroy();
				break;
			}
			default:
				break;
			}
		}


	}

	std::vector<IEntity *> group = getGroup();




	int newX_ = this->getBody()->getX();
	int	newY_ = this->getBody()->getY();


	if (newX_ >= 30 || newX_ == 0 || newY_ >= 30 || newY_ == 0)
	{
		movePosible = false;
	}

	if (movePosible == false)
	{
		//destroy this bullet
		// notify observer
	}

	view->setSymbol('o'); //set symbol in new position

}

void Bullet::onDied(Entity & entity)
{
}

void Bullet::render()
{

	view->render();
}

void Bullet::setView(IView *view_)
{
	view = view_;
}

IView *Bullet::getView() const
{
	return view;
}



void Bullet::setPhysics(IMovable * phys)
{
	physics = phys;
}

IMovable * Bullet::getPhysics() const
{
	return physics;
}



Bullet::~Bullet()
{
}
