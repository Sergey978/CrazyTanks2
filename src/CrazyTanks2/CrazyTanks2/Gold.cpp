#include "stdafx.h"
#include "Gold.h"
#include "View.h"


Gold::Gold()
{
	Body *body = new Body(this);
	body->setX(1);
	body->setY(1);
	body->setDirection(Up);
	setBody(body);

	view = new View(this);
	view->setSymbol('2');
}

IView * Gold::getView() const
{
	return view;
}

void Gold::setView(IView * value)
{
	view = value;
}

void Gold::update()
{
}

void Gold::onDied(Entity & entity)
{
}

void Gold::render()
{
	view->render();
}



Gold::~Gold()
{
}
