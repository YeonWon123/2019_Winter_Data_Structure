// E. �ּҿ� �ִ밪 ���ϱ�
// ���� ����
// �Է��� �����鼭 Ǯ ���� �ְ�, ���� �Է��� ���� �ڿ� Ǯ ���� �ִ�.

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