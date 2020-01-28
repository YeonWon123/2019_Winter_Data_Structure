#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N;
int check[1000] = { 0, };
int idx = 0;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//우선순위 큐에서 값을 뽑을때 절대값이 낮은 순서대로 뽑아야 하므로 
	// pair를 써서 pq를 선언한다.
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int cmd;
		cin >> cmd;
		// cmd가 0이고 pq에 아무것도 없을 때
		if (cmd == 0 && pq.empty())
		{
			cout << 0 << "\n";
		}

		// cmd가 0이고 pq.empty() = 0 일때
		else if (cmd == 0)
		{
			// 절대값을 기준으로 내림차순으로 뽑으므로 
			// pq.top().second() 
			cout << pq.top().second << "\n";
			pq.pop();
		}

		// 그외 
		else
			pq.push({ abs(cmd),cmd }); // pair의 첫번째는 절댓값 , 두번째는 원래값
									  
	}

}
