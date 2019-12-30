#include <iostream>
#include "BinaryTree.h"
using namespace std;

TreeNode* node[50];

int main()
{
	int n;
	int k;
	int res = 0;
	int rootNumber = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		node[i] = MakeTreeNode();
	}
	for (int child = 0; child < n; child++) {
		int parent;
		cin >> parent;
		if (parent == -1) {
			rootNumber = child;
		}
		else {
			if (node[parent]->left == NULL) {
				MakeLeftSubTree(node[parent], node[child]);
				SetIntData(node[child], parent, 0);
			}
			else {
				MakeRightSubTree(node[parent], node[child]);
				SetIntData(node[child], parent, 1);
			}
		}

	}
	int parent;
	int dir;
	cin >> k;
	parent = node[k]->parent;
	dir = node[k]->dir;
	RemoveTreeNode(node[k]);
	if (parent != -1) {
		if (dir == 0) {
			node[parent]->left = NULL;
		}
		else {
			node[parent]->right = NULL;
		}
	}
	CountLeafNode(node[rootNumber], res);
	cout << res;

	RemoveTreeNode(node[rootNumber]);
	return 0;
}