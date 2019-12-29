#include <iostream>
using namespace std;

int tree_preorder[1001]; // ���� ��ȸ�� ���
int tree_inorder[1001];  // ���� ��ȸ�� ���

void recursion(int pre_start, int pre_end, int in_start, int in_end) {

//	cout << endl << "index : " << pre_start << " " << pre_end << " " << in_start << " " << in_end << endl;

	// 3 6 5 4 8 7 1 2 - ���� ��ȸ
	// 5 6 8 4 3 1 2 7 - ���� ��ȸ
	// �켱 ���� ��ȸ���� �� ���� ��� : Head
	// ���� Head�� 3�̴�.
	// ���� ��ȸ���� 3�� �������� �¿�� ������
	// Ž�� ����
	// 5 6 8 4 / 3 / 1 2 7

	if (in_start == in_end) {
		cout << tree_inorder[in_end] << " ";
		return;
	}

	// ���� ��ȸ �迭 �ȿ���, ���� ��ȸ �迭�� �� �� ��尡 ��� �ִ����� ã�´�.
	// �� ��带 �������� �¿�� ������ �ȴ�.
	for (int i = in_start; i <= in_end; i++) {
		if (tree_preorder[pre_start] == tree_inorder[i]) {
			recursion(pre_start + 1, pre_start + i - in_start, in_start, i - 1); // ����
			recursion(pre_start + i - in_start + 1, pre_end, i + 1, in_end); // ������
			cout << tree_inorder[i] << " ";	// �ڱ� ���
		}
		
	}


}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	// ���� Test Case�� ������ŭ �Է��� �޴´�.
	int T;
	cin >> T;

	// ������ Test Case�� ���� �����Ѵ�.
	for (int i = 0; i < T; i++) {
		int n;	// ����� ����
		cin >> n;

		// ���� ��ȸ�� ����� �Է¹޴´�.
		for (int j = 1; j <= n; j++) {
			cin >> tree_preorder[j];
		}

		// ���� ��ȸ�� ����� �Է¹޴´�.
		for (int j = 1; j <= n; j++) {
			cin >> tree_inorder[j];
		}

		// ���� ��ȸ�� ����� �Է��ؾ� �Ѵ�.
		// ��� �ؾ� �ұ�?
		// 3 6 5 4 8 7 1 2 - ���� ��ȸ
		// 5 6 8 4 3 1 2 7 - ���� ��ȸ
		// �켱 ���� ��ȸ���� �� ���� ��� : Head
		// ���� Head�� 3�̴�.
		// ���� ��ȸ���� 3�� �������� �¿�� ������
		// Ž�� ����
		// 5 6 8 4 / 3 / 1 2 7
		// ���� ���� ��ȸ���� �� ���� ��� : ���� ����Ʈ���� Head
		// 6�̹Ƿ�
		// 5 / 6 / 8 4 // 3 // 1 2 7 �� �з� ����
		// �̷� ������ �����ؼ�, ���� ��ȸ�� ���
		// 5 8 4 6 2 1 7 3 ���� ���� (3�� �� ���߿� ���)

		// ��� : recursion(��� ȣ��)
		recursion(1, n, 1, n);
		cout << "\n";
	}
	return 0;
}