#pragma once
#include "SystemHeader.h"

class AudioMaster
{
public:
	 static void initAudio();
	 static void deinitAudio();
	 static void playSoundFile(std::string fileName,float volume=1.0,bool loop = false);
	 static void recordFunction();
	 static void recordInit();
	 static void recordStop();

private:
	static std::list<ALuint>* buffers;
	static ALCcontext* audioContext;
	static ALCdevice* audioDevice;


};
