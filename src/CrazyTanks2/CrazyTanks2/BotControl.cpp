#include "stdafx.h"
#include "BotControl.h"



BotControl::BotControl(IEntity * entity)
{
	this->entity = entity;
}

Command BotControl::getCommand()
{
	//generate command
	return Command();
}

BotControl::~BotControl()
{
}
