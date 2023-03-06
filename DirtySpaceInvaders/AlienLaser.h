#pragma once

#include "GameObject.h"

class PlayField;

class AlienLaser : public GameObject
{
public:
	AlienLaser();
	~AlienLaser();

	void Update(PlayField& world);
};
