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
	Laser::Update(world);
}

void PlayerLaser::Move(PlayField& world)
{
	Laser::Move(world);
}

void PlayerLaser::CollisionCheck(PlayField& world)
{
	Laser::CollisionCheck(world);
}
