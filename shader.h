#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL\glew.h>
#include "transform.h"
#include "camera.h"
//#include "shadow.h"

class Shader
{
public:
	Shader(const std::string& filename);
	Shader();

	void Load(const std::string& filename);
	void Bind();
	void Update(const Transform& transform,const Camera& camera);
	GLuint initial_program_shader(const std::string& filename);

	virtual ~Shader();
private:
	static const unsigned int NUM_SHADERS = 2;
	void operator=(const Shader& other){}

	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	std::string LoadShader(const std::string& fileName);
	GLuint CreateShader(const std::string& text, unsigned int type);

	enum{TRANSFORM_U,INVERSE_MAT4,INVERSE_MAT3,NUM_UNIFORMS};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniform[NUM_UNIFORMS];
};

#endif