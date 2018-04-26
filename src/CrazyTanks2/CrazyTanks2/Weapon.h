#pragma once
#include "IWeapon.h"
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

