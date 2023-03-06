#include "PlayerLaser.h"

#include <cstring>

#include "PlayField.h"

PlayerLaser::PlayerLaser()
{
	strcpy(m_objType, "PlayerLaser");
	sprite = RS_PlayerLaser;
}

PlayerLaser::~PlayerLaser()
{
}

void PlayerLaser::Update(PlayField& world)
{
	bool deleted = false;
	pos.y -= 1.f;
	if (pos.y < 0)
	{
		deleted = true;
	}

	if (deleted)
	{
		world.DespawnLaser(this);
	}
}