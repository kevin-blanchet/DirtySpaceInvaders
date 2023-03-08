#pragma once

#include "Laser.h"

class PlayField;

class AlienLaser : public Laser
{
public:
	AlienLaser();
	~AlienLaser() override = default;

	void Update(PlayField& world) override;

	void Move(PlayField& world) override;

	void CollisionCheck(PlayField& world) override;
};
