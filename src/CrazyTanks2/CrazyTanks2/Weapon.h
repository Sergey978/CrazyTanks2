#ifndef WEAPON
#define WEAPON
#pragma once
#include "IWeapon.h"
#include"IEntity.h"

class Weapon :
	public IWeapon
{
public:
	Weapon(IEntity *ent);
	void shoot();

	~Weapon();
private:
	IEntity * entity;
};

#endif // !WEAPON