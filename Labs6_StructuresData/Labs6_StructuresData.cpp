#include <string>
#include <stack>
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <list>
#include <map>


int task1(std::string s)
{

	std::stack<int> p;
	if (s.size() == 1)
	{
		std::cout << "NO";
		return 0;
	}
	if (s[0] == ')' || s[0] == '}' || s[0] == ']')
	{
		std::cout << "NO";
		return 0;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			p.push(s[i]);
		}
		else {
			if (s[i] == ')' && !p.empty() && p.top() == '(') {
				p.pop();
			}
			else if (s[i] == '}' && !p.empty() && p.top() == '{') {
				p.pop();
			}
			else if (s[i] == ']' && !p.empty() && p.top() == '[') {
				p.pop();
			}
			else if ((s[i] == '}' || s[i] == ')' || s[i] == ']') && p.empty()) {
				p.push(i);
				break;
			}
		}
	}
	std::cout << (p.empty() ? "YES" : "NO");
	return 0;
}

void task2(std::string s)
{
	std::deque<char> d;
	for (int i = 0; i < s.size(); i++)
	{
		d.push_back(s[i]);
	}
	while (!d.empty() && d.size() != 1 && d.front() == d.back())
	{
		d.pop_back();
		d.pop_front();
	}
	std::cout << (d.empty() || d.size() == 1 ? "Палиндром " : "Не палиндром ");
}

bool task3_if(int n)
{
	if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
	{
		return true;
	}
	else
		return false;
}

void task3()
{
	int size1;
	std::cin >> size1;
	std::queue<int>q1;
	for (int i = 1; i < size1; i++)
	{
		if (task3_if(i))
			q1.push(i);
	}
	while (!q1.empty())
	{
		std::cout << q1.front() << std::endl;
		q1.pop();
	}
}

void task4(std::string s)
{
	int size1;
	std::cin >> size1;
	std::queue<int>q1;
	for (int i = 1; i < size1; i++)
	{
		if (task3_if(i))
			q1.push(i);
	}
	while (!q1.empty())
	{
		std::cout << q1.front() << std::endl;
		q1.pop();
	}
}

void task5(std::string s)
{
	int size1;
	std::cin >> size1;
	std::queue<int>q1;
	for (int i = 1; i < size1; i++)
	{
		if (task3_if(i))
			q1.push(i);
	}
	while (!q1.empty())
	{
		std::cout << q1.front() << std::endl;
		q1.pop();
	}
}

void task6(std::string s)
{
	int size1;
	std::cin >> size1;
	std::queue<int>q1;
	for (int i = 1; i < size1; i++)
	{
		if (task3_if(i))
			q1.push(i);
	}
	while (!q1.empty())
	{
		std::cout << q1.front() << std::endl;
		q1.pop();
	}
}

int main() {

	std::string s;
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	while (true)
	{
		std::cout << "Что вы хотите выполнить? \n"
			<< "1. \n"
			<< "2. \n"
			<< "3. \n"
			<< "4. \n"
			<< "5. \n"
			<< "6. \n";
		std::cin >> choice;
		std::cin >> s;
		switch (choice)
		{
		case 1:
		{
			task1(s);
			break;
		}
		case 2:
		{
			task2(s);
			break;
		}
		case 3:
		{
			task3();
			break;
		}
		case 4:
		{
			task4(s);
			break;
		}
		case 5:
		{
			task5(s);
			break;
		}
		case 6:
		{
			task6(s);
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
}