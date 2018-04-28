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
	void render();
	void clear();
	
	virtual ~View();

private:
	Entity *entity;
	char symbol;
	void setCursorPosition();
};

#endif // !IVIEW_H