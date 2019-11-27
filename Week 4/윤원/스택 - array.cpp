#include <iostream>
using namespace std;

int arr[10001];
int top_index = -1;

void push(int x) {
	top_index++;
	arr[top_index] = x;
}

void pop() {
	if (top_index == -1) {
		cout << -1 << endl;
	}
	else {
		cout << arr[top_index] << endl;
		top_index--;
	}
}

void size() {
	cout << top_index + 1 << endl;
}

void empty() {
	if (top_index == -1) {
		cout << 1 << endl;
	}
	else
		cout << 0 << endl;
}

void top() {
	if (top_index != -1)
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
		else if (str == "top") {
			top();
		}
		else if (str == "size") {
			size();
		}
		else if (str == "pop") {
			pop();
		}
		else if (str == "empty") {
			empty();
		}
	}

	return 0;
}