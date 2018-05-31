#include "stdafx.h"
#include "Bullet.h"
#include "Game.h"
#include"NotControl.h"
#include"Unarmed.h"

Bullet::Bullet()
{
	setType( EntityType::BulletInst);
	Body *body = new Body(this);
	body->setDirection(Up);
	body->setDamage(1);
	setBody(body);

	Health *health = new Health(this);
	health->setHitPoints(1);
	setHealth(health);

	View *view = new View(this);
	view->setSymbol('o');
	view->setColor(15);
	setView(view);

	setControl(new NotControl(this));
	setWeapon(new Unarmed(this));
	setPhysics(new Physics(this));
}

void Bullet::update()
{
	getView()->clear();
	int oldX_ = this->getBody()->getX();
	int	oldY_ = this->getBody()->getY();

	getPhysics()->move();
	
	// if border of field
	if (oldX_ == getBody()->getX() && oldY_ == getBody()->getY())
	{
		notifyObservers(Signal::DestroyEntity, this);
	}

}

Bullet::~Bullet()
{
}
