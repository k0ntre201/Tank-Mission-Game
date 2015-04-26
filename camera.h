#ifndef CAMERA_H
#define CAMERA_H

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include "sc_angle.h"
#include <iostream>

class Camera
{
public:
	Camera();
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar, glm::vec3& target = glm::vec3(0.0, 0.0, 1.0));
	/*{
		m_perspective = glm::perspective(fov, aspect,zNear, zFar);
		m_pos = pos;
		m_forwart = target;
		m_up = glm::vec3(0, 1, 0);
		m_rotate = 0.0f;
		m_rotate_mouse = 0.0f;
		high_pos = m_pos.y;
	}*/

	void LoadCamera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar, glm::vec3& target = glm::vec3(0.0, 0.0, 1.0));

	glm::mat4 GetViewProjection() const;
	/*{
		return m_perspective*glm::lookAt(m_pos, m_pos + m_forwart, m_up);
	}*/

	void moveForward(float atm);
	/*{
		m_pos += m_forwart*atm;
	}*/

	void moveBack(float atm);
	/*{
		m_pos -= m_forwart*atm;
	}*/
	void moveRight(float atm);
	/*{
		m_pos += glm::cross(m_up, m_forwart)*atm;
	}*/
	void moveLeft(float atm);
	/*{
		m_pos -= glm::cross(m_up, m_forwart)*atm;
	}*/

	void Pith(float angle, float& angle2, float& posx, float& posz);

	void move(float& x, float &y);

	void rotatebyY(float angle, float& angle2, float& mouse_rotate, float& counter, float& helper);

	void setCamera(bool c);
	
private:
	glm::mat4 m_perspective;
	glm::vec3 m_pos;
	glm::vec3 m_forwart;
	glm::vec3 m_forwart2;
	glm::vec3 m_up;
	float m_rotate_mouse;
	float m_rotate;
	float sin_pos;
	float cos_pos;
	float high_pos;
	bool m_c;
};

#endif