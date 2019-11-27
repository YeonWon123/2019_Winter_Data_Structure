#include <iostream>
#include "CLinkedList.h"
using namespace std;

void init(List* plist)
{
	plist->head = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}

void insert(List* plist)
{
	Node* newNode = new Node;
	if (plist->head == NULL) {
		plist->head = newNode;
	}
	else {
		plist->cur->next = newNode;
	}
	plist->cur = newNode;
	plist->numOfData++;
	newNode->data = plist->numOfData;
	newNode->next = plist->head;
}

int remove(List* plist, int num)
{
	Node* r;
	int res;
	if (plist->numOfData == 0) {
		return 0;
	}
	for (int i = 0; i < num - 1; i++) {
		plist->cur = plist->cur->next;
	}
	r = plist->cur->next;
	res = r->data;

	plist->cur->next = r->next;
	delete r;
	plist->numOfData--;
	return res;
}