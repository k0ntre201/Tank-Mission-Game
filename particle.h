#ifndef PARTICE_H
#define PARTICE_H

#include "transform.h"
#include "mesh.h"
#include "camera.h"
#include "shader.h"

class Particle
{
public:
	Particle(float s);
	~Particle();
	bool draw_particle(Camera &c);
	void init_first_pos(glm::vec3 pos);
protected:
private:
	float scale, deltatime, time;
	enum numb{MAX_PARTICLES=50};
	float deltaSpeed;
	glm::vec3 speed[MAX_PARTICLES];
	glm::vec3 m_pos[MAX_PARTICLES];
	glm::vec3 m_rotate[MAX_PARTICLES];
	bool live[MAX_PARTICLES];
	bool is_live;
	Transform transform[MAX_PARTICLES];
	Camera camera;
	Mesh m_part;
	Shader sh;
	float temp_speed[MAX_PARTICLES];
	glm::vec3 del_rotate[MAX_PARTICLES];
};


#endif