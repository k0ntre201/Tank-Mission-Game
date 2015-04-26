////////////////////////////////////////////////////////
// funkcje sprawdzaj¹ce kolizje cylidrycznie i boxowo //
////////////////////////////////////////////////////////
#include "Collisions.h"
#include <iostream>

using namespace glm;

bool Collision::Box_Collision(vec3 Center, vec3 d_Center,vec3 pos)
{
	///std::cout << (Center.x - d_Center.x) << " " << (Center.x + d_Center.x) << " " << pos.x << " " << Center.z - d_Center.z << " " << Center.z + d_Center.z <<" "<< pos.z << std::endl;
	if (pos.x > (Center.x - d_Center.x) && pos.x<(Center.x + d_Center.x) && pos.y>(Center.y - d_Center.y) && pos.y<(Center.y + d_Center.y) && pos.z>(Center.z - d_Center.z) && pos.z < (Center.z + d_Center.z))
		return true;
	else
		return false;
}

bool Collision::Cylinder_Collision(vec3 center, vec3 pos, float radius, float dy)
{
	float dx = (center.x - pos.x);
	float dz = (center.z - pos.z);
	//std::cout << glm::sqrt(dx*dx + dz*dz) << " " << dx<<" "<<dz <<" " << pos.x << " " << pos.z << std::endl;
	//dx*dx+dz*dz
	if (glm::sqrt(dx*dx + dz*dz) < radius && pos.y >= 0 && pos.y < dy)
		return true;
	else
		return false;
}