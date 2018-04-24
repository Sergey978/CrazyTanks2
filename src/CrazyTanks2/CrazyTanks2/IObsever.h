#ifndef IOBSERVER_H
#define IOBSERVER_H
#pragma once
#include"IEntity.h"
#include"Enums.h"

class IObsever
{
public:
	IObsever();
	virtual void handleEvent(Signal sig, IEntity &sender) = 0;
	virtual ~IObsever();
};

#endif // !IOBSERVER_H