#include <ctime>
#include <string>
#include <stack>
#include <iostream>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_set>

int task1()
{
	std::string s;
	std::cout << "Введите строку:" << std::endl;
	std::cin >> s;
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

void task2()
{
	std::string s;
	std::cout << "Введите строку:" << std::endl;
	std::cin >> s;
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

int min_task3(int a1, int a2, int a3)
{
	if ((a1 <= a2) and (a1 <= a3))
	{
		return a1;
	}
	if ((a2 <= a1) and (a2 <= a3))
	{
		return a2;
	}
	if ((a3 <= a2) and (a3 <= a1))
	{
		return a3;
	}
}

void add_print_task3(int t, std::queue<int>& q2, std::queue<int>& q3, std::queue<int>& q5)
{
	if (t != 1)
	{
		std::cout << t << ' ';
	}
	q2.push(t * 2); 
	q3.push(t * 3); 
	q5.push(t * 5); 
}

void task3()
{
	std::cout << "Введите число:\n";
	int n;
	std::cin >> n;
	std::queue<int> q2,q3,q5;
	q2.push(2);
	q3.push(3);
	q5.push(5);
	int k = 0;
	while (k != n)
	{
		int x = min_task3(q2.front(), q3.front(), q5.front());
		add_print_task3(x, q2, q3, q5);
		k++;
		if (x == q2.front())
			q2.pop();
		if (x == q3.front())
			q3.pop();
		if (x == q5.front())
			q5.pop();
	}
}

void task4()
{
	std::set<std::string> logs;
	std::vector<std::string> logs_mark;
	int num;
	int size = 0;
	std::string mark; // оценка студента 
	std::string log; // номер студента

	std::cout << "Введите количество студентов:" << std::endl;
	std::cin >> num;
	std::cout << "Введите журнал и оценку для каждого студента:" << std::endl;
	for (int i = 0; i < num; i++)
	{
		std::cin >> log >> mark;
		logs.insert(log);
		if (logs.size() > size) // Условие, при котором будет сфомирована оценка
		{
			logs_mark.push_back(log + " - " + mark);
		}
		size = logs.size();
	}
	std::cout << "Журнал - оценка:" << std::endl;
	for (int i = 0; i < logs_mark.size(); i++) // Цикл вывода номера студента и его оценки
	{
		std::cout << logs_mark[i] << std::endl;
	}
}

void task5()
{
	std::map<std::string, int> all_words; 

	char text[1000];
	getchar();
	std::cin.getline(text, sizeof(text)); 
	char s[] = " ,\t\n"; 
	char* remained_text = NULL; 
	char* word = strtok_s(text, s, &remained_text); 

	int words_count = 0; 
	while (word != NULL) 
	{
		all_words[word]++;
		words_count++;

		word = strtok_s(NULL, s, &remained_text);
	}
	std::cout << "\n\n";

	for (auto& word : all_words)
	{
		std::cout << word.second << " " << word.first << " (" << (double)word.second / words_count * 100 << "%)" << std::endl;
	}
}

class student
{
public:

	student(std::string gr, std::string ln)
	{
		group = gr;
		last_name = ln;
	}

	std::string group;
	std::string last_name;

	friend std::ostream& operator << (std::ostream& os, student& st)
	{
		os << st.group << " " << st.last_name;

		return os;
	}
};

void task6()
{
	int n = 20;
	srand(time(0));
	std::list<student> students;
	std::vector<std::string> keys;

	std::string names[] = { "Вася", "Коля", "Максим", "Артём", "Илья", "Лена" };
	int length = sizeof(names) / sizeof(names[0]);

	for (int i = 0; i < n; i++)
	{
		students.push_back(student("201-30" + std::to_string(rand() % 5), names[rand() % length] + "(" + std::to_string(i + 1) + ")"));

		std::cout << students.back() << std::endl;
	}
	std::cout << "\n\n";
	for (auto& i : students)
	{
		std::string key = i.group;
		bool b = false; 

		for (auto& st : students)
		{

			if (find(keys.begin(), keys.end(), key) == keys.end() && st.group == key)
			{
				std::cout << st << std::endl;
				b = true;
			}
		}
		keys.push_back(key);

		if (b)
			std::cout << std::endl;
	}
}

int main()
{	
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
		case 4:
		{
			task4();
			break;
		}
		case 5:
		{
			task5();
			break;
		}
		case 6:
		{
			task6();
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
}