#pragma once
#include "SystemHeader.h"
#include "ThreadingHeader.h"
#include "AudioHeader.h"

class AudioMaster
{
public:
	static sf::SoundBuffer loadFile(std::string fileName);
	static void playSoundFile(sf::SoundBuffer buffer,int volume=100,bool loop = false);
	static std::string getAbsoluteFileName(std::string fileName);
private:
	static void playDeattached(sf::Sound sound);
};

