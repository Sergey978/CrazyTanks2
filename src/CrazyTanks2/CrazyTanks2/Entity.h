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


class Entity : public IEntity, public IObservable
{
public:
	Entity();
	int getId();
	void destroy();
	void update();
	void render();

	EntityType getEntityType();
	void setGroup(Group group);
	Group getGroup();

	Body *getBody() const;
	void setBody(Body *value);
	
	void addObserver(IObserver *o);
	void removeObserver(IObserver *o);
	void notifyObservers(Signal sig, Entity *entity);

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
	void setType(EntityType t);
	EntityType getType();
	std::vector<Group> getTargets();
	void setTargets(std::vector<Group > &value);	

	virtual ~Entity() {   delete weapon; delete physics; };
private:
	int id;
	static int lastId;
	EntityType type;

	Body *body;
	Health *health;
	View *view;
	IControl *control;
	IWeapon *weapon;
	IMovable *physics;
		
	std::vector <Group> targets;
	Group group;
	IObserver * observer;

};

#endif