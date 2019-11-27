


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int stack[20000];
int stack_size = 0;

int main() {
	string inp;
	stringstream ss;
	string str;
	
	int N;
	cin >> N;
	for (int i = 0; getline(cin, inp); i++)
	{
		ss = stringstream(inp);

		while (ss >> str) {
			if (str == "push")
			{
				ss >> str;
				stack[stack_size] = stoi(str);
				stack_size++;
			}
			else if (str == "top")
			{
				if (stack_size > 0)
				{
					cout << stack[stack_size - 1] << "\n";
				}
				else
					cout << "-1" << "\n";
			}
			else if (str == "size")
			{
				cout << stack_size << "\n";
			}
			else if (str == "empty")
			{
				cout << (stack_size ? 0 : 1) << "\n";
			}
			else if (str == "pop")
			{
				if (stack_size > 0)
				{
					cout << stack[stack_size - 1] << "\n";
					stack_size--;
				}
				else
					cout << "-1" << "\n";
			}
		}
	}
	return 0;
}
