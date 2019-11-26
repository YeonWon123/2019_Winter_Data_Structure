#pragma once
#pragma once

#define TRUE 1;
#define FALSE 0;

typedef int LData;
typedef LinkedList List;

class DLinkedList
{
private:
	typedef struct _node
	{
		LData data;
		struct _node* next;
	}Node;

	Node* head = new Node;	//더미노드를 가리키는 멤버
	Node* cur;	//참조 및 삭제를 돕는 멤버
	Node* before;	//삭제를 돕는 멤버
	int numofData;	//저장된 데이터의 수를 기록하기 위한 멤버
	int (*comp)(LData d1, LData d2); //반환형이 int인 LData형 인자를 두개 전달받는, 함수의 주소값 전달

public:
	DLinkedList();
	void LInsert(LData data);	//삽입함수
	int LFirst(LData* pdata);	//pdata가 첫번째를 가리키게함
	int LNext(LData* pdata);	//pdata가 next node를 가리키게 함
	LData LRemove();	//현재 plist가 가리키는 node 삭제
	int LCount();	//현재 존재하는 node 수 반환
	void SetSortRule(int (*comp)(LData d1, LData d2));	//먼지모름

	void FInsert(LData data);
	void SInsert(LData data);

	int WhoIsPrecede(LData d1, LData d2);
};