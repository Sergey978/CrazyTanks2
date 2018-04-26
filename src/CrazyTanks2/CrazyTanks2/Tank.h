#ifndef TANK_H
#define TANK_H
#pragma once
#include "Entity.h"
#include"PlayerControl.h"
#include"Weapon.h"

class Tank : public Entity
	
{
public:
	Tank();	
	void update();
	void onDied();
	virtual ~Tank();
	
};

#endif // !TANK_H
