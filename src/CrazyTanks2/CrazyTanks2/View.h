#ifndef IVIEW_H
#define IVIEW_H
#pragma once

#include <windows.h>
#include <iostream>
#include"IEntity.h"

class View 	
{
public:
	View(IEntity *ent);
	char getSymbol() ;
	void setSymbol(char ch);
	void render();
	void clear();
	
	virtual ~View();

private:
	IEntity *entity;
	char symbol;
	void setCursorPosition();
};

#endif // !IVIEW_H