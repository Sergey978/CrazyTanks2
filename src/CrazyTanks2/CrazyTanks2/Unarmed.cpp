#include "stdafx.h"
#include "Unarmed.h"


Unarmed::Unarmed(IEntity *ent)
{
	this->entity = ent;
}

void Unarmed::shoot()
{
	//in class no weapon shoot does nothing
}


Unarmed::~Unarmed()
{
}
