#ifndef TANK_H
#define TANK_H
#pragma once
#include "Entity.h"
#include "IMovable.h"
#include"IView.h"
#include"Control.h"

class Tank : public Entity
	
{
public:
	Tank();
	IView *getView() const;
	void setView(IView *value);
	void update();
	void onDied(Entity &entity);
	void move();
	void render();
	
	void setPhysics(IMovable *phys);
	IMovable *getPhysics() const;
	//void setControl(Control *contr);
	

	virtual ~Tank();

private:
	
	IMovable *physics;
	IView *view;
	
};

#endif // !TANK_H
