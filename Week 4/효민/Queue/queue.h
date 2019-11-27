#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct _node {
	int data;
	struct _node* back;
}Node;

typedef struct _queue {
	Node* front;
	Node* rear;
	int numOfData;
}Queue;

void init(Queue* pq);
void push(Queue* pq,int data);
int pop(Queue* pq);
int size(Queue* pq);
int empty(Queue* pq);
int front(Queue* pq);
int back(Queue* pq);
#endif // !__QUEUE_H__
