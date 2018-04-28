#ifndef NOTCONTROL_H
#define NOTCONTROL_H
#pragma once
#include "IControl.h"
#include"Entity.h"

class NotControl :
	public IControl
{
public:
	NotControl(Entity * entity);
	Command getCommand();

	virtual ~NotControl();
private:
	Entity * entity;
};

#endif // !NOTCONTROL_H