#ifndef ENUMS_H
#define ENUMS_H
#pragma once

enum Direction
{
	Right, Down, Left, Up
};

enum EntityType
{
	TankInst, EnemyTankInst, BulletInst, GoldInst,  WallInst
};

enum Command
{
	Nothing,  left , right , up , down, shoot, pause 
};

enum Group
{
	Players, Enemies, Neutrals
};

enum Signal
{
	CreateEntity,
	DestroyEntity,
	HitEntity
};
#endif // !ENUMS_H
