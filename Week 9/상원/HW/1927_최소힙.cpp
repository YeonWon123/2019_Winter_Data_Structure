#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 우선순위 큐에서 내림차순으로 뽑아야 하므로 Min heap 을 사용한 q 선언
	priority_queue<int, vector<int>, greater<int>> q;
	
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int cmd;
		cin >> cmd;
		// cmd가 0이고 q 가 비어있다면 0출력
		if (cmd == 0 && q.empty())
		{
			cout << 0 << "\n";
		}
		// cmd가 0이라면, q를 내림차순으로 출력 후 pop
		else if (cmd == 0)
		{
			cout << q.top() << "\n";
			q.pop();
		}
		// 아니라면 push 
		else
			q.push(cmd);
		
	}

}