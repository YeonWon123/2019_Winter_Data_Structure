// D. 별을 찍는 구현 문제
// 백준 2441번 별 찍기 - 4
// 구현 문제

#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int j = 0; j < N; j++) {
		// j개만큼 " "을 찍고
		for (int i = j; i > 0; i--) {
			cout << " ";
		}

		// N-j만큼 "*"을 찍는다.		
		for (int i = N - j; i > 0; i--) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}