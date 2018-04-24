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
	IView *getView() const;
	void setView(IView *value);
	void update();
	void onDied(Entity &entity);
	void render();

	void setPhysics(IMovable *phys);
	IMovable *getPhysics() const;
	virtual ~Bullet();

private :
	IMovable *physics;
	IView *view;
};

#endif // !BULLET_H