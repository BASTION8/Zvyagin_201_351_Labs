#include "matr.h"
#include <iostream>

matr::matr()
{
	cols = 0;
	rows = 0;
	elems = nullptr;
}

matr::~matr()
{
	if (elems != nullptr)
		delete[] elems;
}
// ���� ������� � ����������
bool matr::input()
{
	std::cout << "������� ���������� �������: ";
	std::cin >> rows;
	std::cout << "������� ���������� ��������: ";
	std::cin >> cols;
	if (elems != nullptr)
		delete[] elems;
	elems = new double[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		std::cin >> elems[i];
		//elems[i] = i * 37 % 10;
	return true;
}
// ����� �������
void matr::print()
{
	for (int i = 0; i < rows;i++)
	{
		for (int j = 0; j < cols; j++)
			std::cout << get_elem(i, j) << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
// �������� i, j ������� �������
double matr::get_elem(int i, int j)
{
	return elems[i * cols + j];
}
// �������� ���� ������
bool matr::sum(const matr* matr2)
{
	if (rows != matr2->rows || cols != matr2->cols)
		return false;
	for (int i = 0; i < rows * cols; i++)
		elems[i] = elems[i] + matr2->elems[i];
	return true;
}
// ��������� ���� ������
bool matr::mult(const matr* matr2)
{
	if (cols != matr2->rows)
		return false;
	matr res;
	res.cols = matr2->cols;
	res.rows = this->rows;
	res.elems = new double[double(res.cols) * res.rows]{ 0 };
	for (int i = 0; i < res.rows; i++)
		for (int j = 0; j < res.cols; j++)
			for (int k = 0; k < this->cols; k++)
				res.elems[i * res.cols + j] += get_elem(i, k) * matr2->elems[k * matr2->cols + j];
	res.print();
	return true;
}
// ��������� ������� �� �����
void matr::mult_by_num(double num)
{
	for (int i = 0; i < rows * cols; i++)
	{
		elems[i] *= num;
	}
}
// ����� ������������ ��������� ���������� ������� (������� ���������)
double matr::trace()
{
	double sum = 0;
	if (rows != cols)
		return sum;
	for (int i = 0; i < rows; i++)
		sum += get_elem(i, i);
	return sum;
}
// ������������ �������
double matr::det()
{
	if (rows != cols)
		return 0;
	double mult = 1;
	for (int i = 1; i < rows; ++i)
		for (int k = i; k < rows; ++k)
			for (int j = rows - 1; j >= 0; --j)
				if (get_elem(i - 1, i - 1) != 0 && get_elem(k, i - 1) != 0 && get_elem(i - 1, j) != 0)
					elems[k * cols + j] -= (get_elem(k, i - 1) / get_elem(i - 1, i - 1) * get_elem(i - 1, j));
	print();
	for (int i = 0; i < rows; i++)
		mult *= get_elem(i, i);
	return mult;
}

int matr::get_columns()
{
	return cols;
}

int matr::get_rows()
{
	return rows;
}