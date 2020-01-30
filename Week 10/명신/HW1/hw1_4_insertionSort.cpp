#include "pch.h"		//모두 배열의 크기를 100으로 지정
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

void insertionSort(int a[], int n);
void insertNextItem(int a[], int i);

using namespace std;
using namespace std::chrono;

int main()
{
	srand((unsigned int)time(NULL)); 
	int A[100], B[100], C[100];
	int i;
	for (i = 0; i < 100; i++)	//average case
	{
		A[i] = rand() % 100;
	}
	for (i = 0; i < 100; i++)	//sorted case
	{
		B[i] = i;
	}
	for (i = 0; i < 100; i++)	//best case
	{
		C[i] = i;
	}
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	insertionSort(A,100);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	high_resolution_clock::time_point t3 = high_resolution_clock::now();
	insertionSort(B,100);
	high_resolution_clock::time_point t4 = high_resolution_clock::now();

	high_resolution_clock::time_point t5 = high_resolution_clock::now();
	insertionSort(C,100);
	high_resolution_clock::time_point t6 = high_resolution_clock::now();

	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	cout << endl << " average case took " << time_span.count() << " seconds." << endl;
	duration<double> time_span1 = duration_cast<duration<double>>(t4 - t3);
	cout << endl << " sorted case took " << time_span1.count() << " seconds." << endl;
	duration<double> time_span2 = duration_cast<duration<double>>(t6 - t5);
	cout << endl << " best case took " << time_span2.count() << " seconds." << endl;

}

void insertionSort(int a[], int n)
{
	int i;
	for (i = 1; i < n; i++)
		insertNextItem(a, i);
}
void insertNextItem(int a[], int i)
{
	int newItem = a[i], insertPos = i;
	for (; insertPos && newItem < a[insertPos - 1]; insertPos--)
		a[insertPos] = a[insertPos - 1];
	a[insertPos] = newItem;
}
