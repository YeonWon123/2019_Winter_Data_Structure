//������
#include <iostream>
using namespace std;
typedef struct _node {
	_node* before;
	_node* after;
	char data;
}Node;
typedef struct _list {
	Node* head;
	Node* cur;
	int numOfData;
	char data;
}List;

//List �ʱ�ȭ (dump head�� data 'A'�� �ʱ�ȭ)
void init(List* plist) {
	Node* newNode = new Node;
	plist->head = newNode;
	plist->cur = newNode;
	plist->numOfData = 0;
	newNode->data = 'A';
	newNode->after = NULL;
	newNode->before = NULL;
}

//Node �߰�(cur�� after�� �� Node �߰�)
void add(List* plist, char data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->after = plist->cur->after;
	newNode->before = plist->cur;
	if (plist->cur->after != NULL) {
		plist->cur->after->before = newNode;
	}
	plist->cur->after = newNode;
	plist->cur = newNode;
	plist->numOfData++;
}

//cur�� �������� �� ĭ �ű�(cur�� head�̸� �������� ����)
void Lfunc(List* plist) {
	if (plist->cur->data != 'A') {
		plist->cur = plist->cur->before;
	}
}

//cur�� ���������� �� ĭ �ű�(cur�� tail-cur�� after�� NULL-�̸� �������� ����)
void Dfunc(List* plist) {
	if (plist->cur->after != NULL) {
		plist->cur = plist->cur->after;
	}
}

//Node ����(cur�� ����Ű�� Node ���� �� cur�� ������ Node�� after�� ����Ŵ)
void Bfunc(List* plist) {
	if (plist->cur->data != 'A') {
		if (plist->cur->after != NULL) {
			plist->cur->after->before = plist->cur->before;
		}
		plist->cur->before->after = plist->cur->after;
		plist->cur = plist->cur->before;
		plist->numOfData--;
	}
}

//Node �߰�(data�� ch�� �� Node�� cur�� before�� �߰�)
//? Ŀ���� ���ʿ� �� Node �߰�?
void Pfunc(List* plist, char ch) {
	//Lfunc(plist);
	add(plist, ch);
	//Dfunc(plist);
}
void show(List* plist) {
	plist->cur = plist->head;
	for (int i = 0; i < plist->numOfData; i++) {
		plist->cur = plist->cur->after;
		cout << plist->cur->data;
	}
}
int main() {
	List list;
	char ch;
	int n;
	init(&list);
	ch = getchar();
	while (ch != '\n') {
		add(&list, ch);
		ch = getchar();
	}
	cin >> n;
	ch = getchar();
	for (int i = 0; i < n; i++) {
		ch = getchar();
		switch (ch)
		{
		case 'L':
			Lfunc(&list);	break;
		case 'D':
			Dfunc(&list);	break;
		case 'B':
			Bfunc(&list);	break;
		case 'P':
			ch = getchar();
			ch = getchar();
			Pfunc(&list, ch);
			break;
		default:
			break;
		}
		ch = getchar();
	}
	show(&list);
}