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

	Node* head;	//���̳�带 ����Ű�� ���
	Node* tail;
	Node* cur;	//���� �� ������ ���� ���
	Node* before;	//������ ���� ���
	int numofData;	//����� �������� ���� ����ϱ� ���� ���
	//int (*comp)(LData d1, LData d2); //��ȯ���� int�� LData�� ���ڸ� �ΰ� ���޹޴�, �Լ��� �ּҰ� ����

public:
	DLinkedList();
	void LInsert(LData data);	//�����Լ�
	int LFirst(LData pdata);	//pdata�� ù��°�� ����Ű����
	int LNext(LData pdata);	//pdata�� next node�� ����Ű�� ��
	LData LRemove();	//���� plist�� ����Ű�� node ����
	int LCount();	//���� �����ϴ� node �� ��ȯ
	//void SetSortRule(int (*comp)(LData d1, LData d2));	//������

	void FInsert(LData data);
	void SInsert(LData data);
	int GetnumofData();
	int WhoIsPrecede(LData d1, LData d2);
};


DLinkedList::DLinkedList()	//NULL�� 0�� ����, NULL�� �ּҰ� 0x00000000���� ����Ŵ 0�� �׳� ���� 0
{
	head = NULL;	//���̳�带 ����Ű�� ���
	tail = NULL;
	cur = NULL;	//���� �� ������ ���� ���
	before = NULL;	//������ ���� ���
	numofData = NULL;	//����� �������� ���� ����ϱ� ���� ���
	//comp = NULL;	//setsortrule�Լ��� ���� ���
}

//void DLinkedList::LInsert(LData data)
//{
//	if (comp == NULL)
//		FInsert(data);
	//else
	//	SInsert(data);
//}

int DLinkedList::LFirst(LData pdata)	//cur=0���� �ʱ�ȭ�ϰ� ù��°����� �����͹�ȯ
{
	if (head->next == NULL)		//dummy node�̿ܿ� ��尡 ���� ��
		return false;
	before = head;
	cur = head;	//cur�� ù��° Node�� ����Ű�� ��

	pdata = cur->data;
	return true;
}

int DLinkedList::LNext(LData pdata)
{
	if (cur->next == NULL)	//��������带 ����ų��
		return false;
	before = cur;	//before�� ��������� �ּ� ����
	cur = cur->next;

	pdata = cur->data;
	return true;
}

LData DLinkedList::LRemove()
{
	Node* rpos = cur;
	LData rdata = rpos->data;

	before->next = cur->next;	//�� ��带 Link ���ִ� ����
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

void DLinkedList::FInsert(LData data)	//dummy �κп� insert
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


//void DLinkedList::SInsert(LData data)	//���Ļ���
//{
//	Node* newNode = new Node;
//	Node* pred = head;
//	newNode->data = data;
//
//	while (pred->next != NULL && comp(data, pred->next->data) != NULL)	//��尡 �ϳ��̻�����, �Է�data���� ū ��尡 ���ö���
//	{																	//Q. comp�� ��ȯ���� �ƴ� �ּҰ��̴ϱ�
//		pred = pred->next;												// comp�� �ƴ� WhoIsPrecede�� ��� �ϴ°��� �ƴѰ�?
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

	//��������
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