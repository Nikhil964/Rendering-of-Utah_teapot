
#include "Light.h"

Light::Light(){}
Light::Light(glm::vec3 pos) 
{
	position = pos;
}
Light::Light(glm::vec3 pos, glm::vec3 col)
{
	position = pos;
	color = col;
}

void Light::read(string data) {
	stringstream ss(data);
	char dummy[80];
	ss >> dummy;
	ss >> position.x >> position.y >> position.z;

	if (ss >> color.r) {
		ss >> color.g >> color.b;
	}
	else {
		color = glm::vec3(1.0f, 1.0f, 1.0f);
	}
}



string Light::toString() {
	string output;
	output = output + "l ";
	output += to_string(position.x) + " ";
	output += to_string(position.y) + " ";
	output += to_string(position.z) + " ";
	output += to_string(color.r) + " ";
	output += to_string(color.g) + " ";
	output += to_string(color.b) + " ";
	return output;
}




