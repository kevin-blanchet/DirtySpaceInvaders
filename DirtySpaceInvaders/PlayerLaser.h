#pragma once

#include "GameObject.h"

class PlayField;

class PlayerLaser : public GameObject
{
public:
	PlayerLaser();
	~PlayerLaser();

	void Update(PlayField& world);
};
