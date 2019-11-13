#include <iostream>
using namespace std;
int ans[1000];
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
void push(Stack* s, char ch) {
	s->top++;
	s->stack[s->top] = ch;
}
void pop(Stack* s) {
	s->top--;
}

int main() {
	int n;
	char ch;
	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++) {
		Stack s;
		int len;
		int res=0;
		init(&s);
		cin.get(ch);
		while (ch != '\n') {
			if (ch >= 'a' && ch <= 'z') {
				ch += 'A' - 'a';
			}
			push(&s, ch);
			cin.get(ch);
		}
		len = s.top + 1;
		for (int j = 0; j < len / 2; j++) {
			if (s.stack[s.top] == s.stack[j]) {
				pop(&s);
				res++;
			}
		}
		if (res == len / 2) { ans[i] = 1; }
		delete s.stack;
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