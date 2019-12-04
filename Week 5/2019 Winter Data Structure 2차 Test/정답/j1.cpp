// ��(Deque)
// ���� 10866
// �����ε� �ڷε� ���԰� ������ ������ queue�� Deque�� �Ѵ�.
// STL�� ����Ͽ� Ǯ ���� ������, Deque�� array �Ǵ� vector�� ����Ͽ� ������ ���� �ִ�.
// ���⼭�� Deque��� class�� �����Ͽ���.

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