#include<iostream>
#include"ArrayList.h"
using namespace std;
int main(void)
{
	// ArrayList 의 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	// 5개의 데이터 저장
	LInsert(&list, 11); LInsert(&list, 11);
	LInsert(&list, 22); LInsert(&list, 22);
	LInsert(&list, 33);

	// 저장된 데이터의 출력 
	cout << "현재 저장된 데이터 수 :" << LCount(&list) << "\n";


	if (LFirst(&list, &data)) // 첫번째 데이터 조회
	{
		cout << data << "\n";

		while (LNext(&list, &data)) // 두번째 데이터 조회
			cout << data << "\n";
	}
	cout << "\n";

	// 숫자 22를 탐색하여 모두 삭제 
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

	// 삭제 후 남은 데이터 전체출력 
	cout << "현재 저장된 데이터 수 :" << LCount(&list) << "\n";
	if (LFirst(&list, &data))
	{
		cout << data << "\n";

		while (LNext(&list, &data))
			cout << data << "\n";
	}
	cout << "\n";

	return 0;
}