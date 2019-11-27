#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

int main()
{
	int num;
	cin >> num;
	Queue q;
	init(&q);
	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int temp;
			cin >> temp;
			push(&q, temp);
		}
		else if (str == "pop") {
			cout<<pop(&q)<<'\n';
		}
		else if (str == "size") {
			cout<<size(&q)<<'\n';
		}
		else if (str == "empty") {
			cout<<empty(&q)<<'\n';
		}
		else if (str == "front") {
			cout<< front(&q)<<'\n';
		}
		else if (str == "back") {
			cout<<back(&q)<<'\n';
		}
	}
}