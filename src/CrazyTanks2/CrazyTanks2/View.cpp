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

void View::setColor(int chooseColor)
{
	color_ = chooseColor;
}

void View::render()
{
	choseColor_(color_);
	setCursorPosition();
	std::cout << symbol;
	forgetColor_();
	
}

void View::clear()
{
	forgetColor_();
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



void View::choseColor_(int choosecolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), choosecolor); //FUNCTION OF COLOR
}

void View::forgetColor_()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	//FUNCTION TO ..EHM FORGET COLOR,not sure how to say I know: Stop using color
}


View::~View()
{
}
