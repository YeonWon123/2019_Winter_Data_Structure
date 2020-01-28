#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �켱���� ť���� ������������ �̾ƾ� �ϹǷ� Min heap �� ����� q ����
	priority_queue<int, vector<int>, greater<int>> q;
	
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int cmd;
		cin >> cmd;
		// cmd�� 0�̰� q �� ����ִٸ� 0���
		if (cmd == 0 && q.empty())
		{
			cout << 0 << "\n";
		}
		// cmd�� 0�̶��, q�� ������������ ��� �� pop
		else if (cmd == 0)
		{
			cout << q.top() << "\n";
			q.pop();
		}
		// �ƴ϶�� push 
		else
			q.push(cmd);
		
	}

}