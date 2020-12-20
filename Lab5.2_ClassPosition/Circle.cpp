#include "Circle.h"

Circle::Circle() : Position()
{
	radius = 0;
}

Circle::Circle(int l_x, int l_y, int l_rad) : Position(l_x, l_y)
{
	radius = l_rad;
}

Circle::~Circle()
{
}

int Circle::get_rad()
{
	return radius;
}

void Circle::change_len_rad(int l_rad)
{
	radius = l_rad;
}
