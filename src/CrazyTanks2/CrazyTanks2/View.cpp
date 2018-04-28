#include "stdafx.h"
#include "View.h"


View::View(Entity *ent)
{
	this->entity = ent;
}

char View::getSymbol()
{
	return symbol;
}

void View::setSymbol(char ch)
{
	symbol = ch;
}

void View::render()
{
	
	setCursorPosition();
	std::cout << symbol;

	
}

void View::clear()
{
	setCursorPosition();
	std::cout << ' ';
}

void View::setCursorPosition()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = entity->getBody()->getX();
	Position.Y = entity->getBody()->getY();
	SetConsoleCursorPosition(hOut, Position);
}


View::~View()
{
}
