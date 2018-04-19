#pragma once
#include "IView.h"
#include <windows.h>
#include <iostream>

class View :
	public IView
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

