//에디터
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

//List 초기화 (dump head의 data 'A'로 초기화)
void init(List* plist) {
	Node* newNode = new Node;
	plist->head = newNode;
	plist->cur = newNode;
	plist->numOfData = 0;
	newNode->data = 'A';
	newNode->after = NULL;
	newNode->before = NULL;
}

//Node 추가(cur의 after에 새 Node 추가)
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

//cur를 왼쪽으로 한 칸 옮김(cur이 head이면 움직이지 않음)
void Lfunc(List* plist) {
	if (plist->cur->data != 'A') {
		plist->cur = plist->cur->before;
	}
}

//cur를 오른쪽으로 한 칸 옮김(cur이 tail-cur의 after가 NULL-이면 움직이지 않음)
void Dfunc(List* plist) {
	if (plist->cur->after != NULL) {
		plist->cur = plist->cur->after;
	}
}

//Node 삭제(cur이 가리키는 Node 삭제 후 cur은 삭제한 Node의 after을 가리킴)
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

//Node 추가(data가 ch인 새 Node를 cur의 before에 추가)
//? 커서의 왼쪽에 새 Node 추가?
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