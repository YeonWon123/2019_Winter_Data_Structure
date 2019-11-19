#include<iostream>
using namespace std;
int search(int target, int arr[], int size);	//단순 search함수 시간복잡도 O(n)
int search_recursion(int target, int arr[], int first, int last); //재귀를 이용한 search함수 시간복잡도 0(log2n)

int main()
{ 
	//입력파트
	int case_Num;
	int size1;
	int size2;
	int integer;
	//int note1[1000000] -> error 메모리초과? why? 찾아보니 각 컴퓨터의 하드웨어 마다 임계값이 다르다고 함
	int note1[10000];
	int note2[10000];
	int target;

	cin >> case_Num;

	for (int i = 0; i < case_Num; case_Num++)
	{
		//수첩1에 숫자 저장
		cin >> size1;
		for (int j = 0; j < size1; j++)
		{
			cin >> integer;
			note1[j] = integer;
		}

		//수첩2에 숫자 저장
		cin >> size2;
		for (int j = 0; j < size2; j++)
		{
			cin >> integer;
			note2[j] = integer;
		}
		
		//수첩1,2비교
		for (int i = 0; i < size2; i++)
		{
			target = note2[i];
			if (search(target, note1, size1) == -1)
			{
				cout << "0\n";
			}
			else 
			{
				cout << "1\n";
			}
		}
		
	}

	return 0;
}

int search(int target, int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target) return i;
	}
	return -1;
}
int search_recursion(int target, int arr[], int first, int last)
{
	if (first > last) return -1;
	int mid = (first + last) / 2;

	if (arr[mid] == target) return mid;
	else if (arr[mid] < target)
	{
		first = mid + 1;
		search_recursion(target, arr, first, last);
	}
	else if (arr[mid] > target)
	{
		last = mid - 1;
		search_recursion(target, arr, first, last);
	}
	return -1;
}
