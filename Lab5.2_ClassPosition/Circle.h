#pragma once
#include "Position.h"
class Circle :
    virtual public Position
{
protected:
	int radius;
public:
	Circle();
	Circle(int l_x, int l_y, int l_rad);
	~Circle();

	int get_rad();
	void change_len_rad(int l_rad);
};

