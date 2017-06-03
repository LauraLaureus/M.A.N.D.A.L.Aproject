#include "GameScene.h"



GameScene::GameScene(std::string name)
{
	this->name = name;
	this->entities = *new std::vector<GameEntity*>();
	this->entitiesByName = *new std::unordered_map<std::string, GameEntity*>();
	this->renderinInitialized = false;
}


GameScene::~GameScene()
{
	delete &name;
	delete &entities;
	delete &entitiesByName;
	delete &renderinInitialized;

}

void GameScene::preload()
{
	for (int e = 0; e < this->entities.size(); e++) {
		((Preloader)*(this->entities[e])).preload();
	}
}

void GameScene::initRenderEngine() {

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1, 1, -1, 1, 1, 10);
	gluPerspective(60, 1200 / 768, 1, 50);
	glMatrixMode(GL_MODELVIEW);

	this->renderinInitialized = true;

}

bool GameScene::didInitRendering() {
	return this->renderinInitialized;
}

void GameScene::updateCamera(glm::vec2) {
	
	//TODO: convertir el punto del tobii en movimiento
}

void GameScene::render() {

	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	for (int i = 0; i < this->entities.size(); i++) {
		((Renderizable)*(entities[i])).render();
	}

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();

}

void GameScene::addEntity(GameEntity* newEntity) {
	this->entities.push_back(newEntity);
	this->entitiesByName[newEntity->getName()] = newEntity;
}

void GameScene::removeEntity(GameEntity* toRemove) {
	this->entities.erase(this->entities.begin()+
		std::distance(this->entities.begin(),
			std::find(this->entities.begin(), this->entities.end(), toRemove)
		)
	);
	this->entitiesByName.erase(toRemove->getName());
		
}


std::string GameScene::getName() {
	return this->name;
}

std::string GameScene::update(glm::vec2 gaze) {
	std::string result = this->getName();
	std::string aux;
	for (int i = 0; i < this->entities.size(); i++) {
		aux = entities[i]->update(gaze);
	}
	if (aux != "")  return aux;
	return result;
}

