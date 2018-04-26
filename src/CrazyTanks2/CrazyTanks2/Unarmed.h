#ifndef UNARMED
#define NOWEAUNARMEDPON
#pragma once
#include "IWeapon.h"
#include"IEntity.h"

class Unarmed :
	public IWeapon
{
public:
	Unarmed(IEntity *ent);
	void shoot();

	virtual ~Unarmed();
private:
	IEntity * entity;
};

#endif // !UNARMED