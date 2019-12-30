#include <iostream>
#include "BinaryTree.h"
using namespace std;

TreeNode* MakeTreeNode()
{
	TreeNode* temp = new TreeNode;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void SetIntData(TreeNode* bt, int parent, int dir)
{
	bt->parent = parent;
	bt->dir = dir;

}
void MakeLeftSubTree(TreeNode* main, TreeNode* sub)
{
	main->left = sub;
}
void MakeRightSubTree(TreeNode* main, TreeNode* sub)
{
	main->right = sub;
}
void RemoveTreeNode(TreeNode* remove)
{
	if (remove == NULL) {
		return;
	}
	RemoveTreeNode(remove->left);
	RemoveTreeNode(remove->right);
	delete remove;
	remove = NULL;
}
void CountLeafNode(TreeNode* bt, int& count)
{
	if (bt == NULL) {
		return;
	}
	if (bt->left == NULL && bt->right == NULL) {
		count++;
	}
	else {
		if (bt->left != NULL) {
			CountLeafNode(bt->left, count);
		}
		if (bt->right != NULL) {
			CountLeafNode(bt->right, count);
		}
	}
	return;
}