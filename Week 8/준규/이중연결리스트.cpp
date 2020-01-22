#include <iostream>

using namespace std;

typedef struct _node {
	int data;
	struct _node* next;
	struct _node* prev;
} Node;



int main(void) 
{
	Node nodeArr[100];
	int N, M;  // 2 <= N <= 100, 0 <= M <= 10
	cin >> N >> M;
	nodeArr[0].prev = NULL;
	nodeArr[N - 1].next = NULL;
	for (int i = 0; i < N; i++)
	{
		cin >> nodeArr[i].data;
		if (i != 0)
		{
			nodeArr[i].prev = &nodeArr[i - 1];
			nodeArr[i - 1].next = &nodeArr[i];
		}
	}
	Node* node = &nodeArr[0];

	for (int i = 0; i < M; i++)
	{
		char op;
		int a, b;
		Node* node_a = NULL;
		Node* node_b = NULL;

		cin >> op >> a >> b;
		if (a == b)
			continue;
		for (int j = 0; j < N; j++)
		{
			if (nodeArr[j].data == a)
				node_a = &nodeArr[j];

			if (nodeArr[j].data == b)
				node_b = &nodeArr[j];

			if (node_a != NULL && node_b != NULL)
				break;
		}


		switch (op)
		{
		case 'A':
			if (node_a->prev != NULL)
				node_a->prev->next = node_a->next;
			if (node_a->next != NULL)
				node_a->next->prev = node_a->prev;

			node_a->prev = node_b->prev;
			node_a->next = node_b;

			if (node_b->prev != NULL)
				node_b->prev->next = node_a;

			node_b->prev = node_a;


			break;
		case 'B':
			if (node_a->prev != NULL)
				node_a->prev->next = node_a->next;
			if (node_a->next != NULL)
				node_a->next->prev = node_a->prev;

			node_a->prev = node_b;
			node_a->next = node_b->next;

			if (node_b->next != NULL)
				node_b->next->prev = node_a;

			node_b->next = node_a;

			break;
		default:
			break;
		}
	}
	
	while (true)
	{
		if (node->prev == NULL)
			break;
		node = node->prev;
			
	}

	for (int i = 0; ; i++) {
		cout << node->data << " ";
		if (node->next == NULL)
			break;
		node = node->next;
	}

	return 0;
}