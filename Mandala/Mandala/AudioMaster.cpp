#include "AudioHeader.h"


std::list<ALuint>* AudioMaster::buffers;
ALCcontext* AudioMaster::audioContext;
ALCdevice* AudioMaster::audioDevice;

void AudioMaster::initAudio() {
	AudioMaster::audioDevice = alcOpenDevice(NULL);
	if (!AudioMaster::audioDevice) {
		//TODO mandar una excepción
	}

	AudioMaster::audioContext = alcCreateContext(audioDevice,NULL);
	if (!alcMakeContextCurrent(AudioMaster::audioContext)) {
		//TODO mandar una excepción
	}

	AudioMaster::buffers = new std::list<ALuint>();
}

void AudioMaster::deinitAudio() {
	delete AudioMaster::buffers;
	delete AudioMaster::audioContext;
	delete AudioMaster::audioDevice;
}

int AudioMaster::loadSoundFile(std::string fileName) {
	ALuint bufferDescriptor;
	alGenBuffers((ALuint)1,&bufferDescriptor);
	AudioMaster::buffers->push_back(bufferDescriptor);

	//TODO load wavFile

	return 0;
}