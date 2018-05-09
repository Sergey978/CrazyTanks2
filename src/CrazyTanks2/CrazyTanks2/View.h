#ifndef IVIEW_H
#define IVIEW_H
#pragma once

#include <windows.h>
#include <iostream>
#include"Entity.h"

class View 	
{
public:
	View(Entity *ent);
	char getSymbol() ;
	void setSymbol(char ch);
	void setColor(int choosecolor);
	void render();
	void clear();
	
	virtual ~View();

private:
	Entity *entity;
	char symbol;
	int color_;
	void setCursorPosition();
	
	void choseColor_(int choosecolor);

	void forgetColor_();
};

#endif // !IVIEW_H