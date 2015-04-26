#version 330

varying vec2 texCoord0;
varying vec3 normals0;

uniform sampler2D diffuse;

out vec4 gl_FragColor;

float cutoff=0.1;

void main()
{
	gl_FragColor = texture2D(diffuse,texCoord0)
		* clamp(dot(-vec3(0,0,1),normals0),0.4,0.9);

	if(gl_FragColor.a<cutoff)
	{
		discard;
	}

}
