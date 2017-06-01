#include "GameScene.h"



GameScene::GameScene()
{
	this->entities = *new std::vector<GameEntity*>();
}


GameScene::~GameScene()
{
}

void GameScene::preload()
{
	for (int e = 0; e < this->entities.size(); e++) {
		((Preloader)*(this->entities[e])).preload();
	}
}

void GameScene::render() {

	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	for (int i = 0; i < this->entities.size; i++) {
		((Renderizable)*(entities[i])).render();
	}

	glFlush();
	glutSwapBuffers();

}

void GameScene::addEntity(GameEntity* newEntity) {
	this->entities.push_back(newEntity);
}

void GameScene::initRenderEngine() {

	glClearColor(0.0,0.0,0.0,0.0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1,1,-1,1,1,10);
	glMatrixMode(GL_MODELVIEW);

}