#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int fibo_arr[50];
int fibo_size = 2;

int fibo(int n)
{
	if (n < fibo_size) // n번째 fibo가 이미 구해져있는가?
		return fibo_arr[n]; // n번째 fibo는 n-1 index에 저장되어있음.
	fibo_arr[n] = fibo(n - 1) + fibo(n - 2);
	fibo_size++;
	return fibo_arr[n];
}

int main(void)
{
	int n;
	fibo_arr[0] = 0;
	fibo_arr[1] = 1;
	cin >> n;
	cout << fibo(n);
	return 0;
}