#include "stdafx.h"
#include "View.h"


View::View(IEntity *ent)
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
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = entity->getBody()->getX();
	Position.Y = entity->getBody()->getY();
	SetConsoleCursorPosition(hOut, Position);

	std::cout << symbol;

	
}


View::~View()
{
}
