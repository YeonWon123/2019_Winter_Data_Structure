// B. �������� ���纸��!
// �ڷᱸ�� �̷� ����

#include <iostream>
#define PROBLEM_NUM_MAX 5            // �ִ� ���� ��
using namespace std;

// 1�� ������ ������ answer[0]��, 2�� ������ ������ answer[1]��, ...  �����Ѵ�.
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