#include <iostream>
#include "DLinkedList.h"
using namespace std;

int whoIsPrecede(int d1, int d2) {
	if (d1 < d2) {
		return 0;
	}
	else{
		return 1;
	}
}

int main()
{
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, whoIsPrecede);

	LInsert(&list, 11);	LInsert(&list, 11);
	LInsert(&list, 22);	LInsert(&list, 22);
	LInsert(&list, 33);

	cout << "현재 데이터의 수 : " << LCount(&list) << '\n';

	if (LFirst(&list, &data)) {
		if (data == 22) {
			LRemove(&list);
		}
		while (LNext(&list, &data)) {
			if (data == 22) {
				LRemove(&list);
			}
		}
	}

	cout << "현재 데이터의 수 : " << LCount(&list) << '\n';

	if (LFirst(&list, &data)) {
		cout << data << ' ';

		while (LNext(&list, &data)) {
			cout << data << ' ';
		}
	}
	cout << "\n\n";
	return 0;
}