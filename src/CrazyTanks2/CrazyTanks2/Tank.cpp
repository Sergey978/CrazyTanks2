#include "stdafx.h"
#include "Tank.h"


Tank::Tank()
{
	setType(EntityType::TankInst);
	Body *body = new Body(this);
	body->setDirection(Up);
	setBody(body);


	Health *health = new Health(this);	
	setHealth(health);


	View *view = new View(this);
	view->setSymbol(char(219));
	view->setColor(4);
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
