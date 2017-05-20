#pragma once
#include "GameComponent.h"
#include "AudioHeader.h"
#include "SystemHeader.h"

class MusicComponent :
	public GameComponent
{
public:
	void play(int volume=100, int loop = false);
	void pause();
	void stop();

	void setVolumen(int v);
	void setLoop(bool l);

	MusicComponent(std::string name);
	~MusicComponent();



private:
	std::string filename;
	std::string filePath;

	sf::SoundBuffer buffer;
	sf::Music music;

	int volume; //0-100
	bool loop;
};

