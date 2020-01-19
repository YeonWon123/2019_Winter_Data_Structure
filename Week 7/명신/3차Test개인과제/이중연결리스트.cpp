#include<iostream>
using namespace std;

//Node struct 생성
struct Node {
	int data;
	Node* next, * prev;

	Node() {
		next = prev = NULL;
		data = 0;
	}

	Node(int i, Node* ptr)//ptr 뒤에 추가한다.
	{
		data = i;
		prev = ptr;
		next = ptr->next;
		next->prev = prev->next = this;
	}

	void selvDelete() {
		prev->next = next;
		next->prev = prev;
		delete this;
	}

};

//연결 리스트 생성~
struct DLinkedList {
	Node* head;
	Node* tail;
	int count;
	DLinkedList() { //생성자
		count = 0;
		head = new Node(); //더미를 선언해서 가지고 있게한다.
		tail = new Node(); //더미를 선언해서 가지고 있게한다.
		head->next = tail; //서로연결한다.
		tail->prev = head;
	}
	~DLinkedList() {
		while (head->next != tail)
			head->next->selvDelete();
		delete head;
		delete tail;
	}
	void firstInsert(int i) { //head 다음에 추가한다.
		new Node(i, head);
	}
	void endInsert(int i) { //tail 앞에 추가한다.
		new Node(i, tail->prev);
	}
	void firstDelete() { //head 다음 노드 삭제한다.
		if (head->next == tail)    return;
		head->next->selvDelete();
	}
	void endDelete() { //tail 앞에 제거한다.
		if (tail->prev == head) return;
		tail->prev->selvDelete();
	}
	void printAll() {
		Node* tmp = head;
		while (tmp->next != tail) {
			cout << tmp->next->data << " ";
			tmp = tmp->next;
		}
	}
	
	//새로만든부분
	Node* Findptr(int target)
	{
		Node* tmpz = head;
		while (tmpz != tail)
		{
			if (tmpz->data == target) return tmpz;
			else tmpz = tmpz->next;
		}
		cout << "찾는 data가 list내 존재하지 않습니다." << endl;
		return 0;
	}


	void FuncA_front(int from, int target)
	{
		Node* fromptr = Findptr(from);
		Node* targetptr = Findptr(target);

		int temp = fromptr->data;

		fromptr->selvDelete();
		Node(temp, targetptr);

		/*
		from의 위치와 target의 위치를 찾는다.
		from의 데이터를 삭제해 Node(from의data,target위치)
		*/
	}

	void FuncB_back(int from, int target)
	{
		Node* fromptr = Findptr(from);
		Node* targetptr = Findptr(target);

		int temp = fromptr->data;

		fromptr->selvDelete();
		Node(temp, targetptr->next);
		/*
		from의 위치와 target의 위치를 찾는다.
		from의 데이터를 삭제해 Node(from의data,target위치->next)
		*/
	}
};

int main() {

	DLinkedList* list = new DLinkedList();
	int N, M;
	cin >> N >> M;
	
	int input;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		list->endInsert(input);
	}

	char c;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> c;
		switch (c)
		{
		case 'A':
			cin >> a >> b;
			list->FuncA_front(a, b);
			break;
		case 'B':
			cin >> a >> b;
			list->FuncB_back(a, b);
			break;
		default:
			break;
		}
	}
	list->printAll();
	delete list;

	return 0;
}
