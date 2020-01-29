//heap sort�� �迭�� ����
#include <iostream>
using namespace std;

int heap[100001];	//heap[0]���� data�� ���� ����

bool HisEmpty() {
	if (heap[0] == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Hpush(int data) {
	int index;
	int parent;
	heap[0]++;	//����� data�� ���� 1 ����
	
	//���ο� data�� ������ ��忡 ����
	index = heap[0];
	heap[index] = data;

	//�߰��� data�� �θ� node�� data���� ������ �θ� node�� data�� ��ü
	parent = index / 2;
	while (parent > 0) {
		if (heap[parent] > data) {
			heap[index] = heap[parent];
			heap[parent] = data;
			index = parent;
			parent = index / 2;
		}
		else {
			break;
		}
	}
}

int Hpop() {
	int pop_data = heap[1];	//root node�� data

	//���� ������ node�� �ִ� data�� ������ root node�� ����
	int index = heap[0];
	int data = heap[index];
	heap[0]--;	//data�� ���� 1 ����
	index = 1;
	heap[index] = data;
	while (1) {
		int child1 = index * 2;
		int child2 = index * 2 + 1;
		//�ڽ� node�� ���̻� �������� ���� ���
		if (child1 > heap[0]) {
			break;
		}
		//�ڽ� node�� 1���� ���
		else if (child2 > heap[0] && child1 <= heap[0]) {
			if (heap[child1] < data) {
				heap[index] = heap[child1];
				heap[child1] = data;
				index = child1;
			}
			else {
				break;
			}
		}
		//�ڽ� node�� 2���� ���
		else {
			//�θ� node�� �ڽ� node���� �۰ų� ���� ���
			if (data<=heap[child1] && data<=heap[child2]) {
				break;
			}
			//������ �ڽ� node �� �ϳ��� �θ� node���� ���� ���
			else {
				//�ڽ� node �� ���� node�� data�� �θ� node�� ������ ��ü
				if (heap[child1] < heap[child2]) {
					heap[index] = heap[child1];
					heap[child1] = data;
					index = child1;
				}
				else {
					heap[index] = heap[child2];
					heap[child2] = data;
					index = child2;
				}
			}
		}
	}
	return pop_data;
}

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		if (data == 0) {
			if (HisEmpty()) {
				cout << '0' << '\n';
			}
			else {
				cout << Hpop() << '\n';
			}
		}
		else {
			Hpush(data);
		}
	}
}