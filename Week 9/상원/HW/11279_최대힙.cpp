#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(void)
{

	//priority_queue<int, vector<int>> q; MAX heap 
	//priority_queue<int, vector<int>, greater<int>> q2; Min heap
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// �켱���� ť���� ������������ �����Ƿ� MAX heap�� ����ϴ� q ����
	priority_queue<int, vector<int>> q;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int cmd;
		cin >> cmd;
		q.push(cmd);
		// cmd �� 0�� ��
		if (cmd == 0)
		{
			// q ����� 1�̶��, 0 ���
			
			if (q.size() == 1)
			{
				cout << 0 << "\n";
			}

			// 1�� �ƴ϶�� , ������������ ��� �� pop
			else if (q.size() != 1)
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
	}

	return 0;
}