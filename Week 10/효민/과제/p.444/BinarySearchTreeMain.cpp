#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() {
	BTreeNode* bstRoot;
	BTreeNode* sNode;		//search node

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);

	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL) {
		cout << "탐색 실패\n";
	}
	else {
		cout << "탐색에 성공한 키의 값 : " << BSTGetNodeData(sNode) << '\n';
	}

	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL) {
		cout << "탐색 실패\n";
	}
	else {
		cout << "탐색에 성공한 키의 값 : " << BSTGetNodeData(sNode) << '\n';
	}


	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL) {
		cout << "탐색 실패\n";
	}
	else {
		cout << "탐색에 성공한 키의 값 : " << BSTGetNodeData(sNode) << '\n';
	}

	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL) {
		cout << "탐색 실패\n";
	}
	else {
		cout << "탐색에 성공한 키의 값 : " << BSTGetNodeData(sNode) << '\n';
	}

	return 0;
}