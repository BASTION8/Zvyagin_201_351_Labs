#pragma once

class matr
{
private:
	int cols; // количество столбцов
	int rows; // количество строчек
	double* elems; // элементы
public:
	matr();
	// перегрузка конструктора
	matr(int i, int j);
	matr(int i, int j, const double* arr);
	
	~matr();

	bool input();//ввод матрицы с клавиатуры
	void print(); //вывод матрицы в консоль
	double get_elem(int i, int j);
	//прибавляет к текущей матрице, 
	//матрицу, которая указана в аргументе.
	//результат суммы записывается в текущую
	bool sum(const matr* matr2);
	
	//умножает текущую матрицу
	//на матрицу, которая указана в аргументе.
	//результат произведения записывается в текущую
	bool mult(const matr* matr2);

	void mult_by_num(double num); // умножение матрицы на число
	double trace(); // след матрицы
	void null_elem();
	double det(); // определитель матрицы
	int get_columns();
	int get_rows();
	// перегрузка функций
	bool sum(int i, int j, const double* arr);
	bool mult(int i, int j, const double* arr);
	bool input(int i, int j);
	bool input(int i, int j, double* arr);
};

