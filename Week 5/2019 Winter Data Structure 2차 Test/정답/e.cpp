// E. 최소와 최대값 구하기
// 정렬 문제
// 입력을 받으면서 풀 수도 있고, 먼저 입력을 받은 뒤에 풀 수도 있다.

#include <iostream>
#include <iostream>
using namespace std;

int maxs = -1000001;
int mins = 1000001;

int main(void) {
	int N;
	cin >> N;
	int temp;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (maxs < temp) maxs = temp;
		if (mins > temp) mins = temp;
	}

	cout << mins << " " << maxs << endl;
	return 0;
}