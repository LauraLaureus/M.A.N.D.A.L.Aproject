#pragma once
#include "GameComponent.h"
#include "SystemHeader.h"
#include "AudioHeader.h"

class SoundEffectComponent :
	public GameComponent
{
public:
	SoundEffectComponent(std::string name);
	~SoundEffectComponent();

	void play(int volume = 100,bool loop = false );
	void playWithSettings();

	void pause();
	void stop();
	void resume();

	void setVolumen(int v);
	void setLoop(bool l);

private:
	std::string filename;
	std::string filePath;

	sf::SoundBuffer buffer;
	sf::Sound sound;

	int volume; //0-100
	bool loop; 

};

