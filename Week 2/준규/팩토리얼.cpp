#include <iostream>

using namespace std;

int foo(int n)
{
	if (n == 1)
		return n;
	return n * foo(n - 1);
}

int main(void)
{
	int n;
	cin >> n;
	if (n == 0)
		cout << 1;
	else
		cout << foo(n);
	return 0;
}