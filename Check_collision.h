#ifndef CHECK_COLLISION_H
#define CHECK_COLLISION_H

#include "Collisions.h"

namespace col
{
	bool check_collision_for_tank(glm::vec3 pos,bool a[3]);
	bool for_bullets_with_houses(glm::vec3 pos);
	bool collision(glm::vec3 pos, float d);
	int target_collision(glm::vec3 pos, bool a[3]);
}

#endif