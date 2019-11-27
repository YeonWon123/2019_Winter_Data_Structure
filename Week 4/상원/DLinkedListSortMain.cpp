#include<iostream>
#include"DLinkedList.h"
using namespace std;
int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0; // d1�� ���ļ����� �ռ���.
	else
		return 1; // d2�� ���� ������ �ռ��ų� ����
}

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede); // ������ ������ ����Ѵ�.
	
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);
	cout << "���� �������� �� :" << LCount(&list) << "\n";
	
	if (LFirst(&list, &data))
	{
		cout << data << " ";
		while (LNext(&list, &data))
		{
			cout << data << " ";
		}
	}
	cout << "\n";

	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}
	cout << "���� �������� �� :" << LCount(&list) << "\n";

	if (LFirst(&list, &data))
	{
		cout << data << " ";
		
		while (LNext(&list, &data))
		{
			cout << data << " ";
		}
	}
	cout << "\n";
	return 0;
}