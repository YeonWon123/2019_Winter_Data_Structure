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

	void ListInit(List* plist);	//�ʱ�ȭ
	void LInsert(List* plist, LData data);	//������ ����
	int LFirst(List* plist, LData* pdata);	//ù��° ������ ����
	int LNext(List* plist, LData* pdata);	//�� ��° ���� ������ ����
	LData LRemove(List* plist);	//������ ������ ����
	int LCount(List* plist);	//����� Data���� ��ȯ

	//point��� �Լ�
	void SetPointPos(Point* ppos, int xpos, int ypos);
	void ShowPointPos(Point* ppos);
	int PointComp(Point* pos1, Point* pos2);

private:
	//int�� �����͸� ��� list
	typedef struct _ArrayList
	{
		LData arr[LIST_LEN];
		int numofData;	//Data��
		int curPosition; //plist�� ����Ű�� List�� Data
	}ArrayList;

	//����ü ������ �ּҰ� ����
	typedef struct _point
	{
		int xpos;
		int ypos;

	}Point;
};
