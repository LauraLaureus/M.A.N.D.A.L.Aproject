#pragma once
#include "SystemHeader.h"

class AudioMaster
{
public:
	 static void initAudio();
	 static void deinitAudio();
	 static int loadSoundFile(std::string filename);

private:
	static std::list<ALuint>* buffers;
	static ALCcontext* audioContext;
	static ALCdevice* audioDevice;


};
