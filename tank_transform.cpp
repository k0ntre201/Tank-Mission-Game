#include "tank_transform.h"

const float pi = 3.14159265358979323846;

float Tank_transform::speed = 0.00f;

Tank_transform::Tank_transform()
{
	posx = posy = rotx = roty=angle=radian=angle_y = 0.0f;
}

float Tank_transform::to_radian(float &angle)
{
	return angle* pi/ 180;
}