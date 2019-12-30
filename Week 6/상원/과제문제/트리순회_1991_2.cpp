#include<iostream>
using namespace std;

typedef struct _node
{
	char left;
	char right;
}Node;

Node Arr[100];

void preorder(char root)
{
	if (root == '.')
		return;
	else
	{
		cout << root;
		preorder(Arr[root].left);
		preorder(Arr[root].right);
	}
}
void inorder(char root)
{
	if (root == '.')
		return;
	else
	{
		inorder(Arr[root].left);
		cout << root;
		inorder(Arr[root].right);
	}
}
void postorder(char root)
{
	if (root == '.')
		return;
	else
	{
		postorder(Arr[root].left);
		postorder(Arr[root].right);
		cout << root;
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;
		Arr[root].left = left;
		Arr[root].right = right;
	}
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";


}