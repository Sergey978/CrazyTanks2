#include "stdafx.h"
#include "Bullet.h"
#include "Game.h"
#include"NotControl.h"
#include"Unarmed.h"


Bullet::Bullet()
{
	
	Body *body = new Body(this);
	
	setBody(body);


	Health *health = new Health(this);
	health->setHitPoints(1);
	setHealth(health);


	View *view = new View(this);
	view->setSymbol('o');
	setView(view);

	setType(EntityType::BulletInst);

	setControl(new NotControl(this));
	setWeapon(new Unarmed(this));
	setPhysics(new Physics(this));
}



void Bullet::update()
{
	Entity::update();

}

void Bullet::onDied()
{
}





Bullet::~Bullet()
{
}
