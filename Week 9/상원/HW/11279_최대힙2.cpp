#include<iostream>
#include<vector>

using namespace std;

class Heap {
public:
	vector<int> v;
	int heap_size;
	int root_index = 1;

	Heap() {
		v.push_back(-1); // 초기화
		heap_size = 0;
	}

	void _swap(int index1, int index2) { //swap 함수 
		v[0] = v[index1];
		v[index1] = v[index2];
		v[index2] = v[0];
	}

	void Upheap(int index) { //  힙에 새로운 원소 삽입
		if (index == root_index)return;
		int parent = index / 2;
		if (v[parent] < v[index]) { // 부모노드와 값을 비교하여  더 크다면
			_swap(parent, index); // 위치를 교환한다
			Upheap(parent); //루트 노드까지 위치하거나 부모 노드보다 작을 때 까지 반복한다.
		}
		else return;
	}

	void Downheap(int index) { // 힙에서 노드를 제거 
		// 힙은 완전 이진 트리로 구성되기에
		// 특정 index의 left, right 
		int left = index * 2;
		int right = index * 2 + 1;

		if (right <= heap_size) {
			if (v[left] > v[right]) {
				if (v[left] > v[index]) {
					_swap(left, index);
					Downheap(left);
				}
				else return;

			}
			else {
				if (v[right] > v[index]) {
					_swap(right, index);
					Downheap(right);
				}
				else return;
			}
		}
		else {
			if (left <= heap_size) {
				if (v[left] > v[index]) {
					_swap(left, index);
				}
			}
			else return;
		}
	}
	void insert(int num) { // 삽입 함수 
		v.push_back(num);
		heap_size++;
		Upheap(heap_size);
	}
	int remove() { // 제거 함수 
		int ret = v[1];
		v[1] = v[heap_size--];
		v.pop_back();
		Downheap(root_index);
		return ret;
	}
	bool empty() { // empty 확인 
		if (heap_size == 0) return true;
		else return false;
	}
};

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	Heap heap;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (heap.empty()) cout << "0" << "\n";
			else cout << heap.remove() << "\n";

		}
		else {
			heap.insert(num);
		}
	}
}