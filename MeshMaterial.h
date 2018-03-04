#pragma once

#include "glm/glm.hpp"
using namespace std;

class MeshMaterial
{
public:
	MeshMaterial(){}

	//setters
	void setShininess(float newshiny) { shiny = newshiny; }
	void setKd(glm::vec3& newkd) { kd = newkd; }
	void setKs(glm::vec3& newks) { ks = newks; }

	//getters
	float getShininess() { return shiny; }
	glm::vec3 getKd() { return kd; }
	glm::vec3 getKs() { return ks; }

private:
	glm::vec3 kd = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 ks = glm::vec3(0.0f, 0.0f, 0.0f);
	float shiny = float(1.0f);
};

