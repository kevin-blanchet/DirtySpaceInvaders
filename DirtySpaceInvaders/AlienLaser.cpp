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
	Laser::Update(world);
}

void AlienLaser::Move(PlayField& world)
{
	Laser::Move(world);
}

void AlienLaser::CollisionCheck(PlayField& world)
{
	Laser::CollisionCheck(world);

	GameObject* player = world.GetPlayerObject();
	if (player) {
		if (pos.IntCmp(player->pos))
		{
			m_deleted = true;
			world.RemoveObject(player);
		}
	}
}
