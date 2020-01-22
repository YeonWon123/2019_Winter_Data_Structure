#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

enum{ LEFT, RIGHT };
enum { PRE, IN, POST };

typedef int BTData;

typedef struct _btreenode
{
	BTData data;
	struct _btreenode* leftSub;
	struct _btreenode* rightSub;
} BTree;

BTree* InitBTree(BTData data); //tree 초기화(사용 준비)
bool MakeSubBTree(BTree* parent, BTree* child, int direct);// tree에 왼쪽 또는 오른쪽에 서브 트리 삽입
bool RemoveBTree(BTree* bt); //  트리를 제거
bool TravelBTree(BTree* bt, void (*action)(BTData var), int type); //트리 탐색

void ShowNodeData(BTData var);

////////////////////////  문제L tree 순회  //////////////////////

int T; // 테스트 케이스 수
int N; // 노드의 개수

// 전위 순회 결과, 최초로 나오는 것은 항상 (서브)트리의 루트이다
int PreArr[1000]; 

// 중위 순회 결과, 모든 노드에서 좌측 탐색이 끝나면 본인을 탐색하고 우측 탐색을 시작한다. 
// 루트 노드가 출력되는 위치를 알면 좌우 서브트리의 구성 요소를 알 수 있다.
// 전위 순회 결과로 알아낸 서브트리의 루트
int InArr[1000]; 

BTree* bt;

BTree* GetTreeFromArr(int n, int left, int right) // PreArr에서 루트의 위치, InArr에서의 왼쪽 한계선과 오른쪽 한계선 
{
	// 서브트리의 루트를 만든다.
	BTree* bt_root;
	bt_root = InitBTree(PreArr[n]);

	int m = 0, r = 0;

	if (left == right) // 루트가 서브트리를 가지지 않는다.
		return bt_root;

	for (int i = left; i <= right; i++) // 서브트리의 루트가 InArr에서 어디에 위치하는지 찾는다.
	{
		if (bt_root->data == InArr[i]) // 반드시 존재한다
		{
			m = i;
			break;
		}
	}
	
	// 모든 조건을 정리하면
	r = (m - 1) - left + 1; // 왼쪽 서브트리의 원소 수
	if (left < m)
		MakeSubBTree(bt_root, GetTreeFromArr(n + 1, left, m - 1), LEFT);
	if (right > m)
		MakeSubBTree(bt_root, GetTreeFromArr(n + r + 1, m + 1, right), RIGHT);

	return bt_root;
}

int main(void)
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		for (int j = 0; j < N; j++)
			cin >> PreArr[j];

		for (int j = 0; j < N; j++)
			cin >> InArr[j];

		bt = GetTreeFromArr(0, 0, N - 1);
        
		TravelBTree(bt, ShowNodeData, POST);
		cout << endl;
	}
	return 0;
}

BTree* InitBTree(BTData data)
{
	BTree* bt;
	bt = (BTree*)malloc(sizeof(BTree));

	bt->data = data;
	bt->leftSub = NULL;
	bt->rightSub = NULL;

	return bt;
}

bool MakeSubBTree(BTree* parent, BTree* child, int direct)
{
	if (direct == LEFT)
		parent->leftSub = child;

	if (direct == RIGHT)
		parent->rightSub = child;;

	return true;
}

bool RemoveBTree(BTree* bt)
{
	if (bt->leftSub != NULL)
		RemoveBTree(bt->leftSub);

	if (bt->rightSub != NULL)
		RemoveBTree(bt->rightSub);

	if (bt != NULL) // 초기화되지 않은 트리도 제거가 가능해야 한다.
		free(bt);

	else  // 존재하지 않는 트리를 삭제할 수 없다.
		return false;

	return true;
}

bool TravelBTree(BTree* bt, void (*action)(BTData var), int type) 
{
	if (bt == NULL) // 존재하지 않는 트리를 탐색할 수 없다.
		return false;

	if (type == 0) // 전위
		action(bt->data);

	if (bt->leftSub != NULL)
		TravelBTree(bt->leftSub, action, type);

	if (type == 1) // 중위
		action(bt->data);

	if (bt->rightSub != NULL)
		TravelBTree(bt->rightSub, action, type);

	if (type == 2) // 후위
		action(bt->data);

	return true;
}

void ShowNodeData(BTData var)
{
	cout << var << " ";
}
