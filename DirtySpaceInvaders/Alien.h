#pragma once

#include "GameObject.h"

class PlayField;

class Alien : public GameObject
{
public:
	Alien();
	~Alien() override = default;

private:
	float health = 1.f;
	float energy = 0.f;
	float direction = 1.f;
	float velocity = 0.5f;

	bool DecreaseHealth() override;

	void Update(PlayField& world) override;
};
