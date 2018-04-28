#ifndef UNARMED
#define NOWEAUNARMEDPON
#pragma once
#include "IWeapon.h"
#include"Entity.h"

class Unarmed :
	public IWeapon
{
public:
	Unarmed(Entity *ent);
	void shoot();

	virtual ~Unarmed();
private:
	Entity * entity;
};

#endif // !UNARMED