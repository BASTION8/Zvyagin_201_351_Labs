#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void write(int*& arr, int* len)
{
	cout << "Введите длину массива:" << endl;
	cin >> *len;
	arr = new int[*len];
	cout << "Введите элементы массива:" << endl;
	for (int i = 0; i < *len; i++)
	{
		cin >> arr[i];
	}
}

void print(int* arr, const int& len) 
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int schet(int a) // функция для определения количества разрядов каждого элемента массива
{
	int count = 0;
	while (a > 0)
	{
		count++;
		a /= 10;
	}
	return count;
}

int even_digit_sum(const int& elem)
{
	int sum = 0;
	int elem0 = elem;
	int R = schet(elem0);
	if (R % 2 != 0) // если количество разрядов нечетно, то отбрасываем последний
	{
		elem0 /= 10;
	}
	while (elem0 > 0) {
		sum += elem0 % 10; // считаем сумму четных разрядов, счет с левого края, начиная с 1
		elem0 /= 100;
	}
	return sum;
}

void even_digit_bubble_sort(int* &arr, const int& len)
{
	bool swap;
	int g = 0;
	do
	{
		swap = false;
		for (int j = 0; j < len - 1; j++) {
			if (even_digit_sum(arr[j]) > even_digit_sum(arr[j + 1]))
			{
				swap = true;
				g = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = g;
			}
		}
	}
	while (swap);
	print(arr, len);
}

void task4(int*& arr, const int& len)
{
	int g;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] % 10 > arr[j + 1] % 10)
			{
				g = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = g;
			}
		}
	}
	for (int j = 0; j < len - 1; j++)
	{
		if (arr[j] % 10 == arr[j + 1] % 10)
		{
			for (int k = 0; k < len - 1; k++)
			{
				for (int l = 0; l < len - k - 1; l++)
				{
					if (arr[l] < arr[l + 1])
					{
						g = arr[l];
						arr[l] = arr[l + 1];
						arr[l + 1] = g;
					}
				}
			}
		}
	}
	print(arr, len);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	int len = 0;
	int* arr = new int[len];
	while (true)
	{
		cout << "Что вы хотите выполнить?\n"
			<< "1. Ввод массива\n"
			<< "2. Вывод массива в консоль\n"
			<< "3. Сортировка по сумме цифр, стоящих на четных местах\n"
			<< "4. Сортировка массива по возрастанию последней цифры, при совпадении последних цифр - по убыванию\n"
			<< "5. Выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			write(arr, &len);
			break;
		}
		case 2:
		{
			print(arr, len);
			break;
		}
		case 3:
		{
			even_digit_bubble_sort(arr, len);
			break;
		}
		case 4:
		{
			task4(arr, len);
			break;
		}
		default:
		{
			delete[] arr;
			return 0;
		}
		}
	}
}

