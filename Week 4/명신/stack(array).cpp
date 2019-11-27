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
	void push(SData d);	//정수 X를 스택에 넣는 연산이다.
	SData pop();	//스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
	int size();		//스택에 들어있는 정수의 개수를 출력한다.
	int empty();	//스택이 비어있으면 1, 아니면 0을 출력한다.
	SData top();	//스택의 가장 위에 있는 정수를 출력한다.만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
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

void Stack::push(SData d) //정수 X를 스택에 넣는 연산이다.
{
	topindex++;
	numofData++;
	arr[topindex] = d;
}

SData Stack::pop()//스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다.만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
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

int Stack::size()//스택에 들어있는 정수의 개수를 출력한다.
{
	return numofData;
}

int Stack::empty()//스택이 비어있으면 1, 아니면 0을 출력한다.
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

SData Stack::top()//스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
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