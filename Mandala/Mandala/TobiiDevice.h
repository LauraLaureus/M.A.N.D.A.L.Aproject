#pragma once

#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <assert.h>
#include <eyex-cpp\EyeX.hpp>
#pragma comment (lib, "Tobii.EyeX.Client.lib")

class TobiiDevice
{
public:
	TobiiDevice();
	~TobiiDevice();

private:

	TX_CONTEXTHANDLE hContext = TX_EMPTY_HANDLE;
	TX_STRING InteractorId = "M.A.N.D.A.L.A";
	TX_HANDLE g_hGlobalInteractorSnapshot = TX_EMPTY_HANDLE;
	TX_TICKET hConnectionStateChangedTicket = TX_INVALID_TICKET;


	void TX_CALLCONVENTION OnSnapshotCommitted(TX_CONSTHANDLE hAsyncData, TX_USERPARAM param);
	void TX_CALLCONVENTION OnEngineConnectionStateChanged(TX_CONNECTIONSTATE connectionState, TX_USERPARAM userParam);
	bool InitializeGlobalInteractorSnapshot(TX_CONTEXTHANDLE hContext);
	void TX_CALLCONVENTION HandleEvent(TX_CONSTHANDLE hAsyncData, TX_USERPARAM userParam);
	void OnGazeDataEvent(TX_HANDLE hGazeDataBehavior);
};

