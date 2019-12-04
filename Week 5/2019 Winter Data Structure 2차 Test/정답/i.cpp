// 카드
// 백준 1835번 문제
// 리스트, 스택, 큐, 배열 중 선택해서 구현해야 하는 문제
// 배열을 극한으로 활용하여 구현할 수 있음. 다만, 리스트로 구현하는 편이 더 용이함.
// ACM-ICPC : NCPC 2006 E번 문제

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int m;
	cin >> m;
	vector<int> deck(m);
	vector<int> current(m);
	for (int i = 0; i < m; i++)
		current[i] = i;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= i; j++) {
			int top = current[0];
			for (int k = 0; k < current.size() - 1; k++)
				current[k] = current[k + 1];
			current[current.size() - 1] = top;
		}
		deck[current[0]] = i + 1;
		for (int k = 0; k < current.size() - 1; k++)
			current[k] = current[k + 1];
		current.pop_back();
	}
	for (int i = 0; i < m; i++) {
		if (i > 0)
			cout << " ";
		cout << deck[i];
	}
	cout << endl;
	return 0;
}