#include <iostream>
#include "CircleInSquare.h"
#include "Position.h"
#include "Circle.h"
#include "Square.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	CircleInSquare test(5, 5, 5, 5);
	Square test1(5, 10, 10);
	test1.change_coords(50, 50);
	test.get_rad();
	test.change_len(10);
	test.change_coords(99, 99);
	std::cout
		<< test.get_x() << "\t"
		<< test.get_y() << "\t"
		<< test.get_rad() << "\t"
		<< test.get_len();
	return 0;
}