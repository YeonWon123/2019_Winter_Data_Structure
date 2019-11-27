#include <iostream>
#include "queue.h"
using namespace std;

void init(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->numOfData = 0;
}
void push(Queue* pq, int data)
{
	Node* newNode = new Node;
	if (pq->front == NULL) {
		pq->front = newNode;
	}
	newNode->back = pq->rear;
	newNode->data = data;
	pq->rear = newNode;
	pq->numOfData++;
}
int pop(Queue* pq)
{
	Node* r;
	int res;
	if (pq->numOfData == 0) {
		return -1;
	}
	r = pq->rear;
	res = r->data;
	pq->rear = r->back;
	delete r;
	pq->numOfData--;
	return res;
}
int size(Queue* pq)
{
	return pq->numOfData;
}
int empty(Queue* pq)
{
	if (pq->numOfData == 0) {
		return 0;
	}
	return 1;
}
int front(Queue* pq)
{
	if (pq->numOfData == 0) {
		return -1;
	}
	return pq->front->data;
}
int back(Queue* pq)
{
	if (pq->numOfData == 0) {
		return -1;
	}
	return pq->rear->data;
}