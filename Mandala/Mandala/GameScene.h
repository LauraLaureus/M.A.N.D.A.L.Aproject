#pragma once
#include "GameEntity.h"
#include "Preload.h"
#include "Renderizable.h"

class GameScene : public Preloader, public Renderizable
{

private:
	std::vector<GameEntity> entities;

public:
	GameScene();
	~GameScene();
	void preload();
};

