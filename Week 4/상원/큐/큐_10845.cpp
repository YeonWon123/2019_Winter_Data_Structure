#include<iostream>
#include<queue>
using namespace std;

queue<int> qu;
int main()
{

	cin.tie(NULL); cout.tie(NULL);
	cin.sync_with_stdio(false);
	string str;
	int N; cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "push")
		{
			int num;
			cin >> num;
			qu.push(num);
		}
		else if (str == "front")
		{
			if (!qu.empty())
			{
				cout << qu.front() << "\n";
			}
			else
			{
				cout << "-1" << "\n";
			}
		}
		else if (str == "back")
		{
			if (!qu.empty())
			{
				cout << qu.back() << "\n";
			}
			else
			{
				cout << "-1" << "\n";
			}
		}
		else if (str == "size")
		{
			cout << qu.size() << "\n";
		}
		else if (str == "empty")
		{
			if (qu.empty())
			{
				cout << "1" << "\n";
			}
			else
			{
				cout << "0" << "\n";
			}
		}
		else if (str == "pop")
		{
			if (!qu.empty())
			{
				cout << qu.front() << "\n";
				qu.pop();
			}
			else
			{
				cout << "-1" << "\n";
			}
		
		}

	}
	return 0;
}