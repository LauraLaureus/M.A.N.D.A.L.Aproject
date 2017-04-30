#pragma once
#include "SystemHeader.h"
#include "GameComponent.h"


class GameEntity
{
private:

	std::list<GameComponent> components;

public:
	
	~GameEntity();
};


