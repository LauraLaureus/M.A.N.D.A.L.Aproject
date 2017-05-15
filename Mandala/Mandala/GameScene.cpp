#include "GameScene.h"



GameScene::GameScene()
{
	this->entities = *new std::vector<GameEntity>();
}


GameScene::~GameScene()
{
}

void GameScene::preload()
{
	for (int e = 0; e < this->entities.size(); e++) {
		((Preloader)this->entities[e]).preload();
	}
}
