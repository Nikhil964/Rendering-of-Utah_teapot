#include "Camera.h"

Camera::Camera(glm::vec3 eye,
	           glm::vec3 lookAt,
	           glm::vec3 up,
	           float fov,
	           float nearPlane,
	           float farPlane,
	           int bufferWidth,
	           int bufferHeight)
{
	this->eye = eye;
	this->lookAt = lookAt;
	this->up = up;
	this->fov = fov;
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;
	this->bufferWidth = bufferWidth;
	this->bufferHeight = bufferHeight;
	recomputeViewMat();
	recomputeProjMat();
}


void Camera::recomputeViewMat()
{
	viewMat = glm::lookAt(eye, lookAt, up);
}

void Camera::recomputeProjMat()
{
	float AspRat = bufferWidth / bufferHeight;
	projMat = glm::perspective(fov, AspRat, nearPlane, farPlane);
}


void Camera::updateBufferSize(int width, int height)
{
	width = bufferWidth;
	height = bufferHeight;
	recomputeProjMat();
}

void Camera::rotateRight(float angle)
{
	glm::mat4 mat1;
	mat1 = glm::translate(-eye);
	mat1 = glm::rotate(angle, up);
	mat1 = glm::translate(eye);
	glm::vec4 lookat2;
	lookat2 = glm::vec4(lookAt, 1);
	lookat2 = mat1 * lookat2;
	lookAt = glm::vec3(lookat2);
	recomputeViewMat();
}

void Camera::rotateUp(float angle)
{
	glm::vec3 forwardvector, rightvector;
	forwardvector = lookAt - eye;
	rightvector = glm::normalize(glm::cross(forwardvector, up));
	glm::mat4 mat1;
	mat1 = glm::translate(-eye);
	mat1 = glm::rotate(angle, rightvector);
	mat1 = glm::translate(eye);
	glm::vec4 lookat2;
	lookat2 = glm::vec4(lookAt, 1);
	lookat2 = mat1 * lookat2;
	lookAt = glm::vec3(lookat2);
	recomputeViewMat();
}

void Camera::forward(float distance)
{
	glm::vec3 forwardvector;
	forwardvector = glm::normalize(lookAt - eye);
	forwardvector = distance * forwardvector;
	glm::mat4 mat1;
	mat1 = glm::translate(forwardvector);
	glm::vec4 lookat2;
	lookat2 = glm::vec4(lookAt, 1);
	lookat2 = mat1 * lookat2;
	lookAt = glm::vec3(lookat2);
	glm::vec4 eye2;
	eye2 = glm::vec4(eye, 1);
	eye2 = mat1 * eye2;
	eye = glm::vec3(eye2);
	recomputeViewMat();
}

void Camera::strafeRight(float distance)
{
	glm::vec3 forwardvector;
	forwardvector = lookAt - eye;
	glm::vec3 rightvector;
	rightvector = glm::normalize(glm::cross(forwardvector,up));
	rightvector = distance * rightvector;
	glm::mat4 mat1;
	mat1 = glm::translate(rightvector);
	glm::vec4 lookat2;
	lookat2 = glm::vec4(lookAt, 1);
	lookat2 = mat1 * lookat2;
	lookAt = glm::vec3(lookat2);
	glm::vec4 eye2;
	eye2 = glm::vec4(eye, 1);
	eye2 = mat1 * eye2;
	eye = glm::vec3(eye2);
	recomputeViewMat();
}
