#include <iostream>
#include "BinaryTree.h"
using namespace std;

void InorderTraverse(BTreeNode* bt)
{
	if (bt == NULL) {
		return;
	}
	InorderTraverse(bt->left);
	cout << bt->data << ' ';
	InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode* bt)
{
	if (bt == NULL) {
		return;
	}
	cout << bt->data << ' ';
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt)
{
	if (bt == NULL) {
		return;
	}
	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	cout << bt->data << ' ';
}

int main()
{
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();
	BTreeNode* bt6 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeRightSubTree(bt3, bt6);

	PreorderTraverse(bt1);
	cout << '\n';
	InorderTraverse(bt1);
	cout << '\n';
	PostorderTraverse(bt1);
	cout << '\n';

	return 0;
}