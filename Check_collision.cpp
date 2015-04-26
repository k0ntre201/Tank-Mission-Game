//////////////////////////////////////////////////////////////////
// tutaj nastêpuje sprawdzenie kolizji dla czo¹gu i dla pocisku //
//////////////////////////////////////////////////////////////////

#include "Check_collision.h"

Collision houses;

bool col::collision(glm::vec3 pos, float d)
{
	if (houses.Box_Collision(glm::vec3(-9.4588f, 5.0f, 12.6416f), glm::vec3(3.8555f-d, 5.5f, 6.6992f-d), pos))
		return true;
	if (houses.Box_Collision(glm::vec3(9.9635f, 5.0f, 19.541f), glm::vec3(4.1285-d, 5.5f, 4.46-d), pos))
		return true;
	if (houses.Box_Collision(glm::vec3(9.83, 5.0f, 29.33), glm::vec3(4.67-d, 5.5f, 5.33-d), pos))
		return true;
	if (houses.Box_Collision(glm::vec3(-34.11, 5.0f, 9.95), glm::vec3(3.628-d, 5.5f, 9.68-d), pos))
		return true;
	if (houses.Box_Collision(glm::vec3(-27.23, 5.0f, 16.75), glm::vec3(3.77-d, 5.5f, 2.87-d), pos))
		return true;
	if (houses.Box_Collision(glm::vec3(-9.16, 5.0f, 35.655), glm::vec3(5.84-d, 5.5f, 5.895-d), pos))
		return true;
	if (houses.Box_Collision(glm::vec3(-30.535, 5.0f, 37.27), glm::vec3(6.215-d, 5.5f, 6.07-d), pos))
		return true;
	if (houses.Box_Collision(glm::vec3(-24.225, 5.0f, 37.27), glm::vec3(1.775-d, 5.5f, 6.07-d), pos))
		return true;
	if (houses.Box_Collision(glm::vec3(-37.45, 5.0f, 32.865), glm::vec3(2.45-d, 5.5f, 3.175-d), pos))
		return true;
	if (houses.Box_Collision(glm::vec3(-8.515, 5.0f, 58.015), glm::vec3(5.715-d, 5.5f, 12.0f-d), pos))
		return true;
	if (houses.Box_Collision(glm::vec3(3.845, 5.0f, 73.875), glm::vec3(3.345-d, 5.5f, 3.435-d), pos))
		return true;

	return false;
}

bool col::check_collision_for_tank(glm::vec3 pos,bool a[3])
{
	//check with cylinder 3 first are target
	/*if (!a[0])
		if (houses.Box_Collision(glm::vec3(11.2818f, 0.5f, 39.819f), glm::vec3(1.25f, 0.6f, 1.25f), pos))
			return true;*/
	/*if (!a[1])
		if (houses.Box_Collision(glm::vec3(-24.599, 0.5f, 4.6097), glm::vec3(1.25f, 0.6f, 1.25f), pos))
			return true;
	if (!a[2])
		if (houses.Box_Collision(glm::vec3(-8.0332, 0.5f, 42.8628), glm::vec3(1.25f, 0.6f, 1.25f), pos))
			return true;*/
	if (!a[0])
		if (houses.Cylinder_Collision(glm::vec3(11.2818f, 0.5f, 39.819f), pos, 1.0f, 2.1f))
			return true;
	if (!a[1])
		if (houses.Cylinder_Collision(glm::vec3(-24.599, 0.5f, 4.6097), pos, 1.0f, 2.1f))
			return true;
	if (!a[2])
		if (houses.Cylinder_Collision(glm::vec3(-8.0332, 0.5f, 42.8628), pos, 1.0f, 2.1f))
			return true;
	//check collision with buildigs
	if (col::collision(pos,0.3f))
		return true;

	//check limit of map
	if (pos.z < 78.0f && pos.z>-5.0f && pos.x<20.0f && pos.x>-40.0f)
		return false;
	else
		return true;
}

bool col::for_bullets_with_houses(glm::vec3 pos)
{
	if (col::collision(pos,1.0f))
		return true;
	if (pos.y < 0)
		return true;
	if (pos.z < 80.0f && pos.z>-5.0f && pos.x<20.0f && pos.x>-40.0f)
		return false;
	else
		return true;
}

int col::target_collision(glm::vec3 pos,bool a[3])
{
	if (!a[0])
		if (houses.Cylinder_Collision(glm::vec3(11.2818f, 0.5f, 39.819f), pos,1.0f,1.1f))
			return 1;
	/*if(!a[0])
		if (houses.Box_Collision(glm::vec3(11.2818f, 0.5f, 39.819f), glm::vec3(1.25f, 0.6f, 1.25f), pos))
			return 1;
	if(!a[1])
		if (houses.Box_Collision(glm::vec3(-24.599, 0.5f, 4.6097), glm::vec3(1.25f, 0.6f, 1.25f), pos))
			return 2;
	if(!a[2])
		if (houses.Box_Collision(glm::vec3(-8.0332, 0.5f, 42.8628), glm::vec3(1.25f, 0.6f, 1.25f), pos))
			return 3;*/
	if (!a[0])
		if (houses.Cylinder_Collision(glm::vec3(11.2818f, 0.5f, 39.819f), pos, 1.0f, 1.1f))
			return 1;
	if (!a[1])
		if (houses.Cylinder_Collision(glm::vec3(-24.599, 0.5f, 4.6097), pos, 1.0f, 1.1f))
			return 2;
	if (!a[2])
		if (houses.Cylinder_Collision(glm::vec3(-8.0332, 0.5f, 42.8628), pos, 1.0f, 1.1f))
			return 3;
	return 0;
}