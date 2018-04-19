#ifndef IEntity_H
#define IEntity_H
#pragma once
#include"IEntity.h"
#include"Enums.h"


using namespace std;
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
	vector<IEntity *> getTargets();
	void setTargets(vector<IEntity *> value);
	vector<IEntity *> getGroup();
	void setGroup(vector<IEntity *> value);

	virtual ~Entity();
private:
	Body *body;
	Signal signal;
	vector <IEntity *>targets;
	vector <IEntity *>group;

};

#endif