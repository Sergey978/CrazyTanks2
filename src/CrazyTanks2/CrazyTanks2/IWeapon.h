#pragma once
class IWeapon
{
public:
	IWeapon();
	virtual void shoot() = 0;
	virtual ~IWeapon();
};

