//
//#include <iostream>
//#include <stdio.h>
//#include "UsefulHeap.h"
//
//using namespace std;
//
//int DataPriorityComp(char ch1, char ch2) { // 우선순위 비교함수
//	return ch2 - ch1;
//}
//
//int main(void) {
//	Heap heap;
//	HeapInit(&heap, DataPriorityComp);
//
//	HInsert(&heap, 'A');
//	HInsert(&heap, 'B');
//	HInsert(&heap, 'C');
//	cout << HDelete(&heap) << endl;
//
//	HInsert(&heap, 'A');
//	HInsert(&heap, 'B');
//	HInsert(&heap, 'C');
//	cout << HDelete(&heap) << endl;
//
//	while (!HIsEmpty(&heap))
//		cout << HDelete(&heap) << endl;
//
//	return 0;
//}
