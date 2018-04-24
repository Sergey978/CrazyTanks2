#ifndef IEntity_H
#define IEntity_H
#pragma once
#include"IEntity.h"
#include"Enums.h"

class Entity : public IEntity
{
public:
	Entity();
	void destroy();
	void update();
	void render();
	Body *getBody() const;
	void setBody(Body *value);
	Signal getSignal();
	void setSignal(Signal value);
	void setType(EntityType t);
	EntityType getType();
	std::vector<IEntity *> getTargets();
	void setTargets(std::vector<IEntity *> value);
	std::vector<IEntity *> getGroup();
	void setGroup(std::vector<IEntity *> value);

	virtual ~Entity();
private:
	Body *body;
	EntityType type;
	Signal signal;
	std::vector <IEntity *> targets;
	std::vector <IEntity *> group;

};

#endif