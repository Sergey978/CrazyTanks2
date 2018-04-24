#ifndef IOBSERVABLE_H
#define IOBSERVABLE_H
#pragma once
#include "Game.h"

class IObservable
{
public:
	IObservable();
	virtual void addObserver(Game &o) = 0;
	virtual void removeObserver(Game &o) = 0;
	virtual void notifyObservers() = 0;
	virtual ~IObservable();
};

#endif // !IOBSERVABLE_H