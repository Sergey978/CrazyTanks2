#include "stdafx.h"
#include "Wall.h"
#include"View.h"


Wall::Wall()
{
	Body *body = new Body(this);
	body->setX(20);
	body->setY(20);
	body->setDirection(Up);
	setBody(body);

	view = new View(this);
	view->setSymbol('1');
}

Wall::Wall(int x, int y):Wall()
{
	getBody()->setX(x);
	getBody()->setY(y);
}

IView * Wall::getView() const
{
	return view;
}

void Wall::setView(IView * value)
{
	view = value;
}

void Wall::update()
{
}

void Wall::onDied(Entity & entity)
{
}

void Wall::render()
{
	view->render();
}


Wall::~Wall()
{
}
