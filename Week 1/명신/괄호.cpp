#include<iostream>
#include<string>
using namespace std;

class stack_imake
{
public:
	stack_imake(); //스택 초기화 진행 (스택생성후 젤 먼저 호출되어야 하는 함수)
	void push(char data); //스택에 데이터저장, 매게변수 data로 전달된 값을 저장함
	void pop(); //마지막에 저장된 요소를 삭제, 삭제하는 데이터는 반환됨, 이함수를 호출하려면 하나이상의 값이 스택에 있어야함
	int top(); //마지막에 저장된 요소를 반환하되 삭제하지않음
	bool empty(); //stack이 비어있는지 확인
	~stack_imake();
private:
	//char* cp = new char  //배열을 이렇게 생성하면 runtime_error 왜?
	char* cp = new char[1000];
	int topindex; //-1로 초기화
};

int Array_size(char*arr);

int main()
{
	int size;
	int arrSize;
	bool flag;
	cin >> size;

	//arr[0]부터 arrSize 까지 확인
	for (int i = 0; i < size; i++)
	{
		//사용할 변수 초기화
		stack_imake st;
		char arr[100];
		cin >> arr;		//space,enter 가 나올때까지 입력받음
		arrSize = Array_size(arr);
		flag = true;

		//VPS 검증
		for (int j = 0; j < arrSize; j++)
		{
			// '('이면 push ')'이면pop  단 stack이 empty인 상태에서 pop이면 false
			if (arr[j] == '(')
			{
				st.push('(');
			}
			else if (arr[j] == ')')
			{
				if (st.empty())
				{
					flag = false;
					break;
				}
				else
				{
					st.pop();
				}
			}
		}

		//for문 실행후 st.empty != true 이면 false
		if (!st.empty())
		{
			flag = false;
		}

		//flag true면 YES, 아니면 NO 출력
		if (flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

	}
}

int Array_size(char *arr)
{
	int arrSize = 0;

	for (int i = 0;; i++)
	{
		if (arr[i] == '\0') break;
		arrSize++;
	}

	return arrSize;
}


stack_imake::stack_imake()
{
	topindex = -1;
}
void stack_imake::push(char input)
{
	topindex++;
	cp[topindex] = input;

	return;
}
void stack_imake::pop()
{
	cp[topindex] = '\0';
	topindex--;

	return;
}
int stack_imake::top()
{
	return topindex;
}
bool stack_imake::empty()
{
	if (topindex >= 0) return false;
	else return true;
}
stack_imake::~stack_imake()
{
	delete[] cp;
}