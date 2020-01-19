#include<iostream>
using namespace std;

//Node struct ����
struct Node {
	int data;
	Node* next, * prev;

	Node() {
		next = prev = NULL;
		data = 0;
	}

	Node(int i, Node* ptr)//ptr �ڿ� �߰��Ѵ�.
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

//���� ����Ʈ ����~
struct DLinkedList {
	Node* head;
	Node* tail;
	int count;
	DLinkedList() { //������
		count = 0;
		head = new Node(); //���̸� �����ؼ� ������ �ְ��Ѵ�.
		tail = new Node(); //���̸� �����ؼ� ������ �ְ��Ѵ�.
		head->next = tail; //���ο����Ѵ�.
		tail->prev = head;
	}
	~DLinkedList() {
		while (head->next != tail)
			head->next->selvDelete();
		delete head;
		delete tail;
	}
	void firstInsert(int i) { //head ������ �߰��Ѵ�.
		new Node(i, head);
	}
	void endInsert(int i) { //tail �տ� �߰��Ѵ�.
		new Node(i, tail->prev);
	}
	void firstDelete() { //head ���� ��� �����Ѵ�.
		if (head->next == tail)    return;
		head->next->selvDelete();
	}
	void endDelete() { //tail �տ� �����Ѵ�.
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
	
	//���θ���κ�
	Node* Findptr(int target)
	{
		Node* tmpz = head;
		while (tmpz != tail)
		{
			if (tmpz->data == target) return tmpz;
			else tmpz = tmpz->next;
		}
		cout << "ã�� data�� list�� �������� �ʽ��ϴ�." << endl;
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
		from�� ��ġ�� target�� ��ġ�� ã�´�.
		from�� �����͸� ������ Node(from��data,target��ġ)
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
		from�� ��ġ�� target�� ��ġ�� ã�´�.
		from�� �����͸� ������ Node(from��data,target��ġ->next)
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
