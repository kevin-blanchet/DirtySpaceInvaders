#include "PlayField.h"

#include "GameObject.h"
#include "Input.h"
#include "Vector.h"

void PlayField::DeleteObject(GameObject* newObj)
{
	auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [&](GameObject* in) { return (in == newObj); });
	gameObjects.erase(it);
	delete* it;
}

void PlayField::CreateObject(GameObject* newObj)
{
	gameObjects.push_back(newObj);
}

PlayField::PlayField(const Vector2D& iBounds) : controllerInput(new RndInput), bounds(iBounds)
{}

const std::vector<GameObject*>& PlayField::GameObjects()
{
	return gameObjects;
}

void PlayField::Update()
{
	// Update list of active objects in the world
	for (const auto it : gameObjects)
	{
		it->Update(*this);
	}

	for (const auto it : awaitingDeletion)
	{
		DeleteObject(it);
	}
	awaitingDeletion.clear();

	for (const auto it : awaitingAddition)
	{
		CreateObject(it);
	}
	awaitingDeletion.clear();
}

GameObject* PlayField::GetPlayerObject()
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

void PlayField::SpawnLaser(GameObject* newObj)
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

void PlayField::DespawnLaser(GameObject* newObj)
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

void PlayField::AddObject(GameObject* newObj)
{
	awaitingAddition.push_back(newObj);
}

void PlayField::RemoveObject(GameObject* newObj)
{
	awaitingDeletion.push_back(newObj);
}