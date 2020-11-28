#pragma once

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
	void null_elem();
	double det(); // ������������ �������
	int get_columns();
	int get_rows();
	// ���������� �������
	bool sum(int i, int j, const double* arr);
	bool mult(int i, int j, const double* arr);
	bool input(int i, int j);
	bool input(int i, int j, double* arr);
};

