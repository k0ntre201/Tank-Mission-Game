#version 330

varying vec2 texCoord0;
varying vec3 normals0;

uniform sampler2D diffuse;

out vec4 cos;

void main()
{
	cos = vec4(0.0, 0.0, 1.0, 1.0)
		* clamp(dot(-vec3(0,0,1),normals0),0.5,4.0);

}
