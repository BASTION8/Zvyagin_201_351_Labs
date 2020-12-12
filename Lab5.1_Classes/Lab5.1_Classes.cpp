#include <iostream>
#include "matr.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	double ar[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 }; // при желании можно вводить массив с клавиатуры
	matr matrC(4, 3, ar); // также задать с клавиатуры размерность матрицы
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
			<< "10. Вывести матрицу 3\n"
			<< "11. Вывести количество столбцов\n"
			<< "12. Вывести количество строк\n"
			<< "13. Сложение матриц 2\n"
			<< "14. Произведение матриц 2\n"
			<< "15. Ввод 2\n"
			<< "16. Ввод 3\n"
			<< "17. Выход\n";
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
				// вывод с помощью перегрузки
				std::cout << matrA;
				break;
			}
		case 9:
			{
				matrB.print();
				break;
			}
		case 10:
			{
				matrC.print();
				break;
			}
		case 11:
			{
				std::cout << matrA.get_columns() << std::endl;
				break;
			}
		case 12:
			{
				std::cout << matrA.get_rows() << std::endl;
				break;
			}
		// эти функции вызываются для частного массива, но можно поменять, чтобы данные вводились пользователем
		case 13:
		{
			matrA.sum(4, 3, ar);
			std::cout << "A=A+B; A=\n";
			matrA.print();
			break;
		}
		case 14:
		{
			std::cout << "A=A*C; A=\n";
			matrA.mult(4, 3, ar);
			break;
		}
		case 15:
		{
			matrC.input(4, 3);
			std::cout << "С=\n";
			matrC.print();
			break;
		}
		case 16:
		{
			matrC.input(4, 3, ar);
			std::cout << "С=\n";
			matrC.print();
			break;
		}
		default:
			{
				return 0;
			}
		}
	}
}
