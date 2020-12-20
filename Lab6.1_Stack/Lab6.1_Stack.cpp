#include <string>
#include <stack>
#include <iostream>

int main() {
	std::stack<int> p;
	std::string s;
	std::cin >> s;
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
}
