//heap sort를 배열로 구현
#include <iostream>
using namespace std;

int heap[100001];	//heap[0]에는 data의 개수 저장

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
	heap[0]++;	//저장된 data의 개수 1 증가
	
	//새로운 data를 마지막 노드에 저장
	index = heap[0];
	heap[index] = data;

	//추가된 data가 부모 node의 data보다 작으면 부모 node의 data와 교체
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
	int pop_data = heap[1];	//root node의 data

	//가장 마지막 node에 있는 data를 꺼내서 root node에 저장
	int index = heap[0];
	int data = heap[index];
	heap[0]--;	//data의 개수 1 감소
	index = 1;
	heap[index] = data;
	while (1) {
		int child1 = index * 2;
		int child2 = index * 2 + 1;
		//자식 node가 더이상 존재하지 않은 경우
		if (child1 > heap[0]) {
			break;
		}
		//자식 node가 1개인 경우
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
		//자식 node가 2개인 경우
		else {
			//부모 node가 자식 node보다 작거나 같은 경우
			if (data<=heap[child1] && data<=heap[child2]) {
				break;
			}
			//무조건 자식 node 중 하나는 부모 node보다 작은 경우
			else {
				//자식 node 중 작은 node의 data와 부모 node의 데이터 교체
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