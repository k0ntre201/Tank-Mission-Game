#ifndef MESH_H
#define MESH_H

#include <glm\glm.hpp>
#include <GL\glew.h>
#include "obj_loader.h"


class Vertex
{
public:
	Vertex(const glm::vec3& pos,const glm::vec2& texCoord,const glm::vec3& normals = glm::vec3(0,0,0))
	{
		this->pos = pos;
		this->texCoord = texCoord;
		this->normals = normals;
	}
	glm::vec3 pos;
	glm::vec2 texCoord;
	glm::vec3 normals;
private:
	
};


class Mesh
{
public:
	Mesh();
	Mesh(const std::string& fileName);
	Mesh(Vertex* vertices, unsigned int numVertex, unsigned int* indices, unsigned int numIndices);

	void LoadMesh(const std::string& fileName);

	void Draw();

	virtual ~Mesh();
private:
	Mesh(const Mesh& other);
	void operator=(const Mesh& other);

	void initMesh(const IndexedModel& model);

	enum{POSITION_VB,TEXTURE_VB,NORMAL_VB,INDEX_VB,NUM_BUFFERS};

	GLuint m_vertexArayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCounter;
};

#endif