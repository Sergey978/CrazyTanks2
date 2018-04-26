#ifndef HEALTH_H
#define HEALTH_H
#pragma once
#include"IEntity.h"
class Health 
{
public:
	Health(IEntity *ent);
	void hit(int damage);
	void setHitPoiints(int points);
	int getHitpoints();
	~Health();

private:
	IEntity *entity;
	int hitPoints;

};

#endif // !HEALTH_H