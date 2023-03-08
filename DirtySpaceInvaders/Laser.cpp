#include "Laser.h"

#include "PlayField.h"

Laser::Laser(): GameObject(), m_deleted(false), m_direction(1.f), m_speed(1.f)
{
}

void Laser::Update(PlayField& world)
{
	Move(world);

	CollisionCheck(world);

	if (m_deleted)
	{
		world.DespawnLaser(this);
	}
}

void Laser::Move(PlayField& world)
{
	pos.y += m_direction;
	if (pos.y < 0 || pos.y > world.bounds.y)
	{
		m_deleted = true;
	}
}

void Laser::CollisionCheck(PlayField& world)
{

}
