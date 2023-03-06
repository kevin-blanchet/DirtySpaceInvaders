#include "GameObject.h"

GameObject::GameObject(): m_objType(new char[64]), pos({0,0}), sprite(RS_BackgroundTile)
{
}

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