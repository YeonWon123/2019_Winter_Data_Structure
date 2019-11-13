#include <iostream>
using namespace std;
int ans[100];
typedef struct _stack {
	char* stack;
	int size;
	int top;
}Stack;

void init(Stack* s) {
	s->top = -1;
	s->size = 100;
	s->stack = new char[s->size];
}

bool pop(Stack* s) {
	if (s->top < 0) {
		return false;
	}
	s->top--;
	return true;
}

void push(Stack* s, char ch) {
	s->top++;
	s->stack[s->top] = ch;
}

int main() {
	int n;
	char ch;
	bool res;
	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++) {
		Stack s;
		init(&s);
		cin.get(ch);
		while (ch != '\n') {
			if (ch == '(') {
				push(&s, ch);
			}
			else if (ch == ')') {
				res=pop(&s);
				if (res == false) {
					s.top = -2;
					break;
				}
			}
			cin.get(ch);
		}
		if (s.top == -1) {
			ans[i] = 1;
		}
		delete[] s.stack;
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}