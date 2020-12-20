#pragma once
#include "Circle.h"
#include "Square.h"

class CircleInSquare :
	public Circle, public Square
{
public:
	CircleInSquare();
	CircleInSquare(int l_x, int l_y, int l_rad, int l_len);
	~CircleInSquare();
	
};

