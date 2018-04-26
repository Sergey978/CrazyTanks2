#ifndef ICONTROL_H
#define ICONTROL_H
#pragma once
#include "Enums.h"
class IControl
{
public:
	IControl();
	virtual Command getCommand() = 0;
	virtual ~IControl();
};

#endif // !ICONTROL_H