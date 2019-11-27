#include<iostream>
#include<vector>
using namespace std;
typedef int SData;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

class Stack
{
public:
	Stack();
	void push(SData d);	//���� X�� ���ÿ� �ִ� �����̴�.
	SData pop();	//���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
	int size();		//���ÿ� ����ִ� ������ ������ ����Ѵ�.
	int empty();	//������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
	SData top();	//������ ���� ���� �ִ� ������ ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
private:
	int topindex;
	int numofData;
	SData arr[2000];
};

Stack::Stack()
{
	topindex = -1;
	numofData = 0;
}

void Stack::push(SData d) //���� X�� ���ÿ� �ִ� �����̴�.
{
	topindex++;
	numofData++;
	arr[topindex] = d;
}

SData Stack::pop()//���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�.���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
{
	if (topindex < 0)
	{
		return -1;
	}
	SData d = arr[topindex];
	topindex--;
	numofData--;
	return d;
}

int Stack::size()//���ÿ� ����ִ� ������ ������ ����Ѵ�.
{
	return numofData;
}

int Stack::empty()//������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
{
	if (numofData > 0)
	{
		cout << "0\n";
		return 0;
	}
	else
	{
		cout << "1\n";
		return 1;
	}
}

SData Stack::top()//������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
{
	if (topindex < 0)
	{
		return -1;
	}
	SData d = arr[topindex];
	return d;
}

int main()
{
	Stack s;
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
			s.empty();
		}
		else if (name == "top")
		{
			cout << s.top() << endl;
		}
	
	}


}