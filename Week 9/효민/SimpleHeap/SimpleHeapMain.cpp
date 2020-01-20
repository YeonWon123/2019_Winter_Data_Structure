#include <iostream>
#include "SimpleHeap.h"
using namespace std;

int main() {
	Heap heap;
	HeapInit(&heap);

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	cout << HDelete(&heap) << '\n';

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	cout << HDelete(&heap) << '\n';

	while (!HIsEmpty(&heap)) {
		cout << HDelete(&heap) << '\n';
	}
	return 0;
}