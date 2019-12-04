// 덱(Deque)
// 백준 10866
// 앞으로도 뒤로도 삽입과 삭제가 가능한 queue를 Deque라 한다.
// STL을 사용하여 풀 수도 있지만, Deque를 array 또는 vector를 사용하여 구현할 수도 있다.
// 여기서는 Deque라는 class를 정의하였다.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Deque {
public:
	int length;
	vector<int> d;
	Deque() {
		length = 0;
	}

	void push_front(int n) {
		if (length != 0) {
			d.push_back(d[length - 1]);
			for (int i = d.size() - 1; i > 0; i--) {
				d[i] = d[i - 1];
			}
			d[0] = n;
		}
		else
			d.push_back(n);
		length++;
	}

	void push_back(int n) {
		d.push_back(n);
		length++;
	}

	void pop_back() {
		if (length != 0) {
			cout << d[length - 1] << "\n";
			d.pop_back();
			length--;
		}
		else
			cout << "-1\n";
	}

	void pop_front() {
		if (length != 0) {
			cout << d[0] << "\n";
			for (int i = 0; i < d.size() - 1; i++)
				d[i] = d[i + 1];
			d.pop_back();
			length--;
		}
		else
			cout << "-1\n";
	}

	void size() {
		cout << length << "\n";
	}

	void empty() {
		if (length == 0)
			cout << "1\n";
		else
			cout << "0\n";
	}

	void front() {
		if (length != 0)
			cout << d[0] << "\n";
		else
			cout << "-1\n";;
	}

	void back() {
		if (length != 0)
			cout << d[length - 1] << "\n";
		else
			cout << "-1\n";;
	}
};

int main() {
	int tc;
	cin >> tc;

	Deque k;
	for (int i = 0; i < tc; i++) {
		string input;
		cin >> input;
		int tmp;
		if (input == "push_front") {
			cin >> tmp;
			k.push_front(tmp);

		}
		else if (input == "push_back") {
			cin >> tmp;
			k.push_back(tmp);
		}
		else if (input == "pop_front") {
			k.pop_front();
		}
		else if (input == "pop_back") {
			k.pop_back();
		}
		else if (input == "size") {
			k.size();
		}
		else if (input == "empty") {
			k.empty();
		}
		else if (input == "front") {
			k.front();
		}
		else if (input == "back") {
			k.back();
		}
	}
}