#ifndef IEntity_H
#define IEntity_H
#pragma once
#include "IEntity.h"
#include"Enums.h"
#include"IObservable.h"
#include"IObserver.h"
#include"Body.h"
#include"Health.h"
#include"View.h"
#include "IControl.h"
#include"IWeapon.h"
#include"IMovable.h"

class Game;

class Entity : public IEntity, public IObservable
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

	void addObserver(IObserver *o) override;
	void removeObserver(IObserver *o) override;
	void notifyObservers() override;

	void setHealth(Health *health);
	Health *getHealth() const;
	void setView(View *view);
	View *getView() const;
	void setControl(IControl *contr);
	IControl *getControl() const;
	void setWeapon(IWeapon *weapon);
	IWeapon *getWeapon() const;
	void setPhysics(IMovable *physics);
	IMovable *getPhysics() const;
	Entity *getCreatedEntity() const;
	void   setCreatedEntity(Entity *ent);

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

	Entity * createdEntity;
	std::vector <IEntity *> targets;
	std::vector <IEntity *> group;
	std::vector <IObserver *> observers;

};

#endif