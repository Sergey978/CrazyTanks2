#ifndef IENTITY_H
#define IENTITY_H
#pragma once
#include "stdafx.h"
#include <vector>
#include"Enums.h"
#include"Body.h"


class Body;

class IEntity
{
public:
	
	virtual void destroy() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual Body *getBody() const = 0;
	virtual void setBody(Body *value) = 0;
	virtual std::vector<IEntity *> getTargets() = 0;
	virtual void setTargets(std::vector<IEntity *> value) = 0;
	virtual std::vector<IEntity *> getGroup() = 0;
	virtual void setGroup(std::vector<IEntity *> value) = 0;
	virtual void setType(EntityType t) = 0;
	virtual EntityType getType() = 0;
	
	virtual	~IEntity() {};
};



#endif