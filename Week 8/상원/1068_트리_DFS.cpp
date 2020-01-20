#include<iostream>
#include<vector>
using namespace std;
#define MAX 51

int N;
int val;
int RootNode;
vector<int> V[MAX]; // �׷��� ���� ��������Ʈ 
int DeleteNode;
int cnt = 0;
int Check[MAX]; // ���� �湮 ���� ���� �迭 

// DFS�� Ž�� ���� 
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
			RootNode = i; // ��Ʈ��� 
		else
		{// ����� �׷����� Ʈ������ 
			V[val].push_back(i);
			V[i].push_back(val);
		}

	}
	cin >> DeleteNode;
	Check[DeleteNode] = 1;
	// ���� ��尡 ��Ʈ ��尡 �ƴϸ� Ž�� 
	if (!Check[RootNode])
	{
		DFS(RootNode);
	}
	cout << cnt << "\n";
	return 0;
}