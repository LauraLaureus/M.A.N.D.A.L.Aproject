#include "GameEntity.h"



void GameEntity::preloadChildren()
{
	for (int c = 0; c < this->childrenEntities.size(); c++) {
		((Preloader)(this->childrenEntities[c])).preload();
	}
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


