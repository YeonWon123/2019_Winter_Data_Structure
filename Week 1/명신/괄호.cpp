#include<iostream>
#include<string>
#include<stack>
using namespace std;

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
		stack<char> st;
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

//내가만든 자주 사용하는 함수 어떻게 따로 저장해놓는지

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

/*
stack 사용법
1.#include<stack>	//stack class 받아오기
2.stack<datatype> st(object명)  // datatype의 stack 생성
3. st.push('char')	//stack에 'char'data 집어넣기
	st.pop()	//stack 맨위에 data 꺼내기
	st.empty() //stack 비어있는지 확인 맞으면 true
*/
