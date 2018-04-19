#ifndef ENEMYTANKS_H
#define ENEMYTANKS_H
#pragma once
#include "Entity.h"
#include"IView.h"
#include"Physics.h"

class EnemyTank :
	public Entity
{
public:
	EnemyTank();
	IView *getView() const;
	void setView(IView *value);
	void update();
	void onDied(Entity &entity);
	void move();
	void render();
	void setPhysics(IMovable *phys);
	IMovable *getPhysics() const;
	
	virtual ~EnemyTank();
private:
	IMovable *physics;
	IView *view;
};

#endif // !ENEMYTANKS_H