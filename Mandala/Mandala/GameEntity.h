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

	std::vector<GameComponent*> components;
	std::vector<GameEntity*> childrenEntities;
	std::string name;

	void preloadChildren();

public:
	Transform transform;

	GameEntity(std::string name);
	~GameEntity();

	std::string getName();

	void preload();
	void update(glm::vec2 gaze);

	void addChild(GameEntity* child);
	void removeChild(GameEntity* child);

	void addComponent(GameComponent* component);
	void removeComponent(GameComponent* component);
};


