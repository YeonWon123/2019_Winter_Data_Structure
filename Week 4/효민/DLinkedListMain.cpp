#include <iostream>
#include "DLinkedList.h"
using namespace std;

int main()
{
	//����Ʈ�� ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	//5���� ������ ����
	LInsert(&list, 11);	LInsert(&list, 11);
	LInsert(&list, 22);	LInsert(&list, 22);
	LInsert(&list, 33);

	//����� �������� ��ü ���
	cout << "���� �������� �� : " << LCount(&list) << "\n";

	if (LFirst(&list, &data)) {
		cout << data << ' ';

		while (LNext(&list, &data)) {
			cout << data << ' ';
		}
	}
	cout << "\n\n";

	//���� 22�� �˻��Ͽ� ��� ���
	if (LFirst(&list, &data)) {
		{
			if (data == 22)
				LRemove(&list);

			while (LNext(&list, &data)) {
				if (data == 22)
					LRemove(&list);
			}
		}
	}

	//���� �� �����ִ� ������ ��ü ���
	cout << "���� �������� �� : " << LCount(&list) << '\n';

	if (LFirst(&list, &data)) {
		cout << data << ' ';

		while (LNext(&list, &data)) {
			cout << data << ' ';
		}
	}
	cout << '\n';
	return 0;
}