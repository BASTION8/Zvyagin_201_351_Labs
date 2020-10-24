#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void sort(int* arr, int len)
{
	int h = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				h = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = h;
			}
		}
	}
}

void write(int* &arr, int* &arr0, int* &arr4, int* len)
{
	cout << "Введите длину массива:" << endl;
	cin >> *len;
	arr = new int[*len];
	arr0 = new int[*len];
	arr4 = new int[*len];
	cout << "Введите элементы массива:" << endl;
	for (int i = 0; i < *len; i++)
	{
		cin >> arr[i];
		arr0[i] = arr[i];
		arr4[i] = arr[i];
	}
}

void print(int* arr, int len)
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

void task3(int* &arr, int* &arr0, int len)
{
	int sum = 0;
	int G = 0;
	for (int i = 0; i < len; i++) {
		int R = schet(arr[i]);
		if (R % 2 != 0) // если количество разрядов нечетно, то отбрасываем последний
		{
			arr[i] /= 10;
		}
		while (arr[i] > 0) {
			sum += arr[i] % 10; // считаем сумму четных разрядов, счет с левого края, начиная с 1
			arr[i] /= 100;
		}
		arr[i] = sum;
		sum = 0;
	}
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				G = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = G;
			}
		}
	}
	print(arr, len);
	for (int i = 0; i < len; i++)
	{
		arr[i] = arr0[i];
	}
}

void task4(int* &arr4, int len)
{
	int G;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr4[j] % 10 > arr4[j + 1] % 10)
			{
				G = arr4[j];
				arr4[j] = arr4[j + 1];
				arr4[j + 1] = G;
			}
		}
	}
		for (int j = 0; j < len - 1; j++)
		{
			if (arr4[j] % 10 == arr4[j + 1] % 10)
			{
				for (int k = 0; k < len - 1; k++)
				{
					for (int l = 0; l < len - k - 1; l++)
					{
						if (arr4[l] < arr4[l + 1])
						{
							G = arr4[l];
							arr4[l] = arr4[l + 1];
							arr4[l + 1] = G;
						}
					}
				}
			}
		}
	print(arr4, len);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	int len = 0;
	int* arr = new int[len];
	int* arr0 = new int[len];
	int* arr4 = new int[len];
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
				write(arr, arr0, arr4, &len);
				break;
			}
		case 2:
			{
				print(arr, len);
				break;
			}
		case 3:
			{
				task3(arr, arr0, len);
				break;
			}
		case 4:
			{
				task4(arr4, len);
				break;
			}
		default:
			{
				delete[] arr;
				delete[] arr0;
				delete[] arr4;
				return 0;
			}
		}
	}
}

