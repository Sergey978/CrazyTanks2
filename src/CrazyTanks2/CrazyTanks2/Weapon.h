#ifndef WEAPON
#define WEAPON
#pragma once
#include "IWeapon.h"
#include"Entity.h"

class Weapon :
	public IWeapon
{
public:
	Weapon(Entity *ent);
	void shoot();

	~Weapon();
private:
	Entity * entity;
};

#endif // !WEAPON