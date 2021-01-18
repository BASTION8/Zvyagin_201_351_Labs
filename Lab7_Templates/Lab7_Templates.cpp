#include <iostream>
#include <string>
#include <ctime>

struct Student
{
	std::string lastName;
    int age;

    Student()
    {
        lastName = "";
        age = 0;
    }
    Student(std::string _lastName, int _age)
    {
        lastName = _lastName;
        age = _age;
    }

    bool operator > (Student p)
    {
        return age > p.age;
    }
    bool operator < (Student p)
    {
        return age < p.age;
    }

    friend std::ostream& operator << (std::ostream& os, Student& p);
};

std::ostream& operator << (std::ostream& os, Student& p)
{
	std::cout << p.lastName << ":" << p.age;

    return std::cout;
}

template <typename T>
void qSort(T* arr, int left, int right)
{
    int i = left;
    int j = right;
    T pivot = arr[(i + j) / 2];
    T temp;

    while (i <= j)
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (j > left) 
        qSort(arr, left, j);
    if (i < right)
        qSort(arr, i, right);
}

template <typename T>
void printArray(T* array, int n)
{
    for (int i = 0; i < n; i++) 
        std::cout << array[i] << "  ";
    std::cout << std::endl;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int n;
    std::cout << "Введите число:";
    std::cin >> n;
    bool* arr = new bool[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 2;

    std::cout << "Перед Quick Sort [bool]:" << std::endl;
    printArray(arr, n);

    qSort(arr, 0, n - 1);

    std::cout << "После Quick Sort [bool]:" << std::endl;
    printArray(arr, n);
    std::cout << "\n\n";

    int* arr1 = new int[n];

    for (int i = 0; i < n; i++)
        arr1[i] = -50 + rand() % 100;

    std::cout << "Перед Quick Sort [int]:" << std::endl;
    printArray(arr1, n);

    qSort(arr1, 0, n - 1);

    std::cout << "После Quick Sort [int]:" << std::endl;
    printArray(arr1, n);
    std::cout << "\n\n";

    double* arr2 = new double[n];

    for (int i = 0; i < n; i++)
        arr2[i] = -1 + (double)rand() / 10000;

    std::cout << "Перед Quick Sort [double]:" << std::endl;
    printArray(arr2, n);

    qSort(arr2, 0, n - 1);

    std::cout << "После Quick Sort [double]:" << std::endl;
    printArray(arr2, n);
    std::cout << "\n\n";

    Student* p = new Student[n];

    for (int i = 0; i < n; i++)
    {
        p[i].lastName = "Имя(" + std::to_string(i) + ")";
        p[i].age = 15 + rand() % 21;
    }

    std::cout << "Перед Quick Sort [Student]:" << std::endl;
    printArray(p, n);

    qSort(p, 0, n - 1);

    std::cout << "После Quick Sort [Student]:" << std::endl;
    printArray(p, n);
}