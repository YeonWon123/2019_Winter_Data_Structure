#include<iostream>
#include<vector>
using namespace std;
typedef int QData;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

class Queue
{
public:
	Queue();
	void push(QData d);	// ���� X�� ť�� �ִ� �����̴�.
	QData pop();	//ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�.���� ť�� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
	int size();		//ť�� ����ִ� ������ ������ ����Ѵ�.
	int empty();	//ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
	QData front();	//ť�� ���� �տ� �ִ� ������ ����Ѵ�.���� ť�� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
	QData back();	//ť�� ���� �ڿ� �ִ� ������ ����Ѵ�.���� ť�� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�
private:
	int first_index;
	int last_index;
	int numofData;
	QData arr[2000];
};


int main()
{
	Queue s;
	int num;
	int input;
	string name;

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> name;
		if (name == "push")
		{
			cin >> input;
			s.push(input);
		}
		else if (name == "pop")
		{
			cout << s.pop() << endl;
		}
		else if (name == "size")
		{
			cout << s.size() << endl;
		}
		else if (name == "empty")
		{
			cout << s.empty() << endl;
		}
		else if (name == "front")
		{
			cout << s.front() << endl;
		}
		else if (name == "back")
		{
			cout << s.back() << endl;
		}

	}


}

Queue::Queue()
{
	first_index = 0;
	last_index = -1;
	numofData = 0;
}

void Queue::push(QData d)
{
	last_index++;
	numofData++;
	arr[last_index] = d;
	return;
}

QData Queue::pop()//ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�.���� ť�� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
{
	if (last_index - first_index < 0)
	{
		return -1;
	}
	int temp = first_index;
	first_index++;
	numofData--;
	return arr[temp];
}

int Queue::size()
{
	return numofData;
}

int Queue::empty()
{
	if (last_index - first_index < 0) return -1;
	else return 0;
}

QData Queue::front()
{
	if (last_index - first_index < 0) return -1;
	return arr[first_index];
}

QData Queue::back()
{
	if (last_index - first_index < 0) return -1;
	return arr[last_index];
}
