
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next;
	struct _node* before;
} Node;

typedef struct _linkedList
{
	Node* head;
	Node* cur;
	int numOfData;
} LinkedList;


typedef LinkedList List;


void ListInit(List* plist) // �ֺ� ����Ʈ �����
{
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, LData data)
{
	if (plist->head == NULL)
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = newNode;
		newNode->before = newNode;

		plist->head = newNode;

		(plist->numOfData)++;
	}
	else
	{
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;

		plist->head->before->next = newNode; // ��� ���� -> �� ���
		newNode->before = plist->head->before; // �� ��� -> ��� ����

		plist->head->before = newNode;
		newNode->next = plist->head;

		(plist->numOfData)++;
	}
}

bool LGetFirst(List* plist, LData* pdata)
{
	if (plist->head == NULL)
		return false;

	plist->cur = plist->head;

	*pdata = plist->cur->data;
	return true;
}

int LGetNext(List* plist, LData* pdata)
{
	if (plist->head == NULL) // ���Ұ� ������ false
		return false;
	else
	{
		plist->cur = plist->cur->next;

		*pdata = plist->cur->data;
	}
	return true;
}

int LGetBefore(List* plist, LData* pdata)
{
	if (plist->head == NULL) // ���Ұ� ������ false
		return false;
	else
	{
		plist->cur = plist->cur->before;

		*pdata = plist->cur->data;
	}
	return true;
}
//
LData LRemove(List* plist)
{
	if (plist->head != NULL)
	{
		Node* rpos = plist->cur;
		LData rdata = rpos->data;

		plist->cur->before->next = plist->cur->next; // Ŀ�� ���� ��� -> Ŀ�� ���� ���
		plist->cur->next->before = plist->cur->before; // Ŀ�� ���� ��� -> Ŀ�� ���� ���

		plist->cur = plist->cur->before; // Ŀ���� �ִ� �� ������ �Ŵϱ� Ŀ���� �ϳ� �ڷ� �Ű���.

		if (rpos == plist->head && plist->numOfData == 1)
			plist->head = NULL;
		else
			plist->head = plist->cur;

		free(rpos);
		(plist->numOfData)--;
		return rdata;
	}
	// cout << "�� ����Ʈ �Դϴ�";
}


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	List list;
	int N, K; // N�� ����� K�� ������ ��°
	int data;

	ListInit(&list);

	N = 1;
	K = 3;

	for (int i = 0; i < N; i++)
		LInsert(&list, i + 1);


	list.head = list.head->before;
	cout << "<";
	if (LGetFirst(&list, &data))    // ù ��° ������ ��ȸ
	{
		
		for (int i = 0; LGetNext(&list, &data); i++)    // �� ��° ������ ������ ��ȸ
		{
			if ((i+1) % K == 0)
			{
				data = LRemove(&list);
				if (list.numOfData > 0)
					cout << data << ", " ;
				else
					cout << data;
			}
		}
	}
	cout << ">";

	return 0;
}