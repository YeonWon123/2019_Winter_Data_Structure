#include<iostream>
#include"DLinkedList.h"
using namespace std;
int main(void)
{
	// 리스트의 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	// 5개 데이터 저장
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	// 저장된 데이터의 전체 출력
	cout << LCount(&list) << "\n";

	if (LFirst(&list, &data))
	{
		cout << data << "\n";

		while (LNext(&list, &data))
			cout << data << "\n";
	}
	cout << "\n";

	// 숫자 22을 검색하여 모두 삭제
	if (LFirst(&list, &data))+
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// 삭제 후 남아있는 데이터 전체 출력
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
		{
			LRemove(&list);
		}
		while (LNext(&list, &data))
		{
			if (data == 22)
			{
				LRemove(&list);
			}
		}
	}

	cout << "현재 남아있는 데이터의 수 :" << LCount(&list);

	if (LFirst(&list, &data))
	{
		cout << data << " ";
		while (LNext(&list, &data))
		{
			cout << data << " ";
		}
	}
	cout << "\n";
}