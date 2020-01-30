#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 10000

typedef int HData;	//Heap에 들어갈 데이터를 char형으로 지정
typedef int PriorityComp(HData d1, HData d2);	// int을 함수로 형식변환..?

typedef struct _heap	//Heap Node 모양새
{
	PriorityComp* comp;
	int numOfData;
	HData heapArr[HEAP_LEN];	//총 몇개의 Node가 들어 차 있는지 확인하기 위해 사용
}Heap;

void HeapInit(Heap* ph, PriorityComp pc);		//Heap 초기화
int HIsEmpty(Heap* ph);		//Heap이 비어있는지 확인

void HInsert(Heap* ph, HData data);		//Node 삽입
HData HDelete(Heap* ph);	//ph가 가리키는 Node 삭제


void HeapInit(Heap* ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0) {	//어떤 노드든 상관없음
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int GetParentIDX(int idx)
{
	return idx / 2;	//부모의 인덱스 = 자식의 인덱스  % 2
}

int GetLChildIDX(int idx)
{
	return idx * 2;	//왼쪽 자식의 인덱스 자신의 인덱스 * 2
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1; //오른쪽 자식의 인덱스 자신의 인덱스 * 2 + 1
}

int GetHiPriChildIDX(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData) {
		return 0;
	}
	else if (GetLChildIDX(idx) == ph->numOfData) {
		return GetLChildIDX(idx);
	}
	else {
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0) {
			return GetRChildIDX(idx);
		}
		else {
			return GetLChildIDX(idx);
		}
	}
}

void HInsert(Heap* ph, HData data)
{
	int idx = ph->numOfData + 1;

	while (idx != 1) {	//어느 자리에 들어갈지 찾는 과정
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) {
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else {
			break;
		}
	}

	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

HData HDelete(Heap* ph)	//젤 작은수가 젤 먼저 삭제된다
{
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0) {
			break;
		}

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}

int DataPriorityComp(int ch1, int ch2)
{
	return ch1 - ch2;
}

int main() {

	Heap heap;
	HeapInit(&heap, DataPriorityComp);

	int num,input;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> input;
		if (input == 0)
		{
			if (HIsEmpty(&heap) == TRUE)
			{
				cout << "0" << '\n';
			}
			else
			{
				cout << HDelete(&heap) << '\n';
			}
		}
		else
		{
			HInsert(&heap, input);
		}
	}

	return 0;
}
