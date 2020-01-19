#include<iostream>
#include<queue>
using namespace std;

//Queue를 이용한 요세푸스 문제풀이
int main()
{
	int num, space;
	cin >> num >> space;
	queue<int> q;
	
	for (int i = 0; i < num; i++)
	{
		q.push(i + 1);
	}

	//출력시작
	cout << "<";
	if (num == 1)
	{
		cout << num << ">";
	}
	else {
		while (q.size())
		{

			for (int i = 0; i < space - 1; i++)
			{
				q.push(q.front());
				q.pop();
			}
			cout << q.front() << ", ";
			q.pop();

			if (q.size() == 1)
			{
				cout << q.front() << ">";
				q.pop();
			}
		}
	}
}

/*
처음엔 vector를 이용하려 했지만 인터넷의 해설을 보고 queue를 사용하면 훨씬 간단하게
문제를 해결 할 수 있음을 깨달았다. queue를 사용하면 지울간격만큼 앞의 값들을 다시 뒤로 넣어주고
지울값들만 pop으로 빼내면 된다. 이렇게되면
size를 넘어간 경우를 굳이 고려해 줄 필요가 없게된다.
*/