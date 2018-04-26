#pragma once
#ifndef CONTROL_H
#define CONTROL_H
#include "Enums.h"
#include"IEntity.h"
#include"IControl.h"

class PlayerControl: public IControl
{
public:
	PlayerControl(IEntity * entity);
	Command PlayerControl::getCommand();
	virtual ~PlayerControl();
private:
	IEntity * ent;

};


#endif // !CONTROL_H
