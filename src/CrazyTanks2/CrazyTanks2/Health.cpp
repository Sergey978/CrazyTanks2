#include "stdafx.h"
#include "Health.h"



Health::Health(Entity * ent)
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

void Health::setHitPoints(int points)
{
	hitPoints = points;
}

int Health::getHitpoints()
{
	return hitPoints;
}

Health::~Health()
{
}
