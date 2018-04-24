#pragma once
class IHealth
{
public:
	IHealth();
	virtual void hit(int damage) = 0;
	virtual ~IHealth();
};

