#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <Camera.h>
#include <MeshMaterial.h>
#include <Shader.h>
#include<Light.h>
using namespace std;

class MeshShader : public Shader
{
public:
	MeshShader(string vertexFilename, string fragmentFilename);
	void setModelTransform(glm::mat4 &modelMat);
	void setViewAndProjection(Camera *camera);
	void setMaterial(MeshMaterial *material);
	void setLight(Light *light);


private:
	GLint modelMatLoc = GLint(-1.0f);
	GLint viewMatLoc = GLint(-1.0f);
	GLint normalMatLoc = GLint(-1.0f);
	GLint projMatLoc = GLint(-1.0f);

	GLint shinyLoc = GLint(-1.0f);
	GLint kdLoc = GLint(-1.0f);
	GLint ksLoc = GLint(-1.0f);

	GLint lightPosLoc = GLint(-1.0f);
	GLint lightColorLoc = GLint(-1.0f);

	glm::mat4 modelMat;
	glm::mat4 viewMat;

};


