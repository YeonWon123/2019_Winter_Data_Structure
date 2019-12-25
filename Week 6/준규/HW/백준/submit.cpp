

#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;



typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

typedef BTreeNode* Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _listStack
{
	Node* head;
} ListStack;

typedef ListStack Stack;

typedef void VisitFuncPtr(BTData data);



int T, N; // 테스트 케이스 개수, 노드 개수
int node1[1000], node2[1000];




void StackInit(Stack* pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
		return true;
	else
		return false;
}

void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack* pstack)
{
	Data rdata;
	Node* rnode;

	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}




BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));

	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode* bt)
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);

}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}





BTreeNode* MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode* pnode;

	int expLen = strlen(exp);
	int i;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		pnode = MakeBTreeNode();

		if (isdigit(exp[i]))		// 피연산자
		{
			SetData(pnode, exp[i] - '0');
		}
		else					// 연산자
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}

		SPush(&stack, pnode);
	}

	return SPop(&stack);
}

int EvaluateExpTree(BTreeNode* bt)
{
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode* bt)
{
	InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowNodeData);
}





BTreeNode* GetTreeFromExp(int node1_idx, int node2_begin, int node2_end) //  현재 트리의 모든 노드가 존재하는 node1에서의 범위
{
	int idx = node2_begin;

	BTreeNode* node = MakeBTreeNode(); // 
	BTreeNode* node_a = NULL;
	BTreeNode* node_b = NULL;

	SetData(node, node1[node1_idx]); // 기준 노드의 값을 저장

	if (node2_begin == node2_end)
	{
		MakeLeftSubTree(node, node_a);
		MakeRightSubTree(node, node_b);

		return node;
	}

	for (; idx >= node2_begin && idx <= node2_end; idx++)
	{
		if (node2[idx] == node1[node1_idx]) // 기준 노드의 node2에서 위치 파악. 
		{
			break;
		}
	}
	// 기준 노드가 가장 왼쪽에 있지 않으면
	if (idx >= node2_begin + 1)
	{
		int a_node1_idx = node1_idx + 1; // 원래 위치 + 기준 노드 1개
		int a_node2_begin = node2_begin;
		int a_node2_end = node2_end - (1 + node2_end - idx);
		node_a = GetTreeFromExp(a_node1_idx, a_node2_begin, a_node2_end);
	}
	// 기준 노드가 가장 오른쪽에 있지 않으면
	if (idx <= node2_end - 1)
	{
		int b_node1_idx = node1_idx + 1 + idx - node2_begin; // 원래 위치 + 기준 노드 1개 + 기준 노드 왼쪽 노드
		int b_node2_begin = node2_begin + (1 + idx - node2_begin);
		int b_node2_end = node2_end;
		node_b = GetTreeFromExp(b_node1_idx, b_node2_begin, b_node2_end);
	}

	MakeLeftSubTree(node, node_a);
	MakeRightSubTree(node, node_b);

	return node;
}

void PrintNode(BTData node_data)
{
	printf("%d ", node_data);
}





int main(void)
{
	cin >> T;

	for (; T > 0; T--)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> node1[i];

		for (int i = 0; i < N; i++)
			cin >> node2[i];

		BTreeNode* node = GetTreeFromExp(0, 0, N - 1);

		PostorderTraverse(node, PrintNode);
		puts("");

	}
	return 0;
}