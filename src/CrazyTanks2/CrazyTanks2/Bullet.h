#ifndef BULLET_H
#define BULLET_H
#pragma once
#include "Entity.h"
#include"Physics.h"
#include"View.h"
#include"EnemyTank.h"
#include"Gold.h"
#include"Tank.h"
#include"Wall.h"
class Bullet :
	public Entity
{
public:
	Bullet();
	void update();
	virtual ~Bullet();

};

#endif // !BULLET_H