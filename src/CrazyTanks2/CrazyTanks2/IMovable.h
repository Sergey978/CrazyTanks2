#ifndef IMOVABLE_H
#define IMOVABLE_H
#pragma once
#include"Enums.h"


class IMovable
{
public:
	IMovable();
	virtual void move() = 0;
	virtual ~IMovable();
};
#endif // !IMOVABLE_H
