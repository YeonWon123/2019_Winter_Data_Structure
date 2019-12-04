// F. 피보나치 수
// Bottom-Up 기법
// 배열과 반복문을 사용하는 Dynamic Programming 기법

#include <iostream>
using namespace std;

int n, d[50];
int main() {
    d[1] = 1;
	for (int i = 2; i <= 45; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
    cin >> n;
    cout << d[n];
}