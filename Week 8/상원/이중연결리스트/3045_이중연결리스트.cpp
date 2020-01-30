#include<iostream>
#include<stack>
#include<deque>
#include<vector>
using namespace std;

int N, M;
int arr[1000];
int main(void)
{
	cin >> N >> M;
	deque<int> dq1, dq2;
	stack <int> st1;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dq1.push_back(i); // 1 2 3 4 5 6 
	}

	deque<int>::iterator iter;
	deque<int>::const_iterator conlter = dq1.begin();
	for (iter = dq1.begin(); iter != dq1.end(); iter++)
	{
		cout << *iter << " ";
	}
	int idx = 0;
	int del = 0;
	//dq[0] =1  
	//dq[1] =2

	for (int i = 0; i < M; i++)
	{
		char cmd;
		cin >> cmd;
		if (cmd == 'A')
		{
			int from, to;// 1 4 
			cin >> from >> to;
			int a = from;
			int cnt = 0;
			while (a--)
			{
				conlter++;
				cnt++;
			}
			conlter--;
			cnt--;
			cout << "1. cnt :" << cnt << "\n";
			dq1.erase(conlter);// conlter = dq1.begin()
			// 2 3 4 5 6

			dq1.insert(dq1.begin() + to-2 , from);// to 없으면 1 2 3 4 5 6
			// to 잇으면 2 3 4 5 1 6
			// 바라는 값 2 3 1 4 5 6  
			// 이렇게 하면 2 3 1 4 5 6 
		}
		
		conlter = dq1.begin();

		//dq : 2 3 1 4 5 6 
		if(cmd == 'B')
		{
			int from, to; // 3 5 
			cin >> from >> to;
			int a = from;
			int cnt = 0;
		//	cout << "del:" << del << "\n";
			while (a--)
			{
				conlter++;
				cnt++;
			}
			conlter--; // 
			cout <<"count :"<< cnt-1 << "\n"; // 3 
			dq1.erase(conlter); // 2 3 4 5 6  dq[4]; 
			//dq1.insert(dq1.begin() + to - 2, from);

		}
	}
	for (iter = dq1.begin(); iter != dq1.end(); iter++)
	{
		cout << *iter << " ";
	}

	return 0;
}