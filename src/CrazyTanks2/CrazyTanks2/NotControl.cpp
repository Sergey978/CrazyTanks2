#include "stdafx.h"
#include "NotControl.h"




NotControl::NotControl(IEntity * entity)
{
	this->entity = entity;
}
// Not command always return nothing command
Command NotControl::getCommand()
{
	return Nothing;
}

NotControl::~NotControl()
{
}
