#ifndef IWEAPON_H
#define IWEAPON_H


#pragma once
class IWeapon
{
public:
	IWeapon();
	virtual void shoot() = 0;
	virtual ~IWeapon();
};
#endif // !IWEAPON
