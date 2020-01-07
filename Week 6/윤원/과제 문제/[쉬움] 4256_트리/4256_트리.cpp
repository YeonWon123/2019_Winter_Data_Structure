#include <iostream>
using namespace std;

int tree_preorder[1001]; // 전위 순회한 결과
int tree_inorder[1001];  // 중위 순회한 결과

void recursion(int pre_start, int pre_end, int in_start, int in_end) {

//	cout << endl << "index : " << pre_start << " " << pre_end << " " << in_start << " " << in_end << endl;

	// 3 6 5 4 8 7 1 2 - 전위 순회
	// 5 6 8 4 3 1 2 7 - 중위 순회
	// 우선 전위 순회에서 맨 앞의 노드 : Head
	// 따라서 Head는 3이다.
	// 중위 순회에서 3을 기준으로 좌우로 나누고
	// 탐색 시작
	// 5 6 8 4 / 3 / 1 2 7

	if (in_start == in_end) {
		cout << tree_inorder[in_end] << " ";
		return;
	}

	// 중위 순회 배열 안에서, 전위 순회 배열의 맨 앞 노드가 어디에 있는지를 찾는다.
	// 그 노드를 기준으로 좌우로 나누면 된다.
	for (int i = in_start; i <= in_end; i++) {
		if (tree_preorder[pre_start] == tree_inorder[i]) {
			recursion(pre_start + 1, pre_start + i - in_start, in_start, i - 1); // 왼쪽
			recursion(pre_start + i - in_start + 1, pre_end, i + 1, in_end); // 오른쪽
			cout << tree_inorder[i] << " ";	// 자기 출력
		}
		
	}


}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// 먼저 Test Case의 개수만큼 입력을 받는다.
	int T;
	cin >> T;

	// 각각의 Test Case에 대해 수행한다.
	for (int i = 0; i < T; i++) {
		int n;	// 노드의 개수
		cin >> n;

		// 전위 순회한 결과를 입력받는다.
		for (int j = 1; j <= n; j++) {
			cin >> tree_preorder[j];
		}

		// 중위 순회한 결과를 입력받는다.
		for (int j = 1; j <= n; j++) {
			cin >> tree_inorder[j];
		}

		// 후위 순회한 결과를 입력해야 한다.
		// 어떻게 해야 할까?
		// 3 6 5 4 8 7 1 2 - 전위 순회
		// 5 6 8 4 3 1 2 7 - 중위 순회
		// 우선 전위 순회에서 맨 앞의 노드 : Head
		// 따라서 Head는 3이다.
		// 중위 순회에서 3을 기준으로 좌우로 나누고
		// 탐색 시작
		// 5 6 8 4 / 3 / 1 2 7
		// 다음 전위 순회에서 그 다음 노드 : 왼쪽 서브트리의 Head
		// 6이므로
		// 5 / 6 / 8 4 // 3 // 1 2 7 로 분류 가능
		// 이런 식으로 수행해서, 후위 순회할 경우
		// 5 8 4 6 2 1 7 3 으로 수행 (3을 맨 나중에 출력)

		// 방법 : recursion(재귀 호출)
		recursion(1, n, 1, n);
		cout << "\n";
	}
	return 0;
}