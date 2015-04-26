#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normals;

uniform mat4 dephMVP;

void main()
{
	gl_Position =  dephMVP * vec4(position,1);
}