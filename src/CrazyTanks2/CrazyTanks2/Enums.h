#ifndef ENUMS_H
#define ENUMS_H
#pragma once

enum Direction
{
	Right = 0, Down = 1, Left = 2, Up = 3 

};

enum EntityType
{
	TankInst, EnemyTankInst, BulletInst, GoldInst,  WallInst

};

enum Command
{
	Nothing = 0,  left , right , up , down, shoot, pause 

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