#pragma once
#include "GameEntity.h"
#include "Preload.h"
class GameScene : public Preloader
{

private:
	std::vector<GameEntity> entities;

public:
	GameScene();
	~GameScene();
	void preload();
};

