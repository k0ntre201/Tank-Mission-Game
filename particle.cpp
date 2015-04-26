///////////////////////////////////////////////////////////////////////////////////////
// tutaj nastêpuje inicjacja, za³adowanie i rysowanie particli, gdy nastêpuje wybuch //
///////////////////////////////////////////////////////////////////////////////////////


#include "particle.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>


Particle::Particle(float s)
{
	std::random_device rd;
	std::uniform_real_distribution<> dist(-0.15, 0.15);
	std::default_random_engine d;
	int wight = 1000;
	int height = 600;
	camera.LoadCamera(glm::vec3(0.0f, 0.75f, -2.5f), 45.0f, (float)wight / height, 0.01f, 1000.0f);
	m_part.LoadMesh("./res/cube.obj");
	sh.Load("./res/bulletshader");
	deltaSpeed = 0.00981f;
	time = 2;
	deltatime = 0.02;
	scale = s;
	for (unsigned int i = 0; i < MAX_PARTICLES; i++)
	{
		speed[i].x= dist(d);
		speed[i].z = dist(d);
		temp_speed[i]=speed[i].y = glm::abs(dist(d))+0.1;
		m_rotate[i].x = dist(d)*50;
		m_rotate[i].y = dist(d)*50;
		m_rotate[i].z = dist(d)*10;
		transform[i].SetScal(glm::vec3(scale, scale, scale));
	}
}

// This function inicialize a first value of particles like us first position and live
void Particle::init_first_pos(glm::vec3 pos)
{
	for (unsigned int i = 0; i < MAX_PARTICLES; i++)
	{
		m_pos[i] = pos;
		live[i] = true;
		speed[i].y = temp_speed[i];
		del_rotate[i].x = 0;
		del_rotate[i].y = 0;
		del_rotate[i].z = 0;
	}
}

// This function draw particle until it reaches the high y=0.
// Returns false when all particles have false.
bool Particle::draw_particle(Camera &c)
{
	sh.Bind();
	camera = c;
	is_live = false;
	for (unsigned int i = 0; i < MAX_PARTICLES; ++i)
	{
		if (live[i])
		{
			is_live = true;
			m_pos[i].x += speed[i].x;
			m_pos[i].z += speed[i].z;
			m_pos[i].y += speed[i].y;
			del_rotate[i].x += m_rotate[i].x;
			del_rotate[i].y += m_rotate[i].y;
			del_rotate[i].z += m_rotate[i].z;
			speed[i].y -= deltaSpeed;
			transform[i].GetPos() = m_pos[i];
			transform[i].GetRot() = del_rotate[i];
			sh.Update(transform[i], camera);
			m_part.Draw();
		}
		if (m_pos[i].y < 0.0f)
			live[i] = false;
	}
	return is_live;
}

Particle::~Particle(){}