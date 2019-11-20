#include "Array_List.h"
#include<iostream>
using namespace std;

//accesor
int Array_List::GetData()
{
	return 0;
}
//mutator
void Array_List::SetData(int data)
{
}
//초기화
void Array_List::ListInit(List* plist)
{
	(plist->numofData) = 0;
	(plist->curPosition) = -1;
}
//데이터저장
void Array_List::LInsert(List* plist, LData data)
{
	if (plist->numofData > LIST_LEN)
	{
		cout << "저장이 불가능합니다.\n";
		return;
	}
	plist->arr[plist->numofData] = data;
	(plist->numofData)++;
}
//첫데이터 참조
int Array_List::LFirst(List* plist, LData* pdata)
{
	if (plist->numofData == 0) return false;
	(plist->curPosition) = 0;
	*pdata = plist->arr[0];

	return true;
}
//두 번째 이후 데이터 참조
int Array_List::LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numofData) - 1) return false;
	
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return true;
}
//참조한 데이터 삭제
LData Array_List::LRemove(List* plist)
{
	int rpos = plist->curposition;
	int num = plist->numofData;
	int i;
	LData rdata = arr[rpos];

	for (int i = rpos; i < num - 1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}

	(plist->numofData)--;
	(plist->curPosition)--;

	return LData();
}
//저장된 데이터의 수 반환
int Array_List::LCount(List* plist)
{
	return plist->numofData;
}
