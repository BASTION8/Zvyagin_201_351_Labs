#include <iostream>
#include "matr.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	matr matrA, matrB;

	int choice = 0;
	while (true)
	{
		std::cout << "Что вы хотите выполнить? \n"
			<< "1. Ввести матрицу 1\n"
			<< "2. Ввести матрицу 2\n"
			<< "3. Сложение матриц\n"
			<< "4. Умножение матрицы на число\n"
			<< "5. След матрицы\n"
			<< "6. Определитель матрицы\n"
			<< "7. Произведение матриц\n"
			<< "8. Вывести матрицу 1\n"
			<< "9. Вывести матрицу 2\n"
			<< "10. Вывести количество столбцов\n"
			<< "11. Вывести количество строк\n"
			<< "12. Выход\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			{
				matrA.input();
				std::cout << "A=\n";
				matrA.print();
				break;
			}
		case 2:
			{
				matrB.input();
				std::cout << "B=\n";
				matrB.print();
				break;
			}
		case 3:
			{
				matrA.sum(&matrB);
				std::cout << "A=A+B; A=\n";
				matrA.print();
				break;
			}
		case 4:
			{
				int num;
				std::cout << "Введите число на которое умножить матрицу:" << std::endl;
				std::cin >> num;
				matrA.mult_by_num(num);
				matrA.print();
				break;
			}
		case 5:
			{
				std::cout << matrA.trace() << std::endl;
				break;
			}
		case 6:
			{
				std::cout << matrA.det() << std::endl;
				break;
			}
		case 7:
			{
				std::cout << "A=A*B; A=\n";
				matrA.mult(&matrB);
				break;
			}
		case 8:
			{
				matrA.print();
				break;
			}
		case 9:
			{
				matrB.print();
				break;
			}
		case 10:
		{
			std::cout << matrA.get_columns() << std::endl;
			break;
		}
		case 11:
		{
			std::cout << matrA.get_rows() << std::endl;
			break;
		}
		default:
			{
				return 0;
			}
		}
	}
}
