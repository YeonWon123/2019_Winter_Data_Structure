
#include <stdio.h>
#include "PriorityQueue.h"
#include <iostream>

using namespace std;

int DataPriorityComp(char ch1, char ch2) {
	return ch2 - ch1;
}

int main(void) {
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	cout << PDequeue(&pq) << endl;


	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	cout << PDequeue(&pq) << endl;

	while (!PQIsEmpty(&pq))
		cout << PDequeue(&pq) << endl;
	return 0;
}