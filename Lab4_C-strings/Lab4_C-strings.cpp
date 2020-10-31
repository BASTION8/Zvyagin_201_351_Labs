#include <iostream>
#include <cstring>
#include <Windows.h>
using std::cin;
using std::cout;
using std::endl;

void write_str(char* str1) // на вход подается строка, функция ничего не возвращает, выполняет ввод строки с клавиатуры
{
	cout << "Введите строку:" << endl;
	getchar();
	cin.getline(str1, 255);
}

void is_palindrom(char* str1)
// на вход подается строка, функция ничего не возвращает, проверяет строку на палиндром
{
	write_str(str1);
	for (int i = 0; i < strlen(str1) / 2; i++)
	{
		if (str1[i] != str1[strlen(str1) - i - 1])
		{
			cout << "Не палиндром" << endl;
			return;
		}
	}
	cout << "Палиндром" << endl;
}

void find(char* str1, char* str2)
// на вход подается строка, функция ничего не возвращает, ищет подстроку в строке
{
	int j = 0;
	int k = 0;
	int l = 0;
	static char str3[255];
	write_str(str1);
	cout << "Введите подстроку:" << endl;
	cin.getline(str2, 255);
	for (int i = 0; i < strlen(str1); i++)
	{
		if (str1[i] == str2[j])
		{
			for (; j < strlen(str2); j++)
			{
				if (str2[j] == str1[i])
				{
					str3[k] = str2[j];
					k++;
					i++;
					l++;
				}
				else
				{
					k -= l;
					for (k + 1; k < strlen(str3); k++)
					{
						str3[k] = NULL;
					}
					k -= l;
					l = 0;
					break;
				}
			}
			j = 0;
			l = 0;
			str3[k] = ' ';
			k++;
		}
	}
	printf("%s\n", str3);
}

void encrypt(char* str1)
// на вход подается строка, функция ничего не возвращает, делает сдвиг строки на ключ, введенный с клавиатуры
{
	int key;
	write_str(str1);
	cout << "Введите число, на которое будет произведен сдвиг:" << endl;
	cin >> key;
	for (int i = 0; i < strlen(str1); i++)
	{
		str1[i] = str1[i] + key;
	}
	printf("%s\n", str1);
}

void task4(char* str1, char* str2)
/*
на вход подается строка, функция ничего не возвращает, ищет кавычку в тексте и, начиная с нее, записывает в строку названия,
как только видит вторую скобку, прекращает записывать и начинает опять искать кавычку, в конце выводит строку с названиями
 */ 
{
	int j = 0;
	write_str(str1);
	for (int i = 0; i < strlen(str1); i++)
	{
		if (str1[i] == '"')
		{
			i++;
			for (; str1[i] != '"'; i++)
			{
				str2[j] = str1[i];
				j++;
			}
			str2[j] = ' ';
			j++;
		}
	}
	printf("%s\n", str2);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	static char str1[255];
	static char str2[255];
	while (true)
	{
		cout << "Что вы хотите выполнить?\n"
			<< "1. Проверка строки на палиндром\n"
			<< "2. Аналог функции find для c++ строк\n"
			<< "3. Шифр Цезаря\n"
			<< "4. Вывод названий из текста\n"
			<< "5. Выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			{
				is_palindrom(str1);
				break;
			}
		case 2:
			{
				find(str1, str2);
				break;
			}
		case 3:
			{
				encrypt(str1);
				break;
			}
		case 4:
			{
				task4(str1, str2);
				break;
			}
		default:
			{
				return 0;
			}
		}
	}
}

