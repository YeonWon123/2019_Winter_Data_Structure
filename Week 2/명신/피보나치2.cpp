#include<iostream>
using namespace std;



//n이 주어졌을 때, n번째 피보나치 수를 구하는 함수.
int pivonachi1(int n);
int pivonachi2(int n);

int main()
{
	int input;
	cin >> input;
	cout << pivonachi2(input) << endl;

}

//위에서 아래로 내려가는 방식
int pivonachi1(int n)
{
	if (n == 1)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	else
	{
		return pivonachi1(n-1) + pivonachi1(n-2);
	}
}
//아래에서 위로 올라가는 방식
int pivonachi2(int n)
{
	int fibonacci[50];
	fibonacci[0] = 0;
	fibonacci[1] = 1;

	int sum;
	// ??
	for (int i = 2; i <= n; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	return fibonacci[n];;
}
