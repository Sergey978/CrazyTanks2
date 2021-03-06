#include "stdafx.h"
#include "EnemyTank.h"
#include "View.h"
#include"Game.h"
#include"BotControl.h"


EnemyTank::EnemyTank()
{
	setType(EntityType::EnemyTankInst);
	Body *body = new Body(this);
	body->setDirection(Up);
	setBody(body);

	Health *health = new Health(this);
	health->setHitPoints(1);
	setHealth(health);


	View *view = new View(this);
	view->setSymbol(char(219));
	view->setColor(11);
	setView(view);


	setControl(new BotControl(this));
	setWeapon(new Weapon(this));
	setPhysics(new Physics(this));

}


void EnemyTank::update()
{
	getView()->clear();
	
	Entity::update();

}


EnemyTank::~EnemyTank()
{
}
