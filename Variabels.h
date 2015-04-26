#ifndef VARIABLES_H
#define VARIABLES_H

#include "transform.h"
#include "tank_transform.h"

namespace Variables
{
	struct Tank
	{
		int wight = 1000;
		int height = 600;
		Transform tran;
		Transform tran_up;
		Tank_transform tank_t_prev;
		Tank_transform tank_t;
		float rot_counter = 0.0f;
		float helper = 0.0f;
		glm::vec3 pos;
		int mx, my;
		int mwx = (wight / 2);
		int mwy = (height / 2);
		bool is_press = false;
		bool speed = false;
		bool what1 = false;
		bool what2 = false;
	};
	struct Bullets
	{	
		bool a[3];
		int sh{0};
		int wat{0};
		enum number{ n = 10 };
		int nubber_of_bullets = n;
		glm::vec3 bullet_pos[n];
		glm::vec3 bullet_rot[n];
		bool shoot[n];
		int i;
		float bullet_speed = 0.5f;
		glm::vec3 bullet_tr[n];
		Transform bullet_transform;
		int k{ 3 };
		int licznik{ 0 };
		float gr[n];
	};

	struct Statistic
	{

	};
}


#endif