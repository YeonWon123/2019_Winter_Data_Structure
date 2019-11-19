#include<iostream>
#include"ArrayList.h"
using namespace std;
int main(void)
{
	// ArrayList �� ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	// 5���� ������ ����
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	// ����� �������� ��� 
	cout << "���� ����� ������ �� :" << LCount(&list) << "\n";


	if (LFirst(&list, &data)) // ù��° ������ ��ȸ
	{
		cout << data << "\n";

		while (LNext(&list, &data)) // �ι�° ������ ��ȸ
			cout << data << "\n";
	}
	cout << "\n";

	// ���� 22�� Ž���Ͽ� ��� ���� 
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while(LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// ���� �� ���� ������ ��ü��� 
	cout << "���� ����� ������ �� :" << LCount(&list) << "\n";
	if (LFirst(&list, &data))
	{
		cout << data << "\n";

		while (LNext(&list, &data))
			cout << data << "\n";
	}
	cout << "\n";

	return 0;
}