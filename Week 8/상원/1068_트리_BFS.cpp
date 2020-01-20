#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define MAX 51
int N;
int RootNode;
int DeleteNode;
int val;
vector<int> V[MAX]; // �׷��� ���� ��������Ʈ 
bool visit[MAX]; // ���� �湮 ���� ���� �迭 
int cnt = 0;

// BFS�� Ž�� ���� 
void BFS(int start)
{
	visit[start] = true;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		// �ڽļ��� ��� ���� 
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
		// �ڽ� ������ �ܸ� ��� ���� ����
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
		{// ����� �׷����� Ʈ�� ����
			V[val].push_back(i);
			V[i].push_back(val);
		}
		else
			RootNode = i; // ��Ʈ��� 
	}
	
	cin >> DeleteNode;

	visit[DeleteNode] = true;
	// ������ ��尡 ��Ʈ ��尡 �ƴϸ� Ž�� ���� 
	if (!visit[RootNode])
	{
		BFS(RootNode);
	}
	cout << cnt;
	return 0;
}
