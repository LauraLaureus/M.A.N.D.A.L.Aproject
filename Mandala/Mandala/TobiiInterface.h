#pragma once

#include "TobiiCore.h"
#include "SystemHeader.h"
#include "glm\glm.hpp"


class TobiiInterface
{
public:
	TobiiInterface();
	~TobiiInterface();
	glm::vec2 getGazePoint();
};

