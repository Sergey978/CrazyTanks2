#include "stdafx.h"
#include "Gold.h"
#include "View.h"


Gold::Gold()
{
	setType(EntityType::GoldInst);
	Body *body = new Body(this);
	
	body->setDirection(Up);
	setBody(body);

	Health *health = new Health(this);	
	setHealth(health);


	View *view = new View(this);
	view->setSymbol(char(219));
	view->setColor(14);
	setView(view);
}


void Gold::update()
{
}

void Gold::onDied()
{
}


Gold::~Gold()
{
}
