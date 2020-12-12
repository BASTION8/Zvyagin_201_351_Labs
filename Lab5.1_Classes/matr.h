#pragma once
#include <istream>

class matr
{
private:
	int cols; // ���������� ��������
	int rows; // ���������� �������
	double* elems; // ��������
public:
	matr();
	// ���������� ������������
	matr(int i, int j);
	matr(int i, int j, const double* arr);
	
	~matr();

	bool input();//���� ������� � ����������
	void print(); //����� ������� � �������
	double get_elem(int i, int j);
	//���������� � ������� �������, 
	//�������, ������� ������� � ���������.
	//��������� ����� ������������ � �������
	bool sum(const matr* matr2);
	
	//�������� ������� �������
	//�� �������, ������� ������� � ���������.
	//��������� ������������ ������������ � �������
	bool mult(const matr* matr2);

	void mult_by_num(double num); // ��������� ������� �� �����
	double trace(); // ���� �������
	double det(); // ������������ �������
	int get_columns();
	int get_rows();
	// ���������� �������
	bool sum(int i, int j, const double* arr);
	bool mult(int i, int j, const double* arr);
	bool input(int i, int j);
	bool input(int i, int j, double* arr);
	// ���������� ����������
	friend std::istream& operator>> (std::istream& input, matr& matr_input); // ������������� �������� �����
	friend std::ostream& operator<< (std::ostream& output, const matr& matr_output); // ������������� �������� ������
	friend matr& operator+ (const matr& lhs, const matr& rhs);
	friend matr operator- (const matr& lhs, const matr& rhs);
	matr operator- ();
	friend matr operator* (const matr& lhs, const matr& rhs);
	matr operator* (int num);
};

