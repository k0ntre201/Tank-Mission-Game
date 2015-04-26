#include "mesh.h"
#include <vector>
#include "obj_loader.h"
//konst domyœlny
Mesh::Mesh(){}
//jak chcemy model
Mesh::Mesh(const std::string& fileName)
{
	IndexedModel model = OBJModel(fileName).ToIndexedModel();
	initMesh(model);
}
//a tutaj jak chcemy podaæ wszysko z "rêki"
Mesh::Mesh(Vertex* vertices, unsigned int numVertex, unsigned int* indices, unsigned int numIndices)
{
	IndexedModel model;


	for (unsigned int i = 0; i < numVertex; i++)
	{
		model.positions.push_back(vertices[i].pos);
		model.texCoords.push_back(vertices[i].texCoord);
		model.normals.push_back(vertices[i].normals);
	}

	for (unsigned int i = 0; i < numIndices; i++)
		model.indices.push_back(indices[i]);

	initMesh(model);
}


//inicjujemy model
void Mesh::initMesh(const IndexedModel& model)
{
	m_drawCounter = model.indices.size();

	glGenVertexArrays(1, &m_vertexArayObject);
	glBindVertexArray(m_vertexArayObject);

	//tutaj wczytujemy wspolrzedne wierzcholkow
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() *sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//a tutaj wsp textur
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXTURE_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.positions.size()*sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	//NORMALKI
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[NORMAL_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.normals.size() *sizeof(model.normals[0]), &model.normals[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//indexy vertexów
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() *sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW);

	//za³¹czamy ca³¹ tablicê
	glBindVertexArray(0);
}

//³adujemy model
void Mesh::LoadMesh(const std::string& fileName)
{
	IndexedModel model = OBJModel(fileName).ToIndexedModel();
	initMesh(model);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArayObject);
}

//rysujemy w mainie obiekt
void Mesh::Draw()
{
		glBindVertexArray(m_vertexArayObject);
		glDrawElements(GL_TRIANGLES, m_drawCounter, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
}