#include "GameObject.h"

GameObject::~GameObject()
{
	delete[] m_objType;
}

void GameObject::Update(PlayField& world)
{
}

bool GameObject::DecreaseHealth()
{
	return true;
}