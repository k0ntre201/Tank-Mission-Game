#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

class Transform
{
public:
	Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scal = glm::vec3(1.0f, 1.0f, 1.0f)) :m_pos(pos), m_rot(rot), m_scal(scal)
	{
	}

	glm::mat4 GetModel() const
	{
		glm::mat4 posMatrix = glm::translate(m_pos);
		glm::mat4 rotXMatrix = glm::rotate(m_rot.x, glm::vec3(1, 0, 0));
		glm::mat4 rotYMatrix = glm::rotate(m_rot.y, glm::vec3(0, 1, 0));
		glm::mat4 rotZMatrix = glm::rotate(m_rot.z, glm::vec3(0, 0, 1));
		glm::mat4 scalMatrix = glm::scale(m_scal);

		glm::mat4 rotMatrix = rotZMatrix*rotYMatrix*rotXMatrix;

		return posMatrix*rotMatrix*scalMatrix;
	}


	glm::vec3& GetPos(){ return m_pos; }
	glm::vec3& GetRot(){ return m_rot; }
	glm::vec3& GetScal(){ return m_scal; }


	void SetPos(const glm::vec3& pos){ m_pos = pos; }
	void SetRot(const glm::vec3& Rot){ m_rot = Rot; }
	void SetScal(const glm::vec3& scal){ m_scal = scal; }

	
private:
	glm::vec3 m_pos;
	glm::vec3 m_rot;
	glm::vec3 m_scal;
};


#endif