#include <iostream>
#include "CLinkedList.h"
using namespace std;

int main()
{
	int n, k;
	int res;
	List list;
	init(&list);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		insert(&list);
	}
	cout << "<";
	while (list.numOfData != 0) {
		if (list.numOfData != n) {
			cout << ", ";
		}
		res = remove(&list, k);
		cout << res;
	}
	cout << ">";

	return 0;
}