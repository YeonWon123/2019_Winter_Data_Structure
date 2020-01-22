//트리의 순회
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pre_order;	//pre order 저장
vector<int> in_order;		//in order 저장

/* pre  : 1 2 4 3
   in   : 4 2 1 3
   post : 4 2 3 1
   
   1 (2 4) (3)
   (4 2) 1 (3)

   */
void func(int start_pre, int end_pre, int start_in, int end_in) {
	if (start_in > end_in) {
		return;
	}
	else if (start_in == end_in) {
		cout << in_order[start_in] << ' ';
		return;
	}
	for (int i = start_in; i <= end_in; i++) {
		int root = pre_order[start_pre];
		if (root == in_order[i]) {
			int size = i - start_in;
			func(start_pre + 1, start_pre + 1 + size - 1, start_in, start_in + size - 1);
			func(start_pre + 1 + size - 1 + 1, end_pre, start_in + size - 1 + 1 + 1, end_in);
			cout << root << ' ';
		}
	}
}

int main()
{
	int n, m;
	cin >> m;
	for (int j = 0; j < m; j++) {
		//node의 개수 입력
		cin >> n;

		//pre order 저장
		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			pre_order.push_back(input);
		}

		//in order 저장
		for (int i = 0; i < n; i++) {
			int input;
			cin >> input;
			in_order.push_back(input);
		}

		//재귀
		func(0, n - 1, 0, n - 1);
		cout << '\n';

		//초기화
		pre_order.clear();
		in_order.clear();
	}
}