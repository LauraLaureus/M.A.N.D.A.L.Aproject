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
private:
	TX_CONTEXTHANDLE hContext = TX_EMPTY_HANDLE;
	TX_TICKET hConnectionStateChangedTicket = TX_INVALID_TICKET;
	TX_TICKET hEventHandlerTicket = TX_INVALID_TICKET;
	BOOL success;
};

