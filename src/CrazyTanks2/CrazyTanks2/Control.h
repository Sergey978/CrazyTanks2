#pragma once
#ifndef CONTROL_H
#define CONTROL_H
#include "Enums.h"

class Control
{
public:
	Control();
	static KeyPressed Control::getKey();
	~Control();


};


#endif // !CONTROL_H
