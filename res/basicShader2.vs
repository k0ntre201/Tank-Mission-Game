#version 420

#define POSITION 0

layout( location = POSITION ) in vec4 inPosition;

void main()
{
    gl_Position = inPosition;
}