#include "DLinkedList_Cplus.h"
#include<iostream>

DLinkedList::DLinkedList()	//NULL�� 0�� ����, NULL�� �ּҰ� 0x00000000���� ����Ŵ 0�� �׳� ���� 0
{
	head->next = NULL;	//���̳�带 ����Ű�� ���
	cur = NULL;	//���� �� ������ ���� ���
	before = NULL;	//������ ���� ���
	numofData = NULL;	//����� �������� ���� ����ϱ� ���� ���
	comp = NULL;	//setsortrule�Լ��� ���� ���
}

void DLinkedList::LInsert(LData data)
{
	if (comp == NULL)
		FInsert(data);
	else
		SInsert(data);
}

int DLinkedList::LFirst(LData* pdata)	//cur=0���� �ʱ�ȭ�ϰ� ù��°����� �����͹�ȯ
{
	if (head->next == NULL)		//dummy node�̿ܿ� ��尡 ���� ��
		return false;
	before = head;
	cur = head->next;	//cur�� ù��° Node�� ����Ű�� ��

	*pdata = cur->data;
	return TRUE;
}

int DLinkedList::LNext(LData* pdata)
{
	if (cur->next == NULL)	//��������带 ����ų��
		return false;
	before = cur;	//before�� ��������� �ּ� ����
	cur = cur->next;

	*pdata = cur->data;
	return true;
}

LData DLinkedList::LRemove()
{
	Node* rpos = cur;
	LData rdata = rpos->data;

	before->next = cur->next;	//�� ��带 Link ���ִ� ����
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

void DLinkedList::FInsert(LData data)	//dummy �κп� insert
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head->next;
	head->next = newNode;
	numofData++;
}


void DLinkedList::SInsert(LData data)	//���Ļ���
{
	Node* newNode = new Node;
	Node* pred = head;
	newNode->data = data;

	while (pred->next != NULL && comp(data, pred->next->data) != NULL)	//��尡 �ϳ��̻�����, �Է�data���� ū ��尡 ���ö���
	{																	//Q. comp�� ��ȯ���� �ƴ� �ּҰ��̴ϱ�
		pred = pred->next;												// comp�� �ƴ� WhoIsPrecede�� ��� �ϴ°��� �ƴѰ�?
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

