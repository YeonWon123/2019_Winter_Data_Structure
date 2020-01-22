#include <iostream>

using namespace std;

int TreeArr[50];
int LeafArr[50];
int N;
int Target;
int LeafNum;

int main(void) {

	cin >> N;

	for (int i = 0; i < N; i++) { 
		int parent = 0;
		cin >> parent;
		TreeArr[i] = parent; 
	}

	cin >> Target;


	if (N == 0) { 
		cout << 0;
		return 0;
	}

	if (TreeArr[Target] == -1) {
		cout << 0;
		return 0;
	}

	TreeArr[Target] = -2;

	for (int i = 0; i < N; i++) {
		if (TreeArr[i] > -1)
			LeafArr[TreeArr[i]]++; 
	}

	for (int i = 0; i < N; i++) { 

		int parentNum = LeafArr[i]; 
		if (parentNum != 0) {
			continue;
		}

		int parentTemp = TreeArr[i];
		for (int j = 0; j < N - 1; j++) { 
			if (parentTemp == -1) {
				LeafNum++;
				break;
			}
			else if (parentTemp == -2) {
				break;
			}
			else {
				parentTemp = TreeArr[parentTemp];
			}
		}
	}

	cout << LeafNum;

	return 0;
}