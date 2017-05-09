#pragma once
#include <eyex-cpp\EyeX.hpp>



enum TobiiState{
	INITIALIZED,
	NOTINITIALIZED
};

class TobiiDevice
{
public:
	TobiiDevice();
	~TobiiDevice();

	bool createContext();
	bool connect();
	TobiiState state;
private:
	TX_CONTEXTHANDLE hContext = TX_EMPTY_HANDLE;
};

