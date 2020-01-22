#pragma once

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

//data형은 char, 우선순위 저장을 위한 타입지정
typedef char HData;
typedef int Priority;

//Heap 원소의 내부구조
typedef struct _heapElem
{
	Priority pr;
	HData data;
}HeapElem;

//Heap원소로 이루어진 Heap구조
typedef struct _heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
}Heap;

//힙 초기화, 비어있는지 확인
void HeapInit(Heap* ph);
int HIsEmpty(Heap* ph);

//힙 원소의 삭입과 삭제
void HInsert(Heap* ph, HData data, Priority pr);
HData HDelete(Heap* ph);