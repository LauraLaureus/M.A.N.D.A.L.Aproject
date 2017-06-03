#pragma once
#include "Preload.h"
#include "Renderizable.h"


class GameComponent: public Preloader, public Renderizable
{
private:
	
public:
	
	virtual void preload();

	std::string update(glm::vec2 gaze);

	GameComponent();
	~GameComponent();
};

