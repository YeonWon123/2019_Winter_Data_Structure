#include<iostream>
#include<vector>

using namespace std;

class Heap {
public:
	vector<int> v;
	int heap_size;
	int root_index = 1;

	Heap() {
		v.push_back(-1); // �ʱ�ȭ
		heap_size = 0;
	}

	void _swap(int index1, int index2) { //swap �Լ� 
		v[0] = v[index1];
		v[index1] = v[index2];
		v[index2] = v[0];
	}

	void Upheap(int index) { //  ���� ���ο� ���� ����
		if (index == root_index)return;
		int parent = index / 2;
		if (v[parent] < v[index]) { // �θ���� ���� ���Ͽ�  �� ũ�ٸ�
			_swap(parent, index); // ��ġ�� ��ȯ�Ѵ�
			Upheap(parent); //��Ʈ ������ ��ġ�ϰų� �θ� ��庸�� ���� �� ���� �ݺ��Ѵ�.
		}
		else return;
	}

	void Downheap(int index) { // ������ ��带 ���� 
		// ���� ���� ���� Ʈ���� �����Ǳ⿡
		// Ư�� index�� left, right 
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
	void insert(int num) { // ���� �Լ� 
		v.push_back(num);
		heap_size++;
		Upheap(heap_size);
	}
	int remove() { // ���� �Լ� 
		int ret = v[1];
		v[1] = v[heap_size--];
		v.pop_back();
		Downheap(root_index);
		return ret;
	}
	bool empty() { // empty Ȯ�� 
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