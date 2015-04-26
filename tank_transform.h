#ifndef TANK_TRANSFORRM
#define TANK_TRANSFORRM

class Tank_transform
{
public:
	Tank_transform();
	float posx, posy,rotx,roty,angle,radian,angle_y;
	float to_radian(float &angle);
	static float speed;

private:

};

#endif