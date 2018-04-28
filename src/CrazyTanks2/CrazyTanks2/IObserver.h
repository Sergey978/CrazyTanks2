#ifndef IOBSERVER_H
#define IOBSERVER_H
#pragma once
#include"Enums.h"

class Entity;
class IObserver
{
public:
	IObserver();
	virtual void handleEvent(Signal sig, Entity &sender) = 0;
	virtual ~IObserver();
};

#endif // !IOBSERVER_H