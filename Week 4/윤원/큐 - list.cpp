#include <iostream>
#include <string>
using namespace std;

struct Node {
	class Queue;
	int data;
	struct Node* next;
};

class Queue {
	Node* front = 0;
	Node* rear = 0;
	int count = 0;
public:
	void push(int num) {
		Node* tmp = new Node();
		tmp->data = num;
		tmp->next = NULL;
		if (IsEmpty())
			front = tmp;
		else
			rear->next = tmp;
		rear = tmp;
		count++;
	}
	bool IsEmpty() {
		if (count == 0)
			return true;
		return false;
	}
	void pop() {
		if (IsEmpty()) {
			cout << -1 << "\n";
			return;
		}
		cout << front->data << "\n";
		Node* tmp = front->next;
		delete front;
		front = tmp;
		count--;
	}
	void printsize() {
		cout << count << endl;
	}
	void printfront() {
		if (IsEmpty())
			cout << -1 << "\n";
		else
			cout << front->data << "\n";
	}
	void printback() {
		if (IsEmpty())
			cout << -1 << "\n";
		else
			cout << rear->data << "\n";
	}
}q;

int main() {
	int n;
	string str;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			int temp; cin >> temp;
			q.push(temp);
		}
		else if (str == "pop") {
			q.pop();
		}
		else if (str == "size") {
			q.printsize();
		}
		else if (str == "empty") {
			cout << q.IsEmpty() << "\n";
		}
		else if (str == "front") {
			q.printfront();
		}
		else {
			q.printback();
		}
	}

	return 0;
}