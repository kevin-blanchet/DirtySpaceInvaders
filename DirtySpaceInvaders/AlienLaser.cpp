#include "AlienLaser.h"

#include <cstring>

#include "PlayField.h"

AlienLaser::AlienLaser(): Laser()
{
	strcpy(m_objType, "AlienLaser");
	sprite = RS_AlienLaser;
}

void AlienLaser::Update(PlayField& world)
{
	Laser::Move(world);

	GameObject* player = world.GetPlayerObject();
	if (player) {
		if (pos.IntCmp(player->pos))
		{
			m_deleted = true;
			world.RemoveObject(player);
		}
	}

	Laser::Update(world);
}