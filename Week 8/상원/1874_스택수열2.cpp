#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N, v, last = 0;
stack<int> s;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v;

		if (v > last) {
			for (int j = last + 1; j <= v; j++) {
				s.push(j);
				str += "+\n";
			}
			last = v;
		}

		if (s.top() == v) {
			s.pop();
			str += "-\n";
		}
	}

	if (!s.empty()) {
		cout << "NO";
	}
	else {
		cout << str;
	}


	return 0;
}