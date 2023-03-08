#pragma once
#include <vector>
#include "Vector.h"

class Input;
class GameObject;

class PlayField
{
private:
	std::vector<GameObject*> gameObjects;
	std::vector<GameObject*> awaitingDeletion;
	std::vector<GameObject*> awaitingAddition;

	void DeleteObject(GameObject* newObj);
	void CreateObject(GameObject* newObj);

public:
	Input* controllerInput;
	Vector2D bounds;

	// Number of available active laser slots for aliens and player
	int AlienLasers = 100;
	int PlayerLasers = 40;

	PlayField(const Vector2D& iBounds);

	const std::vector<GameObject*>& GameObjects();

	void Update();

	GameObject* GetPlayerObject();

	void SpawnLaser(GameObject* newObj);

	void DespawnLaser(GameObject* newObj);

	void AddObject(GameObject* newObj);

	void RemoveObject(GameObject* newObj);
};
