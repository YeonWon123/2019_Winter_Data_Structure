#include "DLinkedList_Cplus.h"
#include<iostream>

DLinkedList::DLinkedList()	//NULL과 0의 차이, NULL은 주소가 0x00000000임을 가리킴 0은 그냥 정수 0
{
	head->next = NULL;	//더미노드를 가리키는 멤버
	cur = NULL;	//참조 및 삭제를 돕는 멤버
	before = NULL;	//삭제를 돕는 멤버
	numofData = NULL;	//저장된 데이터의 수를 기록하기 위한 멤버
	comp = NULL;	//setsortrule함수를 위한 멤버
}

void DLinkedList::LInsert(LData data)
{
	if (comp == NULL)
		FInsert(data);
	else
		SInsert(data);
}

int DLinkedList::LFirst(LData* pdata)	//cur=0으로 초기화하고 첫번째노드의 데이터반환
{
	if (head->next == NULL)		//dummy node이외에 노드가 없을 때
		return false;
	before = head;
	cur = head->next;	//cur이 첫번째 Node를 가리키게 함

	*pdata = cur->data;
	return TRUE;
}

int DLinkedList::LNext(LData* pdata)
{
	if (cur->next == NULL)	//마지막노드를 가리킬때
		return false;
	before = cur;	//before에 이전노드의 주소 저장
	cur = cur->next;

	*pdata = cur->data;
	return true;
}

LData DLinkedList::LRemove()
{
	Node* rpos = cur;
	LData rdata = rpos->data;

	before->next = cur->next;	//두 노드를 Link 해주는 역할
	cur = before;

	delete rpos;

	numofData--;
	return rdata;
}


int DLinkedList::LCount()
{
	return numofData;
}

void DLinkedList::SetSortRule(int(*compinput)(LData d1, LData d2))
{
	comp = compinput;
}

void DLinkedList::FInsert(LData data)	//dummy 부분에 insert
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head->next;
	head->next = newNode;
	numofData++;
}


void DLinkedList::SInsert(LData data)	//정렬삽입
{
	Node* newNode = new Node;
	Node* pred = head;
	newNode->data = data;

	while (pred->next != NULL && comp(data, pred->next->data) != NULL)	//노드가 하나이상존재, 입력data보다 큰 노드가 나올때지
	{																	//Q. comp는 반환값이 아닌 주소값이니까
		pred = pred->next;												// comp가 아닌 WhoIsPrecede를 써야 하는것이 아닌가?
	}
	newNode->next = pred->next;
	pred->next = newNode;

	numofData++;
}

int DLinkedList::WhoIsPrecede(LData d1, LData d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}

