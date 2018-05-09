#include "stdafx.h"
#include "Wall.h"
#include"View.h"
#include "Unarmed.h"
#include"Unmoved.h"
#include"NotControl.h"


Wall::Wall()
{
	setType(EntityType::WallInst);
	Body *body = new Body(this);
	body->setDirection(Up);
	setBody(body);


	Health *health = new Health(this);
	health->setHitPoints(1);
	setHealth(health);


	View *view = new View(this);
	view->setSymbol('1');
	setView(view);


	setControl(new NotControl(this));
	setWeapon(new Unarmed(this));
	setPhysics(new Unmoved(this));
}

void Wall::update()
{
}

void Wall::onDied()
{
}



Wall::~Wall()
{
}
