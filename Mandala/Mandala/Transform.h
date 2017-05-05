#pragma once
#include "glm\glm.hpp"

class Transform {

public:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 size;
	Transform() {};
	void setPosition(glm::vec3 newPoisition) {
		this->position = newPoisition;
	};

	void setPosition(float x, float y, float z) {
		this->position = *new glm::vec3(x, y, z);
	};

	void setRotation(glm::vec3 newRotation) {
		this->rotation = newRotation;
	};

	void setRotation(float x, float y, float z) {
		this->rotation = *new glm::vec3(x, y, z);
	};

	void setSize(glm::vec3 newSize) {
		this->size = newSize;
	};

	void setSize(float x, float y, float z) {
		this->size = *new glm::vec3(x, y, z);
	};
};