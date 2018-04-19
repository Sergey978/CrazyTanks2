#pragma once
#ifndef VIEW_H
#define VIEW_H
#include"Entity.h"

class IView
{
public:
	IView();
	virtual char getSymbol() = 0;
	virtual void setSymbol(char ch) = 0;
	virtual void render() = 0;
	virtual ~IView();
};

#endif // !VIEW_H