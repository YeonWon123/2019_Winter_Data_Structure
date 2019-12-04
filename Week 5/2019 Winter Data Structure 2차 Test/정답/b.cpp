// B. 오엑스를 맞춰보자!
// 자료구조 이론 문제

#include <iostream>
#define PROBLEM_NUM_MAX 5            // 최대 문제 수
using namespace std;

// 1번 문제의 정답은 answer[0]에, 2번 문제의 정답은 answer[1]에, ...  기입한다.
int answer[PROBLEM_NUM_MAX] = { 1 , 2 , 1 , 2 , 1 };

int main(void) {
	int problem_number;
	cin >> problem_number;
	for (int i = 1; i <= PROBLEM_NUM_MAX; i++) {
		if (problem_number == i) {
			cout << answer[i - 1] << endl;
			break;
		}
	}
	return 0;
}