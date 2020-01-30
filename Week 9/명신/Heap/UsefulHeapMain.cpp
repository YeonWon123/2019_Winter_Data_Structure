#include <iostream>
#include "UsefulHeap.h"
using namespace std;

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;
}

int main() {
	Heap heap;
	HeapInit(&heap, DataPriorityComp);

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	cout << HDelete(&heap) << '\n';

	HInsert(&heap, 'A');
	HInsert(&heap, 'B');
	HInsert(&heap, 'C');
	cout << HDelete(&heap) << '\n';

	while (!HIsEmpty(&heap)) {
		cout << HDelete(&heap) << '\n';
	}
	return 0;
}