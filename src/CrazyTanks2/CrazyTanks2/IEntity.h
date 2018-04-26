#ifndef IENTITY_H
#define IENTITY_H
#pragma once
#include "stdafx.h"
#include <vector>
#include"Enums.h"
#include"Body.h"
#include"Health.h"
#include"View.h"
#include"IControl.h"
#include "IWeapon.h"
#include"IMovable.h"

class Body;

class IEntity
{
public:

	virtual void destroy() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual Body *getBody() const = 0;
	virtual void setBody(Body *value) = 0;
	virtual void setHealth(Health *health)  = 0;
	virtual Health *getHealth() const = 0;
	virtual void setView(View *view) = 0;
	virtual View *getview() const  = 0;
	virtual void setControl(IControl *contr) = 0;
	virtual IControl *getControl() const = 0;
	virtual void setWeapon(IWeapon *weapon) = 0;
	virtual IWeapon *getWeapon() const  = 0;
	virtual void setPhysics(IMovable *physics) = 0;
	virtual IMovable *getPhysics() const = 0;

	virtual std::vector<IEntity *> getTargets() = 0;
	virtual void setTargets(std::vector<IEntity *> value) = 0;
	virtual std::vector<IEntity *> getGroup() = 0;
	virtual void setGroup(std::vector<IEntity *> value) = 0;
	virtual void setType(EntityType t) = 0;
	virtual EntityType getType() = 0;

	virtual	~IEntity() {};
};



#endif