#include "AudioHeader.h"


std::list<ALuint>* AudioMaster::buffers;
ALCcontext* AudioMaster::audioContext;
ALCdevice* AudioMaster::audioDevice;


const int SRATE = 44100;
const int SSIZE = 1024;

ALbyte buffer[22050];
ALint sample;


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


//TODO: modify to accept volumen and loop
void AudioMaster::playSoundFile(std::string fileName,float volume,bool loop) {

	sf::SoundBuffer buffer;
	
	if (!buffer.loadFromFile(fileName))
		return;

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.setVolume(volume);
	sound.setLoop(loop);
	sound.play();

	//DEPRECATEDPlaySound(TEXT(fileName.c_str()), NULL, SND_ASYNC);
}

void AudioMaster::recordInit() {
	AudioMaster::audioDevice = alcCaptureOpenDevice(NULL, SRATE, AL_FORMAT_STEREO16, SSIZE);
	if (alGetError() != AL_NO_ERROR) {
		return;
	}
	alcCaptureStart(AudioMaster::audioDevice);

}

void AudioMaster::recordFunction() {

	while (true) {
		alcGetIntegerv(AudioMaster::audioDevice, ALC_CAPTURE_SAMPLES, (ALCsizei)sizeof(ALint), &sample);
		alcCaptureSamples(AudioMaster::audioDevice, (ALCvoid *)buffer, sample);

		// ... do something with the buffer 
	}

}

void AudioMaster::recordStop() {
	alcCaptureStop(AudioMaster::audioDevice);
	alcCaptureCloseDevice(AudioMaster::audioDevice);
}