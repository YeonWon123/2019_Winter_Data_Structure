

#include <iostream>

using namespace std;

typedef int QData;

typedef struct _DCQNODE {
	QData data;
	_DCQNODE* prev;
	_DCQNODE* next;
} DCQNode;

typedef struct _DCQUEUE {
	int size; // 원소의 수
	DCQNode* cur; // 큐의 진입지점
}DCQueue;

enum Direction {LEFT, RIGHT};

void dcqueue_init(DCQueue* pq); // 큐를 초기화 하는 함수
void dcqueue_push(DCQueue* pq, QData data); // 어떤 자연수를 받아서 cur가 가리키는 노드(c2)의 앞에 추가하는 함수, 즉 c1 - c2 - c3 가 c1 - new - c2 - c3 // size + 1 필요
void dcqueue_move(DCQueue* pq, int dir); // cur를 이동시키는 함수
void dcqueue_pop(DCQueue* pq); // cur가 가리키는 노드를 제거하고 RIGHT를 가리킨다, size - 1 필요

int i, j, k;
int N; // 원소의 수 // 1 <= N <= 50
int M; // 뽑아 내려고 하는 수의 개수 // M <= N
int target_arr[50]; // 제거할 수의 배열
int count;
int sum_min; // 구하고 싶은 최소 이동 연산 횟수

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	// 양방향 순환 큐를 만들고 초기화한다.
	DCQueue* que = (DCQueue*)malloc(sizeof(DCQueue));
	dcqueue_init(que);

	// 전체 원소의 수에 따라서 양방향 순환 큐(DCQueue)를 만든다.
	for (i = 0; i < N; i++) {
		dcqueue_push(que, i + 1); 
	}

	// 제거하려는 값을 입력받는다.
	for (i = 0; i < M; i++) {
		cin >> target_arr[i];

		// 받은 값을 노드 중에서 찾아서 제거한다.
		for (j = 0; j < N - 1; j++) { //  j == 0 이면 바로 찾았다는 뜻 // 원소수가 1이다 => 그냥 바로 찾게됨. 뽑는 수는최소 1개 이상이므로 무조건 하나 찾고 끝. 즉 답 = 0
			if (que->cur->data == target_arr[i]) {
				int right_cnt = j;
				int left_cnt = que->size - right_cnt;

				dcqueue_pop(que);

				sum_min += (right_cnt > left_cnt ? left_cnt : right_cnt); // 둘 중에 더 작은 쪽을 sum_min에 더함

				break;
			}
			else { // 못찾으면 다음 위치로
				dcqueue_move(que, RIGHT);
			}
		}

	}

	cout << sum_min;

	return 0;
}

void dcqueue_init(DCQueue* pq) {
	pq->cur = (DCQNode*)malloc(sizeof(DCQNode)); // 새 노드를 하나 만들어서 커서가 가리키게 한다.
	pq->size = 0;
}
void dcqueue_push(DCQueue* pq, QData data) {
	if (pq->size == 0) { // 텅빈 큐인 경우
		pq->cur->data = data;
		pq->cur->next = pq->cur; // 다음 것도 나고
		pq->cur->prev = pq->cur; // 이전 것도 나다
		pq->size = 1; // 원소수 1개
	}
	else { // 큐가 먼저 들어있으면
		DCQNode* new_node = (DCQNode*)malloc(sizeof(DCQNode));
		new_node->data = data;
		new_node->prev = pq->cur->prev; // 원래 커서의 뒤에 있던 녀석의 앞
		new_node->next = pq->cur; // 커서의 뒤에 붙일 것
		pq->cur->prev->next = new_node; // 커서의 원래 뒷놈 앞이 new node
		pq->cur->prev = new_node; // 커서의 뒤는 new node
		pq->size++; // 원소수 증가
	}
}
void dcqueue_move(DCQueue* pq, int dir) {
	switch (dir)
	{
	case LEFT: // 커서를 왼쪽으로 움직이는 경우
		pq->cur = pq->cur->prev;
		break;
	case RIGHT: // 커서를 오른쪽으로 움직이는 경우
		pq->cur = pq->cur->next;
		break;
	default:
		break;
	}
}
void dcqueue_pop(DCQueue* pq) {
	if (pq->size == 0) {
		return; // 불가능
	}
	else if (pq->size == 1) { // 원소가 한 개 뿐이면 정보만 지우고 노드는 남김
		pq->cur->data = 0;
		pq->cur->next = NULL;
		pq->cur->prev = NULL;
		pq->size = 0;
	}
	else {
		DCQNode* new_cur = pq->cur->next;
		DCQNode* pre_cur = pq->cur;
		pre_cur->prev->next = pre_cur->next; // 커서의 이전 노드가 커서의 다음 노드를 가리키고
		pre_cur->next->prev = pre_cur->prev; // 커서의 다음 노드가 커서의 이전 노드를 가리킨다.

		pre_cur->data = 0;
		pre_cur->next = NULL;  
		pre_cur->prev = NULL;

		pq->cur = new_cur; // 커서를 원래 커서의 다음 노드로 설정한다.

		pq->size--;
	}
}

