#include "Alien.h"

#include <cstring>

#include "AlienLaser.h"
#include "PlayField.h"
#include "Random.h"

Alien::Alien(): GameObject()
{
	strcpy(m_objType, "AlienShip");
	sprite = RS_Alien;
}

Alien::~Alien()
{
}

bool Alien::DecreaseHealth()
{
	health -= 1.f;
	return health <= 0;
}

void Alien::Update(PlayField& world)
{
	pos.x += direction * velocity;
	// Border check
	if (pos.x < 0 || pos.x >= world.bounds.x - 1)
	{
		direction = -direction;
		pos.y += 1;
	}

	// Border check vertical:
	if (pos.y >= world.bounds.y - 1)
	{
		// kill player
		GameObject* player = world.GetPlayerObject();
		if (player) {
			if (pos.IntCmp(player->pos))
			{
				world.RemoveObject(player);
			}
		}
	}

	floatRand fireRate(0, 1);
	if (fireRate(rGen) < 0.5 && world.AlienLasers > 0)
	{
		//Spawn laser
		GameObject& newLaser = *(new AlienLaser);
		newLaser.pos = pos;
		world.SpawnLaser(&newLaser);
	}
}