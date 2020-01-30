#include "pch.h"		//모두 배열의 크기를 100으로 지정
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>


using namespace std;
using namespace std::chrono;

void swapElements(int a[], int v, int x);
int partition(int a[], int first, int last);
void quicksort(int a[], int first, int last);

int main()
{
	srand((unsigned int)time(NULL));
	int A[100], B[100];
	int i;
	
	for (i = 0; i < 100; i++)	//average case
	{
		A[i] = rand() % 100;
	}
	for (i = 0; i < 100; i++)	//sorted case
	{
		B[i] = i;
	}
	int C[] = { 4, 1, 3, 2, 6, 5, 7 };	//크기가 큰 best case는 못찾았습니다.. ㅠㅠ
	
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	quicksort(A, 0, 99);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	high_resolution_clock::time_point t3 = high_resolution_clock::now();
	quicksort(B, 0, 99);
	high_resolution_clock::time_point t4 = high_resolution_clock::now();

	high_resolution_clock::time_point t5 = high_resolution_clock::now();
	quicksort(C, 0, 6);
	high_resolution_clock::time_point t6 = high_resolution_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	cout << endl << " average case took " << time_span.count() << " seconds."<< endl;
	duration<double> time_span1 = duration_cast<duration<double>>(t4 - t3);
	cout << endl << " sorted case took " << time_span1.count() << " seconds." << endl;
	duration<double> time_span2 = duration_cast<duration<double>>(t6 - t5);
	cout << endl << " best case took " << time_span2.count() << " seconds." << endl;
	
	return 0;
}

void quicksort(int a[], int first, int last)
{
	if (first >= last)		//왜??
		return;

	int split(partition(a, first, last));	//정복함수  split

	quicksort(a, first, split - 1);		//나눠진 partition에 대해 quicksort 실행
	quicksort(a, split + 1, last);
}


int partition(int a[], int first, int last)
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
void swapElements(int a[], int v, int x)
{
int temp; temp = a[v];  a[v] = a[x]; a[x] = temp;
 }
