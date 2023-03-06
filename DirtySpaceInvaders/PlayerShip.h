#pragma once

#include "GameObject.h"

class PlayField;

class PlayerShip : public GameObject
{
public:
	PlayerShip();
	
	~PlayerShip() override;

	void Update(PlayField& world) override;
};
