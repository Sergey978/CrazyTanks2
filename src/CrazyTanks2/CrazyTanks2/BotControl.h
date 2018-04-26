#ifndef BOTCONTROL_H
#define BOTCONTROL_H
#pragma once
#include "IControl.h"
#include"IEntity.h"

class BotControl :
	public IControl
{
public:
	BotControl(IEntity * entity);
	Command getCommand();

	virtual ~BotControl();
private:
	IEntity * entity;
};

#endif // !BOTCONTROL_H