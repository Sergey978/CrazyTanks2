#ifndef NOTCONTROL_H
#define NOTCONTROL_H
#pragma once
#include "IControl.h"
#include"IEntity.h"

class NotControl :
	public IControl
{
public:
	NotControl(IEntity * entity);
	Command getCommand();

	virtual ~NotControl();
private:
	IEntity * entity;
};

#endif // !NOTCONTROL_H