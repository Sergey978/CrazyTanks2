#include "stdafx.h"
#include "BotControl.h"
#include"Game.h"



BotControl::BotControl(Entity * entity)
{
	this->entity = entity;
}

Command BotControl::getCommand()
{
	//generate command
	Command  command = Nothing;
	if (rand() % Game::CHANCE_ENEMY_ACTION == 1)
	{

		  command = static_cast <Command>(rand() % (shoot + 1));
	}
	
	return command;
}

BotControl::~BotControl()
{
}
