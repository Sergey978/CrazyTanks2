#pragma once

enum Direction
{
	Left, Right, Up, Down

};

enum EntityType
{
	TankInst, EnemyTankInst, BulletInst, GoldInst,  WallInst

};

enum KeyPressed
{
	Nothing = 0, Enter = 1, space = 2, left = 3, right = 4, up = 5, down = 6

};

enum Signal
{
	CreateEntity,
	DestroyEntity
};
