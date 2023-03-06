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

	virtual ~GameObject();

	virtual void Update(PlayField& world);

	virtual bool DecreaseHealth();
};
