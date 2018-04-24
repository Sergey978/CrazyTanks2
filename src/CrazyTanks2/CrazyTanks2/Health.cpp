#include "stdafx.h"
#include "Health.h"



Health::Health(IEntity * ent)
{
	entity = ent;
}

void Health::hit(int damage)
{
	if (damage > hitPoints)
		hitPoints = 0;
	else
	{
		hitPoints -= damage;
	}
}

Health::~Health()
{
}
