#include<iostream>
#include"ArrayList.h"
#include"point.h"
using namespace std;
int main()
{
	List list;
	Point compPos;
	Point* ppos;

	ListInit(&list);

	// 4개의 데이터 저장
	ppos = new Point[sizeof(Point)];
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = new Point[sizeof(Point)];
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = new Point[sizeof(Point)];
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = new Point[sizeof(Point)];
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	// 저장된 데이터 출력
	cout << "현재 데이터 수 :" << LCount(&list) << "\n";

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		
		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
		cout << "\n";
	}

	// xpos 가 2 인 모든 데이터 삭제
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			delete[] ppos;
		}

		while (LNext(&list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				delete[] ppos;
			}
		}
	}
	// 삭제 후 남은 데이터 전체출력
	cout << "현재 데이터 수 :" << LCount(&list) << "\n";

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
		cout << "\n";
	}
	


	return 0;
}