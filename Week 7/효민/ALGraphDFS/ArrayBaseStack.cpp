#include <iostream>
#include "ArrayBaseStack.h"
using namespace std;

void StackInit(Stack* pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->topIndex == -1) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void SPush(Stack* pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack* pstack)
{
	int rIdx;
	if (SIsEmpty(pstack)) {
		cout << "Stack Memory Error" << endl;
		exit(-1);
	}
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack)) {
		cout << "Stack Memory Error" << endl;
		exit(-1);
	}
	
	return pstack->stackArr[pstack->topIndex];
}