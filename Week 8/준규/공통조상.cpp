#include <iostream>

using namespace std;

#define SIZE 10001

int TreeArr[SIZE];
int ChildRoute1[SIZE];
int ChildRoute2[SIZE];

int T; // 테스트 케이스 수
int N; // 트리를 구성하는 노드의 수 2이상 10000 이하

int main(void) {
	cin >> T;
	for (int i = 0; i < T; i++) { // 테스트 케이스
		int size1 = 0;
		int size2 = 0;
		cin >> N; // 노드의 수

		for (int j = 0; j < N; j++) { 
			int A, B;
			cin >> A >> B; 
			if (j == N - 1) { 
				ChildRoute1[0] = A;
				ChildRoute2[0] = B;
			}
			else
				TreeArr[B] = A;
		}
		for (int j = 1, n = ChildRoute1[0]; n != 0; j++, n = TreeArr[n]) { 
			ChildRoute1[j] = n;
			size1++;
		}
		for (int j = 1, n = ChildRoute2[0]; n != 0; j++, n = TreeArr[n]) {
			ChildRoute2[j] = n;
			size2++;
		}
		for (int j = 0; j < size1+1; j++) { 
			if (ChildRoute1[size1 - j] != ChildRoute2[size2 - j]) {
				cout << ChildRoute1[size1 - j + 1] << "\n";
				break;
			}
		}

		for (int i = 1; ; i++) {
			if (i == ChildRoute1[size1])
				continue;
			if (TreeArr[i] == 0)
				break;
			TreeArr[i] = 0;
		}
		for (int i = 0; ChildRoute1[i] != 0; i++) {
			ChildRoute1[i] = 0;
		}
		for (int i = 0; ChildRoute2[i] != 0; i++) {
			ChildRoute2[i] = 0;
		}

	}
	return 0;
}