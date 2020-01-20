#include "UsefulHeap.h"


void HeapInit(Heap* ph, PriorityComp pc)
{
	ph->numOfData = 0;
	ph->Comp = pc;
}

int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
	return 0;
}

int GetParentIDX(int idx) {
	return idx / 2;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}

int GetRChildIDX(int idx) {
	return GetLChildIDX(idx) + 1;
}

int GetHipriChildIDX(Heap* ph, int idx) {
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	else {
		if (ph->Comp(ph->heapArr[GetLChildIDX(idx)],
			ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap* ph, HData data) {
	int idx = ph->numOfData + 1;

	while (idx != 1)
	{
		if (ph->Comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) {
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

HData HDelete(Heap* ph) {
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHipriChildIDX(ph, parentIdx)) {
		if (ph->Comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}