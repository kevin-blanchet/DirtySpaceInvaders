#pragma once
#include <cstring>

#include "ConsoleRenderer.h"
#include "GameObject.h"

class PlayerLaser : public GameObject
{
public:
	PlayerLaser()
	{
		m_objType = new char[64];
		strcpy(m_objType, "PlayerLaser");
		sprite = RS_PlayerLaser;
	}
	~PlayerLaser()
	{
		delete[] m_objType;
	}

	void Update(PlayField& world)
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
			delete this;
		}
	}
};
