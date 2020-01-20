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

	// ���ϴ� ����
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		q.push(temp);
	}
	int num = 1;
	// ó�� ���ϴ� ���ڿ� ���� ó��
	for (int i = 0; i < q.front(); i++)
	{
		s.push(num++);
		result += '+';
	}

	// ó�����ϴ� ���ڸ� ó�������Ƿ� pop
	result += '-';
	q.pop();
	s.pop();

	bool check = false;
	while (1)
	{
		if (q.empty())
			break;

		int pos = q.front();

		// ������ ����ų� ���� ������ top���� ���ϴ� ���ڰ� Ŭ ��� push 
		if (s.empty() || pos > s.top())
		{
			s.push(num++);
			result += '+';
		}

		// ���� ���ϴ� ���ڰ� ������ top�� ��� pop
		else if (pos == s.top())
		{
			result += '-';
			q.pop();
			s.pop();
		}
		// �Ұ����� ��� : ������ϴ� ���ڰ� ������ top���� �۴�.
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