#pragma once

class Position
{
protected:
	int x;
	int y;
public:
	Position();
	Position(int l_x, int l_y);
	~Position();

	int get_x();
	int get_y();
	void change_coords(int l_x, int l_y);
};
