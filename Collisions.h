#ifndef COLLISION_H
#define COLLISION_H

#include <glm\glm.hpp>

class Collision
{
public:
	bool Box_Collision(glm::vec3 Center, glm::vec3 d_Center,glm::vec3 pos);
	bool Sphere_Collison(glm::vec3 Center, glm::vec3 pos, float radius);
	bool Cylinder_Collision(glm::vec3 Center, glm::vec3 pos, float radius, float dy);
};

#endif