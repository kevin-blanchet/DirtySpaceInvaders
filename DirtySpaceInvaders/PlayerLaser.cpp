#include "PlayerLaser.h"

#include <cstring>

#include "PlayField.h"

PlayerLaser::PlayerLaser(): Laser()
{
	m_direction = -1.f;
	strcpy(m_objType, "PlayerLaser");
	sprite = RS_PlayerLaser;
}

void PlayerLaser::Update(PlayField& world)
{
	Laser::Move(world);

	Laser::Update(world);
}