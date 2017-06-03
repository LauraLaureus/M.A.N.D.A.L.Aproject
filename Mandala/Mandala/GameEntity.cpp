#include "GameEntity.h"



void GameEntity::preloadChildren()
{
	for (int c = 0; c < this->childrenEntities.size(); c++) {
		((Preloader)(this->childrenEntities[c])).preload();
	}
}

GameEntity::GameEntity(std::string name) {
	this->name = name;
}

GameEntity::~GameEntity()
{
	delete &components;
	delete &childrenEntities;
}

void GameEntity::preload()
{
	std::thread childrenLoader(&GameEntity::preloadChildren,this);
	
	for (int c = 0; c < this->components.size(); c++) {
		((Preloader)this->components[c]).preload();
	}

	childrenLoader.join();
}


std::string GameEntity::getName() {
	return this->name;
}

void GameEntity::update(glm::vec2 gaze) {

	for (int i = 0; i < childrenEntities.size; i++) {
		childrenEntities[i]->update(gaze);
	}

	for (int i = 0; i < components.size; i++) {
		components[i]->update(gaze);
	}
}

void GameEntity::addChild(GameEntity* child) {
	this->childrenEntities.push_back(child);
}

void GameEntity::removeChild(GameEntity* child) {
	this->childrenEntities.erase(
		this->childrenEntities.begin() +
		std::distance(
			this->childrenEntities.begin(),
			std::find(
				this->childrenEntities.begin(),
				this->childrenEntities.end(),
				child)
		)
	);
}

void GameEntity::addComponent(GameComponent* component) {
	this->components.push_back(component);
}

void GameEntity::removeComponent(GameComponent* component) {
	this->components.erase(
		this->components.begin() +
		std::distance(
			this->components.begin(),
			std::find(
				this->components.begin(),
				this->components.end(),
				component
			)
		)
	);
}
