#pragma once
#include "Preload.h"

class GameComponent: public Preloader
{
public:
	virtual void preload();

	~GameComponent();
};

