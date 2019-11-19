/*피보나치 수열을 재귀함수 없이 구현*/
#include <iostream>
using namespace std;
int fibo[50];
int main() {
	int n;
	cin >> n;
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[n];
	return 0;
}