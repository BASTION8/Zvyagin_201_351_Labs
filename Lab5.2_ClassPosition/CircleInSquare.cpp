#include "CircleInSquare.h"

CircleInSquare::CircleInSquare() : Position()
{
	radius = 0;
	length_side = 0;
}

CircleInSquare::CircleInSquare(int l_x, int l_y, int l_rad, int l_len) : Position(l_x, l_y)
{
	radius = l_rad;
	length_side = l_len;
}

CircleInSquare::~CircleInSquare()
{
}
