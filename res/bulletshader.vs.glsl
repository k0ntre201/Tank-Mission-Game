#version 330

//attribute vec3 position;
//attribute vec2 texCoord;
//attribute vec3 normals;

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec3 normals;


varying vec2 texCoord0;
varying vec3 normals0;

uniform mat4 transform;

void main()
{
	gl_Position = transform * vec4(position, 1.0);
	texCoord0 = texCoord;
	normals0 = (transform * vec4(normals,0.0)).xyz;
}