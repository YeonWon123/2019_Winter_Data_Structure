#include<iostream>
using namespace std;
int main(void)
{

	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	int Fibo[50] = { 0, };
	Fibo[0] = 0;
	Fibo[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
	}
	cout << Fibo[N];
	return 0;
}