#include <iostream>
#include <bitset>
using std::cin;
using std::cout;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, a, b;
    // максимумы и минимумы значений типов данных брал с сайта справочника по с++
    cout << "1.\n" << "Zvyagin Anatoliy Viktorovich, 201-351\n" << "2.\n"
        << "min int = -2147483648, max int = 2147483647, size of int = " << sizeof(int) << "\n"
        << "min unsigned int = 0, max unsigned int = 4294967295, size of unsigned int = " << sizeof(unsigned int) << "\n"
        << "min short = –32768, max short = 32767, size of short = " << sizeof(short) << "\n"
        << "min unsigned short = 0, max unsigned short = 65535, size of unsigned short = " << sizeof(unsigned short) << "\n"
        << "min long = -2147483648, max long = 2147483647, size of long = " << sizeof(long) << "\n"
        << "min long long = -9223372036854775808, max long long = 9223372036854775807, size of long long = " << sizeof(long long) << "\n"
        << "min double = +/- 1.7E-308, max double = 1.7E+308, size of double = " << sizeof(double) << "\n"
        << "min char = -128(0), max char = 127(255), size of char = " << sizeof(char) << "\n"
        << "min bool = 0, max bool = 1, size of bool = " << sizeof(bool) << "\n" << "3.\n";
    cout << "Введите число: ";
    cin >> n;
    cout << "В бинарном виде " << std::bitset<32>(n) << "\n" << "В шестнадцатиричном виде " << std::hex << n << "\n";
    cout << "bool " << bool(n) << "\n" << "double " << double(n) << "\n" << "char " << char(n) << "\n4.\n";
    cout << "Введите коэффициенты a * x = b: ";
    cin >> a >> b;
    cout << a << " * x = " << b << "\nx = " << b << " / " << a << "\nx = " << double(b) / a << "\nОтвет: " << double(b) / a << "\n5.";
    cout << "Введите координаты отрезка на прямой: ";
    cin >> a >> b;
    cout << "Середина отрезка находится в точке с координатой " << double(a + b) / 2;
    return 0;
}