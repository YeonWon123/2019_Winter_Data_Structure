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

	//�켱���� ť���� ���� ������ ���밪�� ���� ������� �̾ƾ� �ϹǷ� 
	// pair�� �Ἥ pq�� �����Ѵ�.
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int cmd;
		cin >> cmd;
		// cmd�� 0�̰� pq�� �ƹ��͵� ���� ��
		if (cmd == 0 && pq.empty())
		{
			cout << 0 << "\n";
		}

		// cmd�� 0�̰� pq.empty() = 0 �϶�
		else if (cmd == 0)
		{
			// ���밪�� �������� ������������ �����Ƿ� 
			// pq.top().second() 
			cout << pq.top().second << "\n";
			pq.pop();
		}

		// �׿� 
		else
			pq.push({ abs(cmd),cmd }); // pair�� ù��°�� ���� , �ι�°�� ������
									  
	}

}
