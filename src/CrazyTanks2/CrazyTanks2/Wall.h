#ifndef WALL_H
#define WALL_H

#pragma once
#include "Entity.h"
#include"IView.h"


class Wall :
	public Entity
{
public:
	Wall();
	Wall(int x, int y);
	IView *getView() const;
	void setView(IView *value);
	void update();
	void onDied(Entity &entity);
	void render();
	virtual ~Wall();
private:
	IView *view;
};


#endif // !WALL_H