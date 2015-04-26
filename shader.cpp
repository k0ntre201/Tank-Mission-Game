#include "shader.h"
#include <iostream>
#include <fstream>
#include <glm\gtc\type_ptr.hpp>

Shader::Shader(){}

Shader::Shader(const std::string& filename)
{
	m_program = glCreateProgram();
	
	m_shaders[0] = CreateShader(LoadShader(filename + ".vs.glsl"), GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(filename + ".fs.glsl"), GL_FRAGMENT_SHADER);
	//m_shaders[2] = CreateShader(LoadShader(filename + ".gs"), GL_GEOMETRY_SHADER);

	for (unsigned int i = 0; i < NUM_SHADERS; i++)
		glAttachShader(m_program, m_shaders[i]);

	glBindAttribLocation(m_program, 0, "position");
	glBindAttribLocation(m_program, 1, "texCoord");
	glBindAttribLocation(m_program, 2, "normals");

	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Program is not linked!");

	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is not validated!");

	m_uniform[TRANSFORM_U] = glGetUniformLocation(m_program, "transform");
	m_uniform[INVERSE_MAT4] = glGetUniformLocation(m_program, "v_inv");
	m_uniform[INVERSE_MAT3] = glGetUniformLocation(m_program, "v_inv_3x3");
}

void Shader::Load(const std::string& filename)
{
	m_program = glCreateProgram();

	m_shaders[0] = CreateShader(LoadShader(filename + ".vs.glsl"), GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(filename + ".fs.glsl"), GL_FRAGMENT_SHADER);
	//m_shaders[2] = CreateShader(LoadShader(filename + ".gs"), GL_GEOMETRY_SHADER);

	for (unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glAttachShader(m_program, m_shaders[i]);
		//std::cout << m_shaders[i] << std::endl;
	}

	glBindAttribLocation(m_program, 0, "position");
	glBindAttribLocation(m_program, 1, "texCoord");
	glBindAttribLocation(m_program, 2, "normals");

	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Program is not linked!");

	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is not validated!");

	m_uniform[TRANSFORM_U] = glGetUniformLocation(m_program, "transform");
	m_uniform[INVERSE_MAT4] = glGetUniformLocation(m_program, "v_inv");
	m_uniform[INVERSE_MAT3] = glGetUniformLocation(m_program, "v_inv_3x3");
}

Shader::~Shader()
{
	for (unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}
	glDeleteProgram(m_program);
}

void Shader::Bind()
{
	glUseProgram(m_program);
}




void Shader::Update(const Transform& transform, const Camera& camera)
{
	//shadow.compue_light();
	glm::mat4 model = camera.GetViewProjection() * transform.GetModel();
	glUniformMatrix4fv(m_uniform[TRANSFORM_U], 1, GL_FALSE, &model[0][0]);
	//inverse matrix
	glm::mat4 v_inv = glm::inverse(camera.GetViewProjection());
	glUniformMatrix4fv(m_uniform[INVERSE_MAT4], 1, GL_FALSE, &v_inv[0][0]);
	glm::mat3 m_3x3_inv_transpose = glm::inverse(glm::transpose(glm::mat3(transform.GetModel())));
	glUniformMatrix3fv(m_uniform[INVERSE_MAT3], 1, GL_FALSE, glm::value_ptr(v_inv));
}

std::string Shader::LoadShader(const std::string& fileName)
{
	std::ifstream file;
	file.open((fileName).c_str());

	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
		std::cerr << "Unable to load shader: " << fileName << std::endl;

	return output;
}

void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}
}

GLuint Shader::CreateShader(const std::string& text, unsigned int type)
{
	GLuint shader = glCreateShader(type);

	if (shader == 0)
		std::cerr << "Error: Shader created failed!" << std::endl;

	const GLchar* shaderSourceString[1];
	GLint shaderSourceStringLengh[1];

	shaderSourceStringLengh[0] = text.length();
	shaderSourceString[0] = text.c_str();
	
	glShaderSource(shader, 1, shaderSourceString, shaderSourceStringLengh);
	glCompileShader(shader);

	CheckShaderError(shader,GL_COMPILE_STATUS, false, "Error: Shader is nod compiled!");

	return shader;
}

GLuint Shader::initial_program_shader(const std::string& filename)
{
	GLuint program = glCreateProgram();

	GLuint shader[2];

	shader[0] = CreateShader(LoadShader(filename + ".vs.glsl"), GL_VERTEX_SHADER);
	shader[1] = CreateShader(LoadShader(filename + ".fs.glsl"), GL_FRAGMENT_SHADER);
	//m_shaders[2] = CreateShader(LoadShader(filename + ".gs"), GL_GEOMETRY_SHADER);

	for (unsigned int i = 0; i < 2; i++)
	{
		glAttachShader(program, shader[i]);
		//std::cout << m_shaders[i] << std::endl;
	}

	glBindAttribLocation(program, 0, "position");
	glBindAttribLocation(program, 1, "texCoord");
	glBindAttribLocation(program, 2, "normals");

	glLinkProgram(program);
	CheckShaderError(program, GL_LINK_STATUS, true, "Error: Program is not linked!");

	glValidateProgram(program);
	CheckShaderError(program, GL_VALIDATE_STATUS, true, "Error: Program is not validated!");

	return program;
}