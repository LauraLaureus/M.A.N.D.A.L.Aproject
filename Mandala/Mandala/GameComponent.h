#pragma once
#include "Preload.h"
#include "Renderizable.h"

class GameComponent: public Preloader, public Renderizable
{
public:
	virtual void preload();

	void update(glm::vec2 gaze);

	~GameComponent();
};

