#include <iostream>
using namespace std;

int arr[10001];
int top_index = -1;
int bottom_index = 0;

void push(int x) {
	top_index++;
	arr[top_index] = x;
}

void pop() {
	if (top_index - bottom_index < 0) {
		cout << -1 << endl;
	}
	else {
		cout << arr[bottom_index] << endl;
		bottom_index++;
	}
}

void size() {
	cout << top_index - bottom_index+1 << endl;
}

void empty() {
	if (top_index-bottom_index < 0) {
		cout << 1 << endl;
	}
	else
		cout << 0 << endl;
}

void front() {
//	cout << top_index << endl;
//	cout << bottom_index << endl;
	if (top_index - bottom_index >= 0)
		cout << arr[bottom_index] << endl;
	else
		cout << -1 << endl;
}

void back() {
	if (top_index - bottom_index >= 0)
		cout << arr[top_index] << endl;
	else
		cout << -1 << endl;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			int x;
			cin >> x;
			push(x);
		}
		else if (str == "pop") {
			pop();
		}
		else if (str == "size") {
			size();
		}
		else if (str == "empty") {
			empty();
		}
		else if (str == "front") {
			front();
		}
		else if (str == "back") {
			back();
		}
	}

	return 0;
}