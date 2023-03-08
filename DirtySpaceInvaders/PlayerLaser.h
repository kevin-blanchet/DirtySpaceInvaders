#pragma once

#include "Laser.h"

class PlayField;

class PlayerLaser : public Laser
{
public:
	PlayerLaser();
	~PlayerLaser() override = default;

	void Update(PlayField& world) override;
};
