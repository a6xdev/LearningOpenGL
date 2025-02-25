#pragma once
#ifndef NODE3D_H
#define NODE3D_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

#include <vector>
#include <string>

#include "../node.h"


class Node3D : public Node {
public:
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotation;

	Node3D(const std::string& name = "Node3D") : Node(name), position(0.0f), scale(1.0f), rotation(0.0f) {}

	void setPosition(glm::vec3 _position) {
		position = _position;
	}
	void setScale(glm::vec3 _scale) {
		scale = _scale;
	}
	void setRotation(glm::vec3 _rotation) {
		rotation = _rotation;
	}

	glm::vec3 getPosition() {
		return position;
	}
	glm::vec3 getScale() {
		return scale;
	}
	glm::vec3 getRotation() {
		return rotation;
	}

	glm::mat4 getTransformationMatrix() {
		glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
		glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), scale);
		glm::mat4 rotationMatrix = glm::mat4(1.0f);

		rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); // Rota��o no eixo X
		rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); // Rota��o no eixo Y
		rotationMatrix = glm::rotate(rotationMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)); // Rota��o no eixo Z

		return translationMatrix * rotationMatrix * scaleMatrix;
	}

	virtual ~Node3D() {}
};

#endif // NODE3D_H