#pragma once
#include "GameEntity.h"
#include "Preload.h"
#include "Renderizable.h"
#include "GraphicsHeader.h"

class GameScene : public Preloader, public Renderizable
{

private:
	std::string name;
	std::vector<GameEntity*> entities;
	std::unordered_map<std::string, GameEntity*> entitiesByName;
	bool renderinInitialized;

public:
	GameScene(std::string sceneName);
	~GameScene();

	void preload();
	void initRenderEngine();
	bool didInitRendering();

	void render();
	void updateCamera(glm::vec2 gaze);

	std::string update(glm::vec2 gaze);

	void addEntity(GameEntity* newEntity);
	void removeEntity(GameEntity* toRemove);

	std::string getName();
};

