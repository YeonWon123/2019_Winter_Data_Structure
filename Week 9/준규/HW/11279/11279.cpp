

#include <iostream>
#include <functional>

using namespace std;

typedef struct _heap {
	int arr[100001];
	int idx;
	function<int(int, int)> comp; 
} Heap;

int N;
int x;
Heap hp;
const int MIN = 0;


void swap_heap(int i, int j) 
{
	int tmp = hp.arr[i];
	hp.arr[i] = hp.arr[j];
	hp.arr[j] = tmp;
}

void back_refact() { 
	
	
	if (hp.idx <= 2) 
	{
		return;
	}
	for (int now_idx = hp.idx - 1; ;)
	{
		if (now_idx == 1) 
		{
			break;
		}
		int parent_idx = now_idx / 2;
		if (hp.comp(hp.arr[now_idx], hp.arr[parent_idx]) > 0) 
		{
			swap_heap(now_idx, parent_idx);
			now_idx = parent_idx;
			continue;
		}
		else
		{
			break;
		}
	}
}

void front_refact() { 
	if (hp.idx <= 2) 
	{
		return;
	}
	for (int now_idx = 1; ;)
	{
		int left_idx = 2 * now_idx; 
		int right_idx = left_idx + 1;

		if (left_idx >= hp.idx) 
		{
			return;
		}
		if (right_idx >= hp.idx) 
		{
			if (hp.comp(hp.arr[now_idx], hp.arr[left_idx]) < 0) 
			{
				swap_heap(now_idx, left_idx);
				now_idx = left_idx;
				continue;
			}
			else 
			{
				break;
			}
		}
		else 
		{
			int max_child_idx = hp.comp(hp.arr[left_idx], hp.arr[right_idx]) > 0 ? left_idx : right_idx; 
			if (hp.comp(hp.arr[now_idx], hp.arr[max_child_idx]) < 0) 
			{
				swap_heap(now_idx, max_child_idx);
				now_idx = max_child_idx;
				continue;
			}
			else 
			{
				break;
			}
		}
	}
}

int pop()  
{
	if (hp.idx == 1) 
	{
		return 0;
	}
	else
	{
		swap_heap(1, hp.idx - 1); 
		int output = hp.arr[hp.idx - 1]; 
		hp.arr[hp.idx - 1] = MIN; 
		hp.idx--;

		front_refact(); 

		return output;
	}
}

void insert(int x)  
{
	hp.arr[hp.idx] = x; 
	hp.idx++;

	back_refact();
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	hp.comp = [](int a, int b) { return a - b; };
	hp.idx = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 0)
		{
			cout << pop() << "\n";
		}
		else
		{
			insert(x);
		}
	}

	return 0;
}