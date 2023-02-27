#pragma once

#include <cstring>

#include "ConsoleRenderer.h"
#include "GameObject.h"


class AlienLaser : public GameObject
{
public:
	AlienLaser()
	{
		m_objType = new char[64];
		strcpy(m_objType, "AlienLaser");
		sprite = RS_AlienLaser;
	}
	~AlienLaser()
	{
		delete[] m_objType;
	}

	void Update(PlayField& world)
	{
		bool deleted = false;
		pos.y += 1.f;
		if (pos.y > world.bounds.y)
		{
			deleted = true;
		}

		GameObject* player = world.GetPlayerObject();
		if (pos.IntCmp(player->pos))
		{
			deleted = true;
			world.RemoveObject(player);
		}

		if (deleted)
		{
			world.DespawnLaser((GameObject*)this);
		}
	}
};