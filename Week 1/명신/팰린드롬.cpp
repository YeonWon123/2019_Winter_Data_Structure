#include<iostream>
#include<string>
using namespace std;

int Array_size(string arr);

int main()
{
	//필요한 변수들 생성 및 초기화
	int arrSize;
	bool flag;

	//전체 반복문
	while (1)
	{
		string arr;
		getline(cin, arr);	//공백까지 받아오는 함수
		arrSize = Array_size(arr);
		flag = true;
		for (int i = 0; i < arrSize / 2; i++)
		{
			if (arr[i] != arr[arrSize - 1 - i])
			{
				flag = false;
				break;
			}
		}

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

	int Array_size(string arr)
	{
	
		int arrSize = 0;

		for (int i = 0;; i++)
		{
			if (arr[i] == '\0') break;
			arrSize++;
		}

		return arrSize;
	}
