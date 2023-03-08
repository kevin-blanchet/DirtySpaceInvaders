#include "PlayerShip.h"

#include <cstring>

#include "Input.h"
#include "PlayerLaser.h"
#include "PlayField.h"

PlayerShip::PlayerShip(): GameObject()
{
	strcpy(m_objType, "PlayerShip");
	sprite = RS_Player;
}

PlayerShip::~PlayerShip()
{
}

void PlayerShip::Update(PlayField& world)
{
	if (world.controllerInput->Left())
	{
		pos.x -= 1;
	}
	else if (world.controllerInput->Right())
	{
		pos.x += 1;
	}

	if (world.controllerInput->Fire() && world.PlayerLasers > 0)
	{
		//Spawn laser
		GameObject* newLaser = new PlayerLaser;
		if (newLaser) {
			newLaser->pos = pos;
			world.SpawnLaser(newLaser);
		}
	}
}