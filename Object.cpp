#include "Object.h"

Object::Object(){}

void Object::translate(glm::vec3 t)
{
	glm::mat4 M;
	M = glm::translate(t);
	modelMat = M * modelMat;
	center = M * center;;
}

void Object::rotate(float angle, glm::vec3 axis)
{
	modelMat = glm::translate(-glm::vec3(center)) * modelMat;
	modelMat = glm::rotate(angle, axis) * modelMat;
	modelMat = glm::translate(glm::vec3(center)) * modelMat;
}

void Object::scale(glm::vec3 s)
{
	modelMat = glm::translate(-glm::vec3(center)) * modelMat;
	modelMat = glm::scale(s) * modelMat;
	modelMat = glm::translate(glm::vec3(center)) * modelMat;
}

void Object::draw(MeshShader *shader)
{
	if (model) {
		shader->setModelTransform(modelMat);
		model->draw();
	}
}

void Object::resetTransformations()
{
	modelMat = glm::mat4(1);
	center = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
}

