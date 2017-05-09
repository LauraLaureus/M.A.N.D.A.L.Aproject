#include "TobiiDevice.h"



TobiiDevice::TobiiDevice()
{

	if (TX_RESULT_OK != txInitializeEyeX(TX_EYEXCOMPONENTOVERRIDEFLAG_NONE, NULL, NULL, NULL, NULL))
	{
		this->state = NOTINITIALIZED;
	}
	else
	{
		this->state = INITIALIZED;
	}
}

bool TobiiDevice::createContext() {
	return txCreateContext(&hContext, TX_FALSE) == TX_RESULT_OK;
}

bool TobiiDevice::connect() {
	return txEnableConnection(hContext) == TX_RESULT_OK;
}


TobiiDevice::~TobiiDevice()
{
}
