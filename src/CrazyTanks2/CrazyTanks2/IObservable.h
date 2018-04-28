#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H
#pragma once
#include "IObserver.h"


class Entity;

class IObservable
{
public:
	IObservable();
	virtual void addObserver(IObserver *o) = 0;
	virtual void removeObserver(IObserver *o) = 0;
	virtual void notifyObservers(Signal sig, Entity *ent) = 0;
	virtual ~IObservable();
};

#endif // !IOBSERVABLE_H