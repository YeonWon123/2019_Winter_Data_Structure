#include<iostream>
using namespace std;

int factorial(int num);

int main()
{
	
	int num;
	cin >> num;
	cout << factorial(num) << endl;
}

int factorial(int num)
{
	if (num == 0) return 1;
	else if (num == 1) return 1;
	else
	{
		return num*factorial(num-1);
	}
}
