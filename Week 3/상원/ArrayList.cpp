#include<iostream>
#include"ArrayList.h"
using namespace std;

void ListInit(List* plist)
{
	plist->numofData = 0; // ����Ʈ�� ����� �������� ���� 0 
	plist->curPosition = -1; // ���� �ƹ� ��ġ�� ����Ű�� ����
}

void LInsert(List* plist, LData data)
{
	if (plist->numofData >= LIST_LEN) // ���̻� ������ ������ ���ٸ�
	{
		cout << "������ �Ұ����մϴ�." << "\n";
		return;
	}
	plist->arr[plist->numofData] = data; // ������ ����
	plist->numofData++; // ����� �������� �� ����
}

int LFirst(List* plist, LData* pdata) // ù��° ��ȸ
{
	if (plist->numofData == 0) // ����� �����Ͱ� �ϳ��� ���ٸ�
	{
		return FALSE;
	}
	plist->curPosition = 0; // ���� ��ġ �ʱ�ȭ : ù��° �������� ������ �ǹ�
	*pdata = plist->arr[0]; // pdata�� ����Ű�� ������ ������ ����
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numofData) - 1) // ���̻� ������ �����Ͱ� ���ٸ� 
		return FALSE;
	plist->curPosition++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition; // ������ �������� �ε��� �� ����
	int num = plist->numofData; 
	int i;
	LData rdata = plist->arr[rpos]; // ������ �����͸� �ӽ÷� ����

	// ������ ���� �������� �̵��� �����ϴ� �ݺ���
	for (i = rpos; i < num - 1; i++)
	{
		plist->arr[i] = plist->arr[i + 1];
	}
	plist->numofData--; // �������� �� ����
	plist->curPosition--; // ������ġ�� �ϳ� �ǵ�����.
	return rdata; // ������ �������� ��ȯ
}

int LCount(List* plist)
{
	return plist->numofData;
}







