#pragma once

class matr
{
private:
	int cols; // количество столбцов
	int rows; // количество строчек
	double* elems; // элементы
public:
	matr();
	~matr();

	bool input();//ввод матрицы с клавиатуры
	void print(); //вывод матрицы в консоль
	double get_elem(int i, int j);
	//прибавляет к текущей матрице, 
	//матрицу, которая указана в аргументе.
	//результат суммы записывается в текущую
	//результат суммы возвращается
	bool sum(const matr* matr2);
	
	//умножает текущую матрицу
	//на матрицу, которая указана в аргументе.
	//результат произведения записывается в текущую
	//результат произведения возвращается
	bool mult(const matr* matr2);

	void mult_by_num(double num); // умножение матрицы на число
	double trace(); // след матрицы
	void null_elem();
	double det(); // определитель матрицы
	int get_columns();
	int get_rows();
};

