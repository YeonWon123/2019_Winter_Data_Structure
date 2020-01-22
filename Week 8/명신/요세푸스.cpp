#include<iostream>
#include<queue>
using namespace std;

//Queue�� �̿��� �似Ǫ�� ����Ǯ��
int main()
{
	int num, space;
	cin >> num >> space;
	queue<int> q;
	
	for (int i = 0; i < num; i++)
	{
		q.push(i + 1);
	}

	//��½���
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
ó���� vector�� �̿��Ϸ� ������ ���ͳ��� �ؼ��� ���� queue�� ����ϸ� �ξ� �����ϰ�
������ �ذ� �� �� ������ ���޾Ҵ�. queue�� ����ϸ� ���ﰣ�ݸ�ŭ ���� ������ �ٽ� �ڷ� �־��ְ�
���ﰪ�鸸 pop���� ������ �ȴ�. �̷��ԵǸ�
size�� �Ѿ ��츦 ���� ����� �� �ʿ䰡 ���Եȴ�.
*/