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
	void push(QData d);	// 정수 X를 큐에 넣는 연산이다.
	QData pop();	//큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
	int size();		//큐에 들어있는 정수의 개수를 출력한다.
	int empty();	//큐가 비어있으면 1, 아니면 0을 출력한다.
	QData front();	//큐의 가장 앞에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
	QData back();	//큐의 가장 뒤에 있는 정수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다
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

QData Queue::pop()//큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다.만약 큐에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
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
