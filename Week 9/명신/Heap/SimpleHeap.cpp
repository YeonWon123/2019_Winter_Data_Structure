#include "SimpleHeap.h"

void HeapInit(Heap* ph)
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

//두개의 자식노드중 높은 우선순위의 자식 노드 인덱스 값 반환
int GetHiPriChildIDX(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)	// 자식노드의 인덱스 > 순위권밖 = 자식노드가 없음을 의미
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	else {
		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
			return GetLChildIDX(idx);
		else
			return GetRChildIDX(idx);
	}
}
	//data와 pr이 필요 즉 원소의 정보가 필요
void HInsert(Heap* ph, HData data, Priority pr)
{
	int idx = ph->numOfData + 1;	//맨아래층 맨오른쪽에 삽입하겠다.
	HeapElem nelem = { pr,data };

	while (idx != 1) //idx가 1이 아니라면이라는 조건은 왜? idx가 줄어드나? -> idx 가 1인 원소와 비교할때까지 라는 뜻
	{
		if (pr < (ph->heapArr[GetParentIDX(idx)].pr))	//부모원소의 우선순위와 비교해서 낮다면
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];	//정착!
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = nelem;
	ph->numOfData += 1;
}

//힙에서 데이터 삭제
HData HDelete(Heap* ph)
{
	HData retData = (ph->heapArr[1]).data;
	HeapElem lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if (lastElem.pr <= ph->heapArr[childIdx].pr)
			break;
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	
	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;

	return retData;
}
