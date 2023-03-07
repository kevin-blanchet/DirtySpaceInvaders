#pragma once

#include "GameObject.h"

class PlayField;

class PlayerLaser : public GameObject
{
public:
	PlayerLaser();
	~PlayerLaser() override;

	void Update(PlayField& world) override;
};
