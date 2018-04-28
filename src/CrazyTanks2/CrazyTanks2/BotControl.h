#ifndef BOTCONTROL_H
#define BOTCONTROL_H
#pragma once
#include "IControl.h"
#include"Entity.h"

class BotControl :
	public IControl
{
public:
	BotControl(Entity * entity);
	Command getCommand();

	virtual ~BotControl();
private:
	Entity * entity;
};

#endif // !BOTCONTROL_H