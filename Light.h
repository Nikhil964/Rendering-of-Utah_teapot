#pragma once

#include "glm/glm.hpp"
#include <cstring>
#include <sstream>
#include <string>
using namespace std;

class Light
{
public:
	Light();
	Light(glm::vec3 position);
	Light(glm::vec3 position, glm::vec3 col);
	void read(string data);
	string toString();

	//getters
	glm::vec3 getPos() { return position; }
	glm::vec3 getColor() { return color; }

private:
	glm::vec3 position=glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 color=glm::vec3(1.0f, 1.0f, 1.0f);
};
 
 