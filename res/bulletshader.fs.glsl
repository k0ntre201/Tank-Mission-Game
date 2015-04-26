#version 330

varying vec2 texCoord0;
varying vec3 normals0;

uniform sampler2D diffuse;

out vec4 gl_FragColor;

void main()
{
	gl_FragColor = vec4(0.85,0.85,0.1,1.0)
		* clamp(dot(-vec3(0,0,1),normals0),0.4,0.9);

}
//vec4(1.0, 0.0, 0.0, 1.0);
