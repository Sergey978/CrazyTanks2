#include "stdafx.h"
#include "PlayerControl.h"
#include <conio.h>



PlayerControl::PlayerControl(Entity * entity)
{
	ent = entity;
}

 Command PlayerControl::getCommand()
{
	 
	 Command keyP_ = Nothing;

	if (_kbhit()) //If player clicks something

	{
		int key = _getch();

		switch (key)

		{
		case 72:
		{
			keyP_ = up;
			break;
		}

		case 80:
		{
			keyP_ = down;
			break;
		}

		case 75:
		{
			keyP_ = left;
			break;
		}

		case 77:
		{
			keyP_ = right;
			break;
		}
		case 32:
		{
			keyP_ = shoot;
			break;
		}


		default:
		{
		}


		}
	}

	return keyP_;
}


PlayerControl::~PlayerControl()
{
}
