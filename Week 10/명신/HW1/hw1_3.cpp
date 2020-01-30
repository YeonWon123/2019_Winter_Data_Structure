#include "pch.h"				
#include <iostream>
#include <string>
#include <cstdlib>		//시간을 랜덤하게 지정하기위해 사용
#include <ctime>
#include "CCustomer.h"		//클래스를 불러옴
using namespace std;


void insertionSort(CCustomer b[], int n);	//사용자정의타입의 배열을 입력변수로 받는다
void insertNextItem(CCustomer b[], int i);
void quicksort(CCustomer a[], int first, int last);
int partition(CCustomer a[], int first, int last);
void swapElements(CCustomer a[], int v, int x);

int main()
{
	int i;

	CCustomer a[10];			//사용자정의타입의 배열을 지정 후
	a[0].setName("a");			// 이름을 하나하나 넣어주는 모습이다
	a[1].setName("b");
	a[2].setName("c");
	a[3].setName("d");
	a[4].setName("e");
	a[5].setName("f");
	a[6].setName("g");
	a[7].setName("h");
	a[8].setName("i");
	a[9].setName("j");

	for (i = 0; i < 10; i++) {			//그룹명수와 순번을 1~10으로 간단히 지정
		a[i].setnoc(i);
		a[i].setnog(i);
	}
	for (i = 0; i < 10; i++)	//도착시간을 랜덤하게 저장함
	{
		a[i].settime(rand() % 10);
	}

	for (i = 0; i < 10; i++) {	//정렬전
		cout << "순번:" << a[i].getnoc() << "\t그룹인원수:" << a[i].getnog() << "\t도착시간:" << a[i].gettime() << "\t이름:" << a[i].getName() << endl;
	}


	quicksort(a, 0, 9);
	
	cout << endl;

	for (i = 0; i < 10; i++) { //정렬후
		cout << "순번:" << a[i].getnoc() << "\t그룹인원수:" << a[i].getnog() << "\t도착시간:" << a[i].gettime() << "\t이름:" << a[i].getName() << endl;
	}
	cout << endl;
}
void insertionSort(CCustomer a[], int n)	// insertionSort정의부
{
	int i;
	for (i = 1; i < n; i++)
		insertNextItem(a, i);
}

void insertNextItem(CCustomer a[], int i)
{
	CCustomer newItem = a[i];
	int insertPos = i;
	for (; insertPos && newItem < a[insertPos - 1]; insertPos--)
		a[insertPos] = a[insertPos - 1];
	a[insertPos] = newItem;
}

void quicksort(CCustomer a[], int first, int last)	//quicksort정의부
{
	if (first >= last)		//왜??
		return;

	int split(partition(a, first, last));	//정복함수  split

	quicksort(a, first, split - 1);		//나눠진 partition에 대해 quicksort 실행
	quicksort(a, split + 1, last);
}


int partition(CCustomer a[], int first, int last)
{
	int lastSmall(first), i;	//lastsmall = first 가 맞다 간혹 first + 1 로 두는 경우가 있음

	for (i = first + 1; i <= last; i++)
	{
		if (a[i] <= a[first])
		{
			++lastSmall;
			swapElements(a, lastSmall, i);
		}
	}
	swapElements(a, first, lastSmall);

	return lastSmall;
}

void swapElements(CCustomer a[], int v, int x)
{
	CCustomer temp;
	temp = a[v];  a[v] = a[x]; a[x] = temp;
}

