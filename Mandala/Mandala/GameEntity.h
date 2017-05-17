#pragma once
#include "SystemHeader.h"
#include "GameComponent.h"
#include "ThreadingHeader.h"
#include "Transform.h"
#include "Preload.h"
#include "Renderizable.h"

class GameEntity: public Preloader, public Renderizable
{
private:

	std::vector<GameComponent> components;
	std::vector<GameEntity> childrenEntities;

	void preloadChildren();

public:
	Transform transform;
	~GameEntity();

	void preload();
};


