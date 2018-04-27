#ifndef WALL_H
#define WALL_H

#pragma once
#include "Entity.h"



class Wall :
	public Entity
{
public:
	Wall();
	void update();
	void onDied();
	virtual ~Wall();

};


#endif // !WALL_H