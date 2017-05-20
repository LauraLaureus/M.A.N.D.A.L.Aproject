#pragma once
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <assert.h>
#include "eyex/EyeX.h"
#include "glm\glm.hpp"

#pragma comment (lib, "Tobii.EyeX.Client.lib")

// ID of the global interactor that provides our data stream; must be unique within the application.
static const TX_STRING InteractorId = "Twilight Sparkle";

// global variables
static TX_HANDLE g_hGlobalInteractorSnapshot = TX_EMPTY_HANDLE;

BOOL InitializeGlobalInteractorSnapshot(TX_CONTEXTHANDLE hContext);
void TX_CALLCONVENTION OnEngineConnectionStateChanged(TX_CONNECTIONSTATE connectionState, TX_USERPARAM userParam);
void TX_CALLCONVENTION HandleEvent(TX_CONSTHANDLE hAsyncData, TX_USERPARAM userParam);

glm::vec2 getGaze();

