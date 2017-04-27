#pragma once
#include "SystemHeader.h"
#include "AudioHeader.h"

class AudioMaster
{
public:
	static sf::SoundBuffer loadFile(std::string fileName);
	static void playSoundFile(sf::SoundBuffer buffer,float volume=1.0,bool loop = false);
	static std::string getAbsoluteFileName(std::string fileName);
};

