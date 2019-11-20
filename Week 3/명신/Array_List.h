#pragma once

#define LIST_LEN 100
typedef int LData;
typedef Array_List List;

typedef struct _point
{
	int xpos;
	int ypos;

}Point;

class Array_List
{
public:
	int GetData();
	void SetData(int data);

	void ListInit(List* plist);	//초기화
	void LInsert(List* plist, LData data);	//데이터 저장
	int LFirst(List* plist, LData* pdata);	//첫번째 데이터 참조
	int LNext(List* plist, LData* pdata);	//두 번째 이후 데이터 참조
	LData LRemove(List* plist);	//참조한 데이터 삭제
	int LCount(List* plist);	//저장된 Data숫자 반환

	//point사용 함수
	void SetPointPos(Point* ppos, int xpos, int ypos);
	void ShowPointPos(Point* ppos);
	int PointComp(Point* pos1, Point* pos2);

private:
	//int형 데이터를 담는 list
	typedef struct _ArrayList
	{
		LData arr[LIST_LEN];
		int numofData;	//Data수
		int curPosition; //plist가 가리키는 List의 Data
	}ArrayList;

	//구조체 변수의 주소값 저장
	typedef struct _point
	{
		int xpos;
		int ypos;

	}Point;
};
