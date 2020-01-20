#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX 51
int N;
int RootNode;
int DeleteNode;
int val;
vector<int> V[MAX]; // 그래프 저장 인접리스트 
bool visit[MAX]; // 정점 방문 여부 저장 배열 
int cnt = 0;

// BFS로 탐색 시작 
void BFS(int start)
{
	visit[start] = true;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		// 자식숫자 계산 변수 
		int childCount = 0;
		for (int i = 0; i < V[node].size(); i++)
		{
			int next = V[node][i];
			if (!visit[next])
			{
				childCount++;
				visit[next] = true;
				q.push(next);
			}
		}
		// 자식 없으면 단말 노드 개수 증가
		if (childCount == 0)
		{
			cnt++;
		}
	}
}
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> val;
		if (val != -1)
		{// 양방향 그래프로 트리 만듬
			V[val].push_back(i);
			V[i].push_back(val);
		}
		else
			RootNode = i; // 루트노드 
	}
	
	cin >> DeleteNode;

	visit[DeleteNode] = true;
	// 지워진 노드가 루트 노드가 아니면 탐색 시작 
	if (!visit[RootNode])
	{
		BFS(RootNode);
	}
	cout << cnt;
	return 0;
}
