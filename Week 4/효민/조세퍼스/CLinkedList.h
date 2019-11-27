#ifndef __CLINKEDLIST_H__
#define __CLINKEDLIST_H__

typedef struct _node
{
	int data;
	struct _node* next;
}Node;

typedef struct _list
{
	Node* head;
	Node* cur;
	int numOfData;
}List;

void init(List* plist);
void insert(List* plist);
int remove(List* plist, int num);
#endif // !__CLINKEDLIST_H__
