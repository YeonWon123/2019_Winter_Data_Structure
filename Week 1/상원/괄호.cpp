#include<iostream>
#include<string>

using namespace std;

// stack 라이브러리 사용
// #include<stack>
/*
bool Check(string str)
{
	
	stack<char> st;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		char s = str[i];
		if (str[i] == '(')
		{
			st.push(str[i]);
		}
		else
		{
			if (!st.empty())
			{
				st.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return st.empty();
}
int main()
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		if (Check(str))
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}

	return 0;
}
*/

char stack[100];
int Top = 0;
void Push(char);
char Pop();
int Empty();
int func(char *);

int main()
{
	int T;
	char str[101];
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> str;

		if (func(str))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}
int func(char *str)
{
	int result = 1;
	for (int i = 0; i < str[i]; i++)
	{
		if (str[i] == '(')
		{
			Push(str[i]);
		}
		else
		{
			if (Empty())
			{
				result = 0;
				break;
			}
			else
			{
				Pop();
			}
		}
		
	}
	if (!Empty())
	{
		result = 0;
	}
	while (!Empty())
	{
		Pop();
	}
	return result;
}

void Push(char c)
{
	stack[Top++] = c;
}
char Pop()
{
	return stack[--Top];
}

int Empty()
{
	//cout << "Empty :" << (Top == 0) << "\n";
	return Top == 0;
}