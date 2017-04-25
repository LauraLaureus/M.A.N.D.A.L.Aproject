#pragma once
#include "SystemHeader.h"

class AudioMaster
{
public:
	 void initAudio();
	 void deinitAudio();
	 int loadSoundFile(std::string filename);

private:
	std::list<int>* buffers = new std::list<int>();
	ALCcontext* audioContext;
	ALCdevice* audioDevice;


};
