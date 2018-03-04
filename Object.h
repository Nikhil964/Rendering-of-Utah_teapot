#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/string_cast.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"
#include <MeshShader.h>
#include <Model.h>
using namespace std;

class Object
{
public:
	Object();
	void setModel(Model *m) { model = m; }
	void translate(glm::vec3 t);
	void rotate(float angle, glm::vec3 axis);
	void scale(glm::vec3 s);
	void draw(MeshShader *shader);
	void resetTransformations();

private:
	Model *model = NULL;
	glm::mat4 modelMat;
	glm::vec4 center = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
};

