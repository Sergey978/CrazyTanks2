#ifndef GOLD_H
#define GOLD_H
#pragma once
#include "Entity.h"
#include"IView.h"

class Gold :
	public Entity
{
public:
	Gold();
	IView *getView() const;
	void setView(IView *value);
	void update();
	void onDied(Entity &entity);
	void render();

	virtual ~Gold();

private:
	IView *view;
};

#endif // !GOLD_H
