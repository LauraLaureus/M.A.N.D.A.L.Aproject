#pragma once
#include "GameEntity.h"
class GameScene
{

private:
	std::list<GameEntity> entities;

public:
	GameScene();
	~GameScene();
};

