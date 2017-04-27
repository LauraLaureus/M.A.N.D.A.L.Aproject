#pragma once
#include "SystemHeader.h"

class AudioMaster
{
public:
	 static void initAudio(); // proposed to be deprecated.
	 static void deinitAudio(); // proposed to be deprecated.
	 static void playSoundFile(std::string fileName,float volume=1.0,bool loop = false);
	 static void recordFunction(); // proposed to be deprecatd. 
	 static void recordInit(); // proposed to be deprecated.
	 static void recordStop(); // proposed to be deprecated. 

private:
	static std::list<ALuint>* buffers; //proposed to be deprecated
	static ALCcontext* audioContext; // proposed to be deprecated
	static ALCdevice* audioDevice; // proposed to be deprecated


};
