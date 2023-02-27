#pragma once
#include <vector>
#include "Vector.h"

class Input;
class GameObject;

class PlayField
{
private:
	std::vector<GameObject*> gameObjects;

public:
	Input* controllerInput;
	Vector2D bounds;

	// Number of available active laser slots for aliens and player
	int AlienLasers = 10;
	int PlayerLasers = 4;

	PlayField(Vector2D iBounds) : bounds(iBounds)
	{

	}

	const std::vector<GameObject*>& GameObjects()
	{
		return gameObjects;
	}

	void Update()
	{
		// Update list of active objects in the world
		for (auto it : gameObjects)
		{
			it->Update(*this);
		}
	}

	GameObject* GetPlayerObject()
	{
		auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [](GameObject* in) { return (strcmp(in->m_objType, "playerShip") == 0); });
		if (it != gameObjects.end())
		{
			return (*it);
		}
		else
		{
			return nullptr;
		}
	}

	void SpawnLaser(GameObject* newObj)
	{
		if (strcmp(newObj->m_objType, "alienLaser") == 0)
		{
			AlienLasers--;
		}

		else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
		{
			PlayerLasers--;
		}

		AddObject(newObj);
	}

	void DespawnLaser(GameObject* newObj)
	{
		if (strcmp(newObj->m_objType, "AlienLaser") == 0)
		{
			AlienLasers++;
		}

		else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
		{
			PlayerLasers++;
		}

		RemoveObject(newObj);
	}

	void AddObject(GameObject* newObj)
	{
		gameObjects.push_back(newObj);
	}

	void RemoveObject(GameObject* newObj)
	{
		auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [&](GameObject* in) { return (in == newObj); });
		delete* it;
		gameObjects.erase(it);
	}
};
