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

	// 우선순위 큐에서 오름차순으로 뽑으므로 MAX heap을 사용하는 q 선언
	priority_queue<int, vector<int>> q;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int cmd;
		cin >> cmd;
		q.push(cmd);
		// cmd 가 0일 때
		if (cmd == 0)
		{
			// q 사이즈가 1이라면, 0 출력
			
			if (q.size() == 1)
			{
				cout << 0 << "\n";
			}

			// 1이 아니라면 , 오름차순으로 출력 후 pop
			else if (q.size() != 1)
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
	}

	return 0;
}