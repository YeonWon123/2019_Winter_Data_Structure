#include <iostream>
#include <algorithm>
using namespace std;
int note1[10000];
//int ans[10000];

int search(int ary[],int target,int first, int last) {
	int mid = (first + last) / 2;
	if (first > last) { return -1; }

	if (target == ary[mid]) {
		return mid;
	}
	else if (target > ary[mid]) {
		return search(ary, target, mid + 1, last);
	}
	else if (target < ary[mid]) {
		return search(ary, target, first, mid - 1);
	}

}

int main() {
	int t, n, m;
	//case 수 입력
	cin >> t;
	//수첩1 에 입력할 개수 입력
	cin >> n;

	//case수만큼 실행
	for (int i = 0; i < t; i++) {
		//수첩1에 기록
		for (int j = 0; j < n; j++) {
			cin >> note1[j];
		}
		//수첩1 정렬
		sort(note1, note1 + n);
		cin >> m;
		//수첩2 기록
		for (int k = 0; k < m; k++) {
			int target;
			int res;
			cin >> target;
			res = search(note1, target, 0, n - 1);
			if (res == -1) { cout << "0" << endl; }
			else { cout << "1" << endl; }
		}
		/*for (int z = 0; z < m; z++) {
			if (ans[z] == -1) { cout << "0" << endl; }
			else { cout << "1" << endl; }
		}*/
	}
	
}