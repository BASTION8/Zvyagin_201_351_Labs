#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int* task1(int *arr, int len)
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
	return arr;
}

char* task2(char *arr, int len)
{
	const int alph = 26;
	int count[alph] = { 0 };
	int j = 0;
	for (int i = 0; i < len; i++)
	{
		j = int(arr[i] - 'a');
		count[j]++;
	}
	int i = 0;
	j = 0;
	while (j <= alph)
	{
		if (count[j] > 0)
		{
			arr[i] = char(int('a') + j);
			i++;
			count[j]--;
		}
		else
		{
			j++;
		}
	}
	return arr;
}

int* Merge(int *arr, int first, int middle, int last)
{
	int i, j, k;
	int n1 = middle - first + 1;
	int n2 = last - middle;
	int L[500], R[500];
	for (i = 0; i < n1; i++)
	{
		L[i] = arr[first + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = arr[middle + j + 1];
	}
	i = 0, j = 0;
	// сравнение и объединение в новый массив в отсортированном порядке
	for (k = first; i < n1 && j < n2; k++)
	{
		if (L[i] < R[j])
		{
			arr[k] = L[i++];
		}
		else
		{
			arr[k] = R[j++];
		}
	}
	// если в L[] больше элементов чем в R[], то добавляем оставшиеся элементы из L[] в результирующий массив
	while (i < n1)
	{
		arr[k++] = L[i++];
	}
	// если в R[] больше элементов чем в L[], то добавляем оставшиеся элементы из R[] в результирующий массив
	while (j < n2)
	{
		arr[k++] = R[j++];
	}
	return arr;
}

void task3(int *arr, int first, int last)
{
	int middle;
	if (first < last)
	{
		middle = (first + last) / 2;
		task3(arr, first, middle);
		task3(arr, middle + 1, last);
		Merge(arr, first, middle, last);
	}
}

void print_int(int *arr, int len)
{
	cout << "Отсортированный по возрастанию массив:" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}

void print_char(char* arr, int len)
{
	cout << "Отсортированный по возрастанию массив:" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	while (true)
	{
		cout << "Что вы хотите выполнить? \n"
			<< "1. Алгоритм сортировки пузырьком\n"
			<< "2. Алгоритм сортировки подсчетом\n"
			<< "3. Алгоритм сортировки слиянием \n"
			<< "4. Выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			{
				int array1[1000];
				int len;
				cout << "Введите длину массива:" << endl;
				cin >> len;
				cout << "Введите элементы массива:" << endl;
				for (int i = 0; i < len; i++)
				{
					cin >> array1[i];
				}
				task1(array1, len);
				print_int(array1, len);
				break;
			}
		case 2:
			{
				char array1[1000];
				int len;
				cout << "Введите длину массива:" << endl;
				cin >> len;
				cout << "Введите элементы массива:" << endl;
				for (int i = 0; i < len; i++)
				{
					cin >> array1[i];
				}
				task2(array1, len);
				print_char(array1, len);
				break;
			}
		case 3:
			{
				int array1[1000];
				int len;
				cout << "Введите длину массива:" << endl;
				cin >> len;
				cout << "Введите элементы массива:" << endl;
				for (int i = 0; i < len; i++)
				{
					cin >> array1[i];
				}
				task3(array1,0, len - 1);
				print_int(array1, len);
				break;
			}
		default:
			{
				return 0;
			}
		}
	}
}
