#pragma once
#include "RaiderSprites.h"
#include "Vector.h"

class PlayField;

class GameObject
{
public:
	char* m_objType = nullptr;
	Vector2D pos;
	RaiderSprites sprite;

	virtual void Update(PlayField& world)
	{

	}
	bool DecreaseHealth()
	{
		return true;
	}
};
