#version 330 core

// Input variables
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

// uniform variables
struct PointLight
{
vec3 pos;
vec3 color;
};
uniform PointLight light;
uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 normalMat;
uniform mat4 projMat;

//outputvariables
out vec3 view_Half;
out vec3 view_Normal;
out vec3 view_LightDir;
out vec3 world_Pos;

void main()
{
vec4 pos = vec4(position, 1.0);
vec4 norm = vec4(normal, 0.0);
vec4 Lpos = vec4(light.pos, 1.0);
view_Normal = vec3(normalMat*norm);
world_Pos = vec3(modelMat*pos);
vec4 viewP = viewMat*modelMat*pos;
vec3 viewLpos = (viewMat*Lpos).xyz;
view_LightDir = normalize(viewLpos - viewP.xyz);
vec3 viewV = normalize(-viewP.xyz);
view_Half = normalize(view_LightDir + viewV).xyz;
gl_Position = projMat*viewP;
}
