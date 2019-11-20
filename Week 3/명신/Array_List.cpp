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
//�ʱ�ȭ
void Array_List::ListInit(List* plist)
{
	(plist->numofData) = 0;
	(plist->curPosition) = -1;
}
//����������
void Array_List::LInsert(List* plist, LData data)
{
	if (plist->numofData > LIST_LEN)
	{
		cout << "������ �Ұ����մϴ�.\n";
		return;
	}
	plist->arr[plist->numofData] = data;
	(plist->numofData)++;
}
//ù������ ����
int Array_List::LFirst(List* plist, LData* pdata)
{
	if (plist->numofData == 0) return false;
	(plist->curPosition) = 0;
	*pdata = plist->arr[0];

	return true;
}
//�� ��° ���� ������ ����
int Array_List::LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numofData) - 1) return false;
	
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return true;
}
//������ ������ ����
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
//����� �������� �� ��ȯ
int Array_List::LCount(List* plist)
{
	return plist->numofData;
}
