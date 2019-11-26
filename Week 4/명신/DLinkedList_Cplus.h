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

	Node* head = new Node;	//���̳�带 ����Ű�� ���
	Node* cur;	//���� �� ������ ���� ���
	Node* before;	//������ ���� ���
	int numofData;	//����� �������� ���� ����ϱ� ���� ���
	int (*comp)(LData d1, LData d2); //��ȯ���� int�� LData�� ���ڸ� �ΰ� ���޹޴�, �Լ��� �ּҰ� ����

public:
	DLinkedList();
	void LInsert(LData data);	//�����Լ�
	int LFirst(LData* pdata);	//pdata�� ù��°�� ����Ű����
	int LNext(LData* pdata);	//pdata�� next node�� ����Ű�� ��
	LData LRemove();	//���� plist�� ����Ű�� node ����
	int LCount();	//���� �����ϴ� node �� ��ȯ
	void SetSortRule(int (*comp)(LData d1, LData d2));	//������

	void FInsert(LData data);
	void SInsert(LData data);

	int WhoIsPrecede(LData d1, LData d2);
};