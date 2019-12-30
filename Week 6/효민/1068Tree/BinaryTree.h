#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

typedef struct _node {
	int parent;
	int dir;
	struct _node* left;
	struct _node* right;
}TreeNode;

TreeNode* MakeTreeNode();

void SetIntData(TreeNode* bt, int parent, int dir);

void MakeLeftSubTree(TreeNode* main, TreeNode* sub);
void MakeRightSubTree(TreeNode* main, TreeNode* sub);

void RemoveTreeNode(TreeNode* remove);
void CountLeafNode(TreeNode* bt,int& count);

#endif // !__BINARYTREE_H__
