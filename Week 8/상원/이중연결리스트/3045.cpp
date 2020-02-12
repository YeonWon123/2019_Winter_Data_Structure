
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;


// 구조체 
// link 저장해서 양방향으로 이동할 수 있음
struct Node {
	int data;
	struct Node* llink;
	struct Node* rlink;
};

void init(Node* phead) //헤드 노드를 초기화해주는 함수 
{
	phead->llink = phead;
	phead->rlink = phead;
}

void display(Node* phead) // 노드의 데이터를 보여주는 함수
{
	Node* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
		cout << p->data << " ";
	cout << "\n";
}

Node* create(int data) // 이중연결리스트에 삽입할 노드를 생성하는 함수 
{
	Node* new_node;
	new_node = new Node[sizeof(Node)];
	new_node->data = data;
	new_node->llink = NULL; new_node->rlink = NULL; // 양방향 NULL 초기화

	return new_node;
}
int cnt = 0;
Node* node_which(Node* pnode, int num) // 해당하는 위치에 있는 노드를 구하는 함수
{
	 
	if (num == (cnt + 1))
	{
		pnode = pnode->llink;
	}
	else if (num <= (cnt + 1) / 2)
	{
		for (int i = 0; i < num - 1; i++)
			pnode = pnode->rlink;
	}
	else
	{
		for (int i = 0; i < 2 + (cnt - num); i++)
			pnode = pnode->llink;
	}

	return pnode;
}

void dinsert_node(Node* p, Node* new_node, int num) // 삽입함수 
{
	if (num == 1)
	{
		new_node->llink = p;
		new_node->rlink = p->rlink;
		p->rlink->llink = new_node;
		p->rlink = new_node;
	}
	else
	{
		Node* pnode = node_which(p, num);

		new_node->llink = pnode;
		new_node->rlink = pnode->rlink;
		pnode->rlink->llink = new_node;
		pnode->rlink = new_node;
	}
	cnt++;
}

void dremove_node(Node* p, int num) // 삭제함수
{
	Node* remove = node_which(p, num + 1); // node_which 함수를 사용해서 노드위치구한다.
	cnt--;
	remove->llink->rlink = remove->rlink; 
	remove->rlink->llink = remove->llink; 
	delete[] remove;
}


int from, to;
void main()
{
	Node head_node;
	Node* Head;
	init(&head_node);
	int N, M, idx;
	cin >> N >> M; 
	for (int i = 1; i <= N; i++)
	{
		int val;
		cin >> val;
		dinsert_node(&head_node, create(val), val);// 1 2 3 4 5 6 
	}

	for (int i = 0; i < M; i++)
	{
		char cmd;
		cin >> cmd;
		if (cmd == 'A')
		{
			int idx = 0; // 삭제할 데이터의 위치를 찾기 위한 변수
			from, to;
			cin >> from >> to;
			Node* n;
			n = head_node.llink;
			while (1)
			{
				bool check = false;
				n = n->rlink;
				//cout << "n->data :" << n->data << "\n";
				if (from != n->data)
				{
					++idx;
				}
				if (from == n->data)
				{
					check = true;
				}
				if (check == true)
				{
					break;
				}
			} 
			dremove_node(&head_node, idx); 
			dinsert_node(&head_node, create(from), to-1 ); //  2 3 1 4 5 6
		}
		
		//display(&head_node); 2 3 1 4 5 6 
		if (cmd == 'B')
		{
			int idx = 0;// 삭제할 데이터의 위치를 찾기 위한 변수
			from, to;
			cin >> from >> to;
			Node* n;
			n = head_node.llink;
			while (1)
			{
				bool check = false;
				n = n->rlink;
				//cout << "n->data :" << n->data << "\n";
				if (from != n->data)
				{
					++idx;
				}
				if (from == n->data)
				{
					check = true;
				}
				if (check == true)
				{
					break;
				}
			}		
			dremove_node(&head_node, idx);
			dinsert_node(&head_node, create(from), to);
		}
	}
	
	display(&head_node);
}
