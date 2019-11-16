#include<iostream>
using namespace std;

int Fibo(int n)
{
	if (n > 2)
		n *= Fibo(n - 1);
	return n;
}
int main()
{
	int N, result = 1;
	cin >> N;
	if (N != 0)
		result = Fibo(N);
	cout << result;
	return 0;
}