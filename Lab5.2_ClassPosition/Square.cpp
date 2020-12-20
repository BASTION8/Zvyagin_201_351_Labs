#include "Square.h"

Square::Square() : Position()
{
	length_side = 0;
}

Square::Square(int l_x, int l_y, int l_len) : Position(l_x, l_y)
{
	length_side = l_len;
}

Square::~Square()
{
}

int Square::get_len()
{
	return length_side;
}

void Square::change_len(int l_len)
{
	length_side = l_len;
}
