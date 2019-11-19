#include <iostream>
using namespace std;
int fact(int n) {
	if (n == 1) {
		return 1;
	}
	return n * fact(n - 1);
}
int main() {
	int n;
	cin >> n;
	if (n == 0) {
		return 0;
	}
	else {
		cout << fact(n);
	}
}