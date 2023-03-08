#pragma once

#include "Laser.h"

class PlayField;

class AlienLaser : public Laser
{
public:
	AlienLaser();
	~AlienLaser() override = default;

	void Update(PlayField& world) override;
};
