#pragma once
#include "Position.h"
class Square :
    virtual public Position
{
protected:
	int length_side;
public:
	Square();
	Square(int l_x, int l_y, int l_len);
	~Square();

	int get_len();
	void change_len(int l_len);
};

