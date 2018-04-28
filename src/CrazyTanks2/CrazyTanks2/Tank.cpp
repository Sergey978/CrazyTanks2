#include "stdafx.h"
#include "Tank.h"


Tank::Tank()
{
	Body *body = new Body(this);
	body->setDirection(Up);
	setBody(body);


	Health *health = new Health(this);
	health->setHitPoints(3);
	setHealth(health);


	View *view = new View(this);
	view->setSymbol('#');
	setView(view);


	setControl(new PlayerControl(this));
	setWeapon(new Weapon(this));
	setPhysics(new Physics(this));

	

}

void Tank::update()
{

	getView()->clear();
	Entity::update();

	


}

void Tank::onDied()
{
}



Tank::~Tank()
{
}
