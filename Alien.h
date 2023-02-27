#pragma once
#include <cstring>

#include "AlienLaser.h"
#include "GameObject.h"
#include "Random.h"


class Alien : public GameObject
{
public:
	Alien()
	{
		m_objType = new char[64];
		strcpy(m_objType, "AlienShip");
		sprite = RS_Alien;
	}
	~Alien()
	{
		delete m_objType;
	}

private:
	float health = 1.f;
	float energy = 0.f;
	float direction = 1.f;
	float velocity = 0.5f;

	bool DecreaseHealth()
	{
		health -= 1.f;
		return health <= 0;
	}

	void Update(PlayField& world)
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
			if (pos.IntCmp(player->pos))
			{
				world.RemoveObject(player);
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
};
