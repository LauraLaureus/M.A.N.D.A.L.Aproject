#include "SoundEffectComponent.h"



SoundEffectComponent::SoundEffectComponent(GameEntity* parent,std::string name) : GameComponent(parent)
{
	this->filename = name;
	this->filePath = AudioMaster::getAbsoluteFileName(name);
	this->buffer = sf::SoundBuffer();
	this->buffer.loadFromFile(this->filePath);
	this->sound = sf::Sound(this->buffer);
}


SoundEffectComponent::~SoundEffectComponent()
{
	
}

void SoundEffectComponent::playWithSettings() {
	play(this->volume, this->loop);
}


void SoundEffectComponent::play(int volume, bool loop) {
	this->sound.setVolume(volume);
	this->sound.setLoop(loop);
	this->sound.play();
}

void SoundEffectComponent::pause() {
	this->sound.pause();
}

void SoundEffectComponent::resume() {
	this->sound.play();
}

void SoundEffectComponent::stop() {
	this->sound.stop();
}

void SoundEffectComponent::setVolumen(int v) {
	this->volume = v;
}
 

void  SoundEffectComponent::setLoop(bool l) {
	this->loop = l;
}