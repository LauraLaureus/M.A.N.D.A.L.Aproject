#include "AudioMaster.h"


//TODO: modify to accept volumen and loop
void AudioMaster::playSoundFile(sf::SoundBuffer buffer,float volume,bool loop) {

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.setVolume(volume);
	sound.setLoop(loop);
	sound.play();

}

sf::SoundBuffer AudioMaster::loadFile(std::string fileName) {
	sf::SoundBuffer buffer;
	buffer.loadFromFile(fileName);
	return buffer;
}


std::string AudioMaster::getAbsoluteFileName(std::string fileName) {


	char* nameBuffer = new char[1024];
	if (GetModuleFileName(NULL, nameBuffer, 1024)) {

	}

	std::string absolutePath(nameBuffer);
	int pointer = absolutePath.rfind("\\");
	absolutePath = absolutePath.substr(0, pointer + 1);
	return absolutePath + fileName;

}