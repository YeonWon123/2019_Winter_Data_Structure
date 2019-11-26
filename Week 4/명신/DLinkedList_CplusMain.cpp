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
	//리스트생성 및 초기화
	DLinkedList list;
	int data;
	

	//5개의 데이터 저장
	list.LInsert(11); list.LInsert(11);
	list.LInsert(22); list.LInsert(22);
	list.LInsert(33);

	//데이터 전체 출력
	cout << "현재 데이터의 수: " << list.LCount();

	if (list.LFirst(&data))
	{
		cout << data;
		while (list.LNext(&data))
			cout << data;
	}
	cout << "\n\n";

	//숫자2을 검색하여 모두 삭제
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
	//삭제 후 남아있는 데이터 전체 출력
	cout << "현재 데이터의 수: " << list.LCount();

	if (list.LFirst(&data))
	{
		cout << data;
		while (list.LNext(&data))
			cout << data;
	}
	cout << "\n\n";

	return 0;
}
