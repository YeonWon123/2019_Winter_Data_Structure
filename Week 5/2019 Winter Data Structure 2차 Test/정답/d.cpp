// D. ���� ��� ���� ����
// ���� 2441�� �� ��� - 4
// ���� ����

#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int j = 0; j < N; j++) {
		// j����ŭ " "�� ���
		for (int i = j; i > 0; i--) {
			cout << " ";
		}

		// N-j��ŭ "*"�� ��´�.		
		for (int i = N - j; i > 0; i--) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}