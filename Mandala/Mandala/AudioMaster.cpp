#include "AudioHeader.h"


void AudioMaster::initAudio() {
	audioDevice = alcOpenDevice(NULL);
	audioContext = alcCreateContext(audioDevice,NULL);
}

void AudioMaster::deinitAudio() {}

int AudioMaster::loadSoundFile(std::string fileName) {
	//TODO: a�adir el descriptor a la lista
	return 0;
}