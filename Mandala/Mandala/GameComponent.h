#pragma once
#include "Preload.h"
#include "Renderizable.h"
#include "GameDataStructures.h"

class GameEntity;

class GameComponent: public Preloader, public Renderizable
{
protected:
	GameEntity* parent;

public:
	

	GameComponent(GameEntity* parent);
	~GameComponent();

	virtual void preload();
	std::string update(glm::vec2 gaze);

};

