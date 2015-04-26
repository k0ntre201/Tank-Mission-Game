////////////////////////////////////////////////////////////////////
// tutaj nastêpuje inicjalizacja kamery i znajduj¹ siê tutaj      //
// wszystkie funkcje odpowiedzalneza posuszanie i obracanie kamey //
////////////////////////////////////////////////////////////////////


#include "camera.h"
#include <cmath>

Camera::Camera(){}

Camera::Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar, glm::vec3& target)
{
	m_perspective = glm::perspective(fov, aspect, zNear, zFar);
	m_pos = pos;
	m_forwart = target;
	m_up = glm::vec3(0, 1, 0);
	m_rotate = 0.0f;
	m_rotate_mouse = 0.0f;
	high_pos = m_pos.y;
	m_c = true;
}

void Camera::LoadCamera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar, glm::vec3& target)
{
	m_perspective = glm::perspective(fov, aspect, zNear, zFar);
	m_pos = pos;
	m_forwart = target;
	m_up = glm::vec3(0, 1, 0);
	m_rotate = 0.0f;
	m_rotate_mouse = 0.0f;
	high_pos = m_pos.y;
}

glm::mat4 Camera::GetViewProjection() const
{
	return m_perspective*glm::lookAt(m_pos, m_pos + m_forwart, m_up);
}

void Camera::moveForward(float atm)
{
	m_pos += m_forwart*atm;
}


void Camera::moveBack(float atm)
{
	m_pos -= m_forwart*atm;
}
void Camera::moveRight(float atm)
{
	m_pos += glm::cross(m_up, m_forwart)*atm;
}
void Camera::moveLeft(float atm)
{
	m_pos -= glm::cross(m_up, m_forwart)*atm;
}

void Camera::rotatebyY(float angle, float& angle2,float& mouse_rotate, float& counter, float& helper)
{
	static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

	glm::mat4 rotation = glm::rotate(angle, UP);

	m_rotate = angle2 + mouse_rotate;
	if (m_c)
	{
		cos_pos = 2.5 * cosinus(m_rotate);
		sin_pos = 2.5 * sinus(m_rotate);
	}
	else
		high_pos = 0.75f;
	//camera on tank position
	m_pos = glm::vec3(helper, high_pos, counter);
	m_forwart = glm::vec3(glm::normalize(rotation * glm::vec4(m_forwart, 0.0)));
	m_up = glm::vec3(glm::normalize(rotation * glm::vec4(m_up, 0.0)));
	//back camera to behind tank
	if (m_c)
		m_pos = glm::vec3(m_pos.x - sin_pos , high_pos, m_pos.z - cos_pos);
}

void Camera::move(float& x, float& y)
{
	if (m_c)
		m_pos = glm::vec3(x - sin_pos, high_pos, y - cos_pos);
	else
		m_pos = glm::vec3(x, high_pos, y);
}

void Camera::Pith(float angle, float& angle2,float& posx,float& posz)
{
	if (m_c)
		high_pos = 0.75f + 2.5 * sinus(angle2);
	else
		high_pos = 0.75f;
	m_pos = glm::vec3(posx, high_pos, posz);
	glm::vec3 right = glm::normalize(glm::cross(m_forwart, m_up));

	m_forwart = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(m_forwart, 0.0)));
	//m_up = glm::normalize(glm::cross(m_forwart, right));
	if (m_c)
		m_pos = glm::vec3(m_pos.x - sin_pos, high_pos, m_pos.z - cos_pos);

}

void Camera::setCamera(bool c)
{
	m_c = c;
}