#pragma once
#include "GameEntity.h"
#include "Preload.h"
#include "Renderizable.h"
#include "GraphicsHeader.h"

class GameScene : public Preloader, public Renderizable
{

private:
	std::vector<GameEntity*> entities;

public:
	GameScene();
	~GameScene();
	void preload();
	void initRenderEngine();
	void render();
	void addEntity(GameEntity* newEntity);
};

