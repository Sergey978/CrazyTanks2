#pragma once


struct Position
	{
		enum Direction
		{
			Left, Right, Up, Down

		};

		int x;
		int y;
		Direction direction;
		int length;

	};



class IGameObject
{
	

public:
	virtual void setPosition(Position position  ) = 0;
	virtual Position getPosition() = 0;
	virtual Position generatePosition(int maxX, int maxY, int maxLength) = 0;
	virtual void draw() = 0;

	IGameObject();
	~IGameObject();
};

