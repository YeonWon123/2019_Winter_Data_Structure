#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stdio.h>
using namespace std;

typedef int LData;

class DLinkedList
{
private:
	typedef struct _node
	{
		LData data;
		struct _node* next;
	}Node;

	Node* head;	//더미노드를 가리키는 멤버
	Node* tail;
	Node* cur;	//참조 및 삭제를 돕는 멤버
	Node* before;	//삭제를 돕는 멤버
	int numofData;	//저장된 데이터의 수를 기록하기 위한 멤버
	//int (*comp)(LData d1, LData d2); //반환형이 int인 LData형 인자를 두개 전달받는, 함수의 주소값 전달

public:
	DLinkedList();
	void LInsert(LData data);	//삽입함수
	int LFirst(LData pdata);	//pdata가 첫번째를 가리키게함
	int LNext(LData pdata);	//pdata가 next node를 가리키게 함
	LData LRemove();	//현재 plist가 가리키는 node 삭제
	int LCount();	//현재 존재하는 node 수 반환
	//void SetSortRule(int (*comp)(LData d1, LData d2));	//먼지모름

	void FInsert(LData data);
	void SInsert(LData data);
	int GetnumofData();
	int WhoIsPrecede(LData d1, LData d2);
};


DLinkedList::DLinkedList()	//NULL과 0의 차이, NULL은 주소가 0x00000000임을 가리킴 0은 그냥 정수 0
{
	head = NULL;	//더미노드를 가리키는 멤버
	tail = NULL;
	cur = NULL;	//참조 및 삭제를 돕는 멤버
	before = NULL;	//삭제를 돕는 멤버
	numofData = NULL;	//저장된 데이터의 수를 기록하기 위한 멤버
	//comp = NULL;	//setsortrule함수를 위한 멤버
}

//void DLinkedList::LInsert(LData data)
//{
//	if (comp == NULL)
//		FInsert(data);
	//else
	//	SInsert(data);
//}

int DLinkedList::LFirst(LData pdata)	//cur=0으로 초기화하고 첫번째노드의 데이터반환
{
	if (head->next == NULL)		//dummy node이외에 노드가 없을 때
		return false;
	before = head;
	cur = head;	//cur이 첫번째 Node를 가리키게 함

	pdata = cur->data;
	return true;
}

int DLinkedList::LNext(LData pdata)
{
	if (cur->next == NULL)	//마지막노드를 가리킬때
		return false;
	before = cur;	//before에 이전노드의 주소 저장
	cur = cur->next;

	pdata = cur->data;
	return true;
}

LData DLinkedList::LRemove()
{
	Node* rpos = cur;
	LData rdata = rpos->data;

	before->next = cur->next;	//두 노드를 Link 해주는 역할
	cur = before->next;

	delete rpos;

	numofData--;
	return rdata;
}


int DLinkedList::LCount()
{
	return numofData;
}
//
//void DLinkedList::SetSortRule(int(*compinput)(LData d1, LData d2))
//{
//	comp = compinput;
//}

void DLinkedList::FInsert(LData data)	//dummy 부분에 insert
{

	if (numofData == 0)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = newNode;
		head = newNode;
		tail = newNode;
		numofData++;
	}
	else
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = head;
		tail->next = newNode;
		head = newNode;
		numofData++;
	}
}


//void DLinkedList::SInsert(LData data)	//정렬삽입
//{
//	Node* newNode = new Node;
//	Node* pred = head;
//	newNode->data = data;
//
//	while (pred->next != NULL && comp(data, pred->next->data) != NULL)	//노드가 하나이상존재, 입력data보다 큰 노드가 나올때지
//	{																	//Q. comp는 반환값이 아닌 주소값이니까
//		pred = pred->next;												// comp가 아닌 WhoIsPrecede를 써야 하는것이 아닌가?
//	}
//	newNode->next = pred->next;
//	pred->next = newNode;
//
//	numofData++;
//}

//int DLinkedList::WhoIsPrecede(LData d1, LData d2)
//{
//	if (d1 < d2)
//		return 0;
//	else
//		return 1;
//}

int DLinkedList::GetnumofData()
{
	return numofData;
}

int main()
{
	DLinkedList list;
	int num, count;
	LData* pdata = 0;
	LData data = 0;
	cin >> num;

	//숫자저장
	for (int i = num; i > 0; i--)
	{
		list.FInsert(i);
	}
	cin >> count;

	list.LFirst(data);

	cout << "<";
	while (list.GetnumofData())
	{
		for (int i = 1; i < count; i++)
		{
			list.LNext(data);
		}
		data = list.LRemove();
		cout << data;
		if (list.GetnumofData()) cout << ", ";
	}
	cout << ">";
	return 0;
}