#include <iostream>

using namespace std;

int n;
int inorder[100000];
int postorder[100000];
int position[100001];

void preorder(int in_start, int in_end, int post_start, int post_end) 
{
	if (in_start > in_end || post_start > post_end)
		return;

	int root = postorder[post_end];
	cout << root << " ";
	int p = position[root];
	// inorder���� ��Ʈ ���� �ڽ��� � �ִ��� ����
	int left = p - in_start;

	// ��Ʈ�� �������� �������� �̵�
	preorder(in_start, p - 1, post_start, post_start + left - 1);
	// ��Ʈ�� �������� ���������� �̵�
	preorder(p + 1, in_end, post_start + left, post_end - 1);
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}
	for (int i = 0; i < n; i++) {
		// inorder���� �ش� i(root)�� ���° ��ġ�ϰ� �ִ��� ����
		position[inorder[i]] = i;
	}

	preorder(0, n - 1, 0, n - 1);
	return 0;
}