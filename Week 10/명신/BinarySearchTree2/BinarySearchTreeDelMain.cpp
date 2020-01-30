#include <iostream>
#include "BinarySearchTree2.h"
using namespace std;

int main() {

	BTreeNode* bstRoot;
	BTreeNode* sNode;

	BSTMakeAndInit(&bstRoot);
	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 4);
	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 7);

	BSTShowAll(bstRoot);
	cout << '\n';

	sNode = BSTRemove(&bstRoot, 3);
	delete sNode;
	BSTShowAll(bstRoot);
	cout << '\n';

	sNode = BSTRemove(&bstRoot, 8);
	delete sNode;
	BSTShowAll(bstRoot);
	cout << '\n';

	sNode = BSTRemove(&bstRoot, 1);
	delete sNode;
	BSTShowAll(bstRoot);
	cout << '\n';

	sNode = BSTRemove(&bstRoot, 6);
	delete sNode;
	BSTShowAll(bstRoot);
	cout << '\n';

	return 0;
}