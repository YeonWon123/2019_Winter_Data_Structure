#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

stack<int> s;
queue<int> q;
string result;
int main(void)
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	int N;
	cin >> N;

	// 원하는 순서
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		q.push(temp);
	}
	int num = 1;
	// 처음 원하는 숫자에 대한 처리
	for (int i = 0; i < q.front(); i++)
	{
		s.push(num++);
		result += '+';
	}

	// 처음원하는 숫자를 처리했으므로 pop
	result += '-';
	q.pop();
	s.pop();

	bool check = false;
	while (1)
	{
		if (q.empty())
			break;

		int pos = q.front();

		// 스택이 비었거나 현재 스택의 top보다 원하는 숫자가 클 경우 push 
		if (s.empty() || pos > s.top())
		{
			s.push(num++);
			result += '+';
		}

		// 현재 원하는 숫자가 스택의 top일 경우 pop
		else if (pos == s.top())
		{
			result += '-';
			q.pop();
			s.pop();
		}
		// 불가능한 경우 : 현재원하는 숫자가 스택의 top보다 작다.
		else if (pos < s.top())
		{
			check = true;
			break;
		}

	}
	if (check)
		cout << "NO\n";
	else
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << "\n";
	return 0;
}