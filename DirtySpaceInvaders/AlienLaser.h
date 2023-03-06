#pragma once

#include "GameObject.h"

class PlayField;

class AlienLaser : public GameObject
{
public:
	AlienLaser();
	~AlienLaser() override;

	void Update(PlayField& world) override;
};
