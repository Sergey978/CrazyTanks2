#include "stdafx.h"
#include "Unmoved.h"


Unmoved::Unmoved(IEntity *ent)
{
	this->entity = ent;
}

void Unmoved::move(Direction direct)
{
	// in Unmove class method move does nothing
}


Unmoved::~Unmoved()
{
}
