#pragma once

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

//data���� char, �켱���� ������ ���� Ÿ������
typedef char HData;
typedef int Priority;

//Heap ������ ���α���
typedef struct _heapElem
{
	Priority pr;
	HData data;
}HeapElem;

//Heap���ҷ� �̷���� Heap����
typedef struct _heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
}Heap;

//�� �ʱ�ȭ, ����ִ��� Ȯ��
void HeapInit(Heap* ph);
int HIsEmpty(Heap* ph);

//�� ������ ���԰� ����
void HInsert(Heap* ph, HData data, Priority pr);
HData HDelete(Heap* ph);