#pragma once
#include <windows.h>
#include <iostream>

class View 	
{
public:
	View(IEntity *ent);
	char getSymbol() ;
	void setSymbol(char ch);
	void render();
	virtual ~View();

private:
	IEntity *entity;
	char symbol;
	
};

