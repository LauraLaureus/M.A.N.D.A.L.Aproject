#pragma once
#include "SystemHeader.h"
#include "ThreadingHeader.h"
#include "AudioHeader.h"

class AudioMaster
{
public:
	static std::string getAbsoluteFileName(std::string fileName)
	{


		char* nameBuffer = new char[1024];
		if (GetModuleFileName(NULL, nameBuffer, 1024)) {

		}

		std::string absolutePath(nameBuffer);
		int pointer = absolutePath.rfind("\\");
		absolutePath = absolutePath.substr(0, pointer + 1);
		return absolutePath + fileName;

	}

};

