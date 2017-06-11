#include "GameComponent.h"

void GameComponent::preload() {}

std::string GameComponent::update(glm::vec2 gaze) {
	return "";
}

GameComponent::GameComponent(GameEntity* parent) {
	this->parent = parent;
}

GameComponent::~GameComponent()
{
}
