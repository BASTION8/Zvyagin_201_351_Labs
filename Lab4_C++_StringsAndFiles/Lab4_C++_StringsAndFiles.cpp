#include <iostream>
#include <string>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios_base;
// пример строки:   D:\Some\Thing\Something\sometext.txt
void input_string(string * file_path_full) // производит ввод строки с клавиатуры
{
	cout << "Введите полное расположения файла:" << endl;
	getchar();
	getline(cin, *file_path_full);
}

void output_string(const string *file_path_full)  // выводит полное расположение файла на экран
{
	cout << * file_path_full << endl;
}

string file_format(const string * file_path_full) // по введенному полному расположению файла получает расширение
{
	string expansion;
	const int number = (*file_path_full).find_last_of('.');
	expansion.append((*file_path_full), number + 1);
	return expansion;
}

string file_name(const string * file_path_full) // по введенному полному расположению файла получает название
{
	string name;
	const int number = (*file_path_full).find_last_of('\\');
	name.append((*file_path_full), number + 1);
	return name;
}

string file_path(const string * file_path_full) // по введенному полному расположению файла получает расположение
{
	string short_path;
	int number = (*file_path_full).find_last_of('\\');
	number = (*file_path_full).find_last_of('\\', number - 1);
	short_path.append((*file_path_full), number);
	return short_path;
}

char file_disk(const string * file_path_full) // по введенному полному расположению файла получает название диска
{
	const int number = (*file_path_full).find_last_of(':');
	return (*file_path_full)[number - 1];
}

bool file_rename(string * file_path_full) // по введенному полному расположению файла и новому имени переименовывает файл
{
	string rename;
	cout << "Введите новое имя:" << endl;
	getchar();
	do
		getline(cin, rename);
	while (rename.find('.') == -1);
	const int number = (*file_path_full).find_last_of('\\');
	(*file_path_full).replace(number + 1, (*file_path_full).size(), rename);
	return true;
}

string file_path_copy(const string* file_path_full) // создает путь к копии файла, основываясь на изначальном пути файла(в одном каталоге)
{
	string name_path_copy = *file_path_full;
	const int number = (*file_path_full).find_last_of('.');
	name_path_copy.insert(number, "_copy");
	return name_path_copy;
}

bool file_copy(const string* file_path_full) // по введенному полному расположению файла создает копию файла(имя копии получается приписыванием  «_copy» к имени файла)
{
	char * buf;
	int len = 256;
	ifstream in(*file_path_full, ios_base::in);
	ofstream out(file_path_copy(file_path_full), ios_base::out);
	if (!in || !out)
		return false;
	buf = new char[len];
	while (!in.eof())
	{
		in.read(buf, len);
		if (in.gcount()) // используем gcount() для проверки что-то считалось в прошлый раз
			out.write(buf, in.gcount());
	}
	in.close();
	out.close();
	delete[] buf;
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	string file_path_full;
	while (true)
	{
		cout << "Что вы хотите выполнить?\n"
			<< "0. Ввод полного расположения файла с клавиатуры\n"
			<< "1. По введенному полному расположению файла получить расширение\n"
			<< "2. По введенному полному расположению файла получить название\n"
			<< "3. По введенному полному расположению файла получить расположение\n"
			<< "4. По введенному полному расположению файла получить название диска\n"
			<< "5. По введенному полному расположению файла и новому имени переименовать файл\n"
			<< "6. По введенному полному расположению файла создать копию файла\n"
			<< "7. Вывести полное расположение файла\n"
			<< "8. Выход\n";
		cin >> choice;
		switch (choice)
		{
		case 0:
			{
				input_string(&file_path_full);
				break;
			}
		case 1:
			{
				cout << file_format(&file_path_full) << endl;
				break;
			}
		case 2:
			{
				cout << file_name(&file_path_full) << endl;
				break;
			}
		case 3:
			{
				cout << file_path(&file_path_full) << endl;
				break;
			}
		case 4:
			{
				cout << file_disk(&file_path_full) << endl;
				break;
			}
		case 5:
			{
				cout << file_rename(&file_path_full) << endl;
				break;
			}
		case 6:
			{
				cout << file_copy(&file_path_full) << endl;
				break;
			}
		case 7:
			{
				output_string(&file_path_full);
				break;
			}
		default:
			{
				return 0;
			}
		}
	}
}


