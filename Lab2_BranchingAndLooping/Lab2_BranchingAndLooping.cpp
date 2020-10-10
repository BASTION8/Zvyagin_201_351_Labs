#include <iostream>
using std::cin;
using std::cout;
using std::endl;
double fact(int n)
{
	double f = 1;
	for (int i = 1; i <= n; i++)
	{
		f *= i;
	}
	return f;
}
void task1()
{
	int n;
	cin >> n;
	for(int j = 0; j <= n; j++)
	{
		cout << endl;
		for (int i = 0; i <= j; i++)
		{
			cout << i;
		}
	}
	cout << endl;
}
void task2()
{
	int n;
	cin >> n;
	for (int k = 0; k <= n; k++)
	{
		cout << fact(n) / (fact(n - k) * fact(k)) << " ";
	}
}
void task3()
{
	double n;
	double sr = 0;
	int i = 0;
	do
	{
		cin >> n;
		if (n == 1.7e+308)
		{
			if (i != 0)
			{
				cout << sr / i << endl;
				break;
			}
			else
			{
				cout << 0;
				break;
			}
		}
		else
		{
			sr += n;
			i++;
		}
	}
	while (true);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	while (true)
	{
		cout << "Что вы хотите выполнить? \n"
			<< "1. Числовой треугольник\n"
			<< "2. Нахождение биномиальных коэффициентов\n"
			<< "3. Вычисление среднего арифметического введенных точек на прямой, заданных своими координатами\n"
			<< "4. Выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			{
				task1();
				break;
			}
		case 2:
			{
				task2();
				break;
			}
		case 3:
			{
				task3();
				break;
			}
		default:
			{
				return 0;
			}
		}
	}
}
