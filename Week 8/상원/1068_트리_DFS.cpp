#include<iostream>
#include<vector>
using namespace std;
#define MAX 51

int N;
int val;
int RootNode;
vector<int> V[MAX]; // 그래프 저장 인접리스트 
int DeleteNode;
int cnt = 0;
int Check[MAX]; // 정점 방문 여부 저장 배열 

// DFS로 탐색 시작 
void DFS(int node)
{
	Check[node] = 1;
	bool chk = true;
	for (int i = 0; i < V[node].size(); i++)
	{
		if (!Check[V[node][i]])
		{
			DFS(V[node][i]);
			chk = false;
		}
	}
	if (chk)
		cnt++;
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> val;
		if (val == -1)
			RootNode = i; // 루트노드 
		else
		{// 양방향 그래프로 트리만듬 
			V[val].push_back(i);
			V[i].push_back(val);
		}

	}
	cin >> DeleteNode;
	Check[DeleteNode] = 1;
	// 지운 노드가 루트 노드가 아니면 탐색 
	if (!Check[RootNode])
	{
		DFS(RootNode);
	}
	cout << cnt << "\n";
	return 0;
}