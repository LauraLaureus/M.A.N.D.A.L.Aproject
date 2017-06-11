#include "MusicComponent.h"



MusicComponent::MusicComponent(GameEntity* parent,std::string name): GameComponent(parent)
{

	this->filename = name;
	this->filePath = AudioMaster::getAbsoluteFileName(name);
	this->music.openFromFile(this->filePath);
}


MusicComponent::~MusicComponent()
{
}


void MusicComponent::play(int volume, int loop) {
	this->music.setVolume(volume);
	this->music.setLoop(loop);
	this->music.play();
}

void MusicComponent::pause() {
	this->music.pause();
}


void MusicComponent::stop() {
	this->music.stop();
}

void MusicComponent::setVolumen(int v) {
	this->volume = v;
}

void MusicComponent::setLoop(bool l) {
	this->loop = l;
}

