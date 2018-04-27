#ifndef ENEMYTANKS_H
#define ENEMYTANKS_H
#pragma once
#include "Entity.h"
#include"Physics.h"

class EnemyTank :
	public Entity
{
public:
	EnemyTank();

	void update();
	void onDied();
		
	virtual ~EnemyTank();
};

#endif // !ENEMYTANKS_H