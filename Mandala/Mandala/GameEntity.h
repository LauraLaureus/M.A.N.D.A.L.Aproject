#pragma once
#include "SystemHeader.h"
#include "GameComponent.h"
#include "Transform.h"

class GameEntity
{
private:

	std::list<GameComponent> components;
	std::vector<GameEntity*> childrenEntities;

public:
	Transform transform;
	~GameEntity();
};


