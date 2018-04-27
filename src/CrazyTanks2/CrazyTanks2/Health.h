#ifndef HEALTH_H
#define HEALTH_H
#pragma once
#include"IEntity.h"

class IEntity;

class Health 
{
public:
	Health(IEntity *ent);
	void hit(int damage);
	void setHitPoints(int points);
	int getHitpoints();
	~Health();

private:
	IEntity *entity;
	int hitPoints;

};

#endif // !HEALTH_H