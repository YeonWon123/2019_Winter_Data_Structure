#include<iostream>
#include"DLinkedList_Cplus.h"
using namespace std;


int DLinkedList::WhoIsPrecede(LData d1, LData d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}

int main()
{
	//����Ʈ���� �� �ʱ�ȭ
	DLinkedList list;
	int data;
	

	//5���� ������ ����
	list.LInsert(11); list.LInsert(11);
	list.LInsert(22); list.LInsert(22);
	list.LInsert(33);

	//������ ��ü ���
	cout << "���� �������� ��: " << list.LCount();

	if (list.LFirst(&data))
	{
		cout << data;
		while (list.LNext(&data))
			cout << data;
	}
	cout << "\n\n";

	//����2�� �˻��Ͽ� ��� ����
	if (list.LFirst( &data))
	{
		if (data == 22)
			list.LRemove();
		while (list.LNext(&data))
		{
			if (data == 22)
				list.LRemove();
		}
	}
	//���� �� �����ִ� ������ ��ü ���
	cout << "���� �������� ��: " << list.LCount();

	if (list.LFirst(&data))
	{
		cout << data;
		while (list.LNext(&data))
			cout << data;
	}
	cout << "\n\n";

	return 0;
}
