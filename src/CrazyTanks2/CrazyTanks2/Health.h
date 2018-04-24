#ifndef HEALTH_H
#define HEALTH_H
#pragma once
#include "IHealth.h"
#include"IEntity.h"
class Health :
	public IHealth
{
public:
	Health(IEntity *ent);
	void hit(int damage);
	~Health();

private:
	IEntity *entity;
	int hitPoints;

};

#endif // !HEALTH_H