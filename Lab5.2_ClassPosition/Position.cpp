#include "Position.h"
#include <iostream>

Position::Position()
{
	x = 0;
	y = 0;
}

Position::Position(int l_x, int l_y)
{
	x = l_x;
	y = l_y;
}

Position::~Position()
{
}

int Position::get_x()
{
	return x;
}

int Position::get_y()
{
	return y;
}

void Position::change_coords(int l_x, int l_y)
{
	x = l_x;
	y = l_y;
}
