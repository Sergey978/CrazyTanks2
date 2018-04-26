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

	void setHealth(Health *health);
	Health *getHealth() const;
	void setView(View *view);
	View *getview() const;
	void setControl(IControl *contr);
	IControl *getControl() const;
	void setWeapon(IWeapon *weapon);
	IWeapon *getWeapon() const;
	void setPhysics(IMovable *physics);
	IMovable *getPhysics() const;

	void setType(EntityType t);
	EntityType getType();
	std::vector<IEntity *> getTargets();
	void setTargets(std::vector<IEntity *> value);
	std::vector<IEntity *> getGroup();
	void setGroup(std::vector<IEntity *> value);

	virtual ~Entity();
private:
	Body *body;
	Health *health;
	View *view;
	IControl *control;
	IWeapon *weapon;
	IMovable *physics;

	EntityType type;
	Signal signal;
	std::vector <IEntity *> targets;
	std::vector <IEntity *> group;

};

#endif