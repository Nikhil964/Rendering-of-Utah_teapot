#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/string_cast.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"
using namespace std;

class Camera
{
public:
	Camera(
		glm::vec3 eye,
		glm::vec3 lookAt,
		glm::vec3 up,
		float fov,
		float nearPlane,
		float farPlane,
		int bufferWidth,
		int bufferHeight
	);

	void updateBufferSize(int width, int height);
	void rotateRight(float angle);
	void rotateUp(float angle);
	void forward(float distance);
	void strafeRight(float distance);

	//getters
	glm::mat4 getViewMatrix() { return viewMat; }
	glm::mat4 getProjectMatrix() { return projMat; }

private:
	glm::vec3 eye = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 lookAt = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.f);
	float fov = float(glm::radians(100.0f));
	float nearPlane = float(0.1f);
	float farPlane = float(1000.0f);
	float bufferWidth = float(500.0f);
	float bufferHeight = float(500.0f);
	glm::mat4 viewMat;
	glm::mat4 projMat;

	void recomputeViewMat();
	void recomputeProjMat();
};

