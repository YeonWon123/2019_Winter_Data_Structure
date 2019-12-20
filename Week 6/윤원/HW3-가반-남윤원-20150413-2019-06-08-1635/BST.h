#pragma once
#include "BinaryTree.h"
using namespace std;


#ifndef BST_H
#define BST_H
template < class btElementType >
class BST : public BinaryTree < btElementType > {
public:
	BST();
	virtual void insert(const btElementType & d);
	// Precondition: if d is a left child, then d must be < parent->getData();
	//    if d is a right child, then d must be > parent->getData();
	// Postconditions: T->retrieve(k)->getData() == d

	virtual BinaryTree < btElementType > * retrieve(const btElementType & d);
	// Precondition: none
	// Postcondition: none
	// Returns: if T contains a node matching d, then
	// T->retrieve(d)->getData() == d; otherwise, T->isEmpty()

	virtual void deletes(BST * node, const btElementType & d, BST * root);
};

template < class btElementType >
void
BST < btElementType >
::insert(const btElementType & d)
{
	if (this->nullTree) {
		this->nullTree = false;
		this->leftTree = new BST;
		this->rightTree = new BST;
		this->treeData = d;
	}
	else if (d == this->treeData)
		this->treeData = d;
	else if (d < this->treeData)
		this->leftTree->insert(d);
	else
		this->rightTree->insert(d);
}

template < class btElementType >
BinaryTree < btElementType > *
BST < btElementType >
::retrieve(const btElementType & d)
{
	if (this->nullTree || d == this->treeData)
		return this;
	else if (d < this->treeData)
		return ((BST <btElementType> *)this->leftTree)->retrieve(d);
	else
		return ((BST <btElementType> *)this->rightTree)->retrieve(d);
}

template<class btElementType>
void
BST < btElementType >
::deletes(BST * node, const btElementType & d, BST * parent_node)
{
	if (node->isEmpty())
		return;

	// 일단 탐색을 한다.
	if (d == node->treeData) {
		// 이 경우는 자신의 노드를 지우자.
		// 자식이 없을 경우
		if (node->leftTree->isEmpty() && node->rightTree->isEmpty()) {
			delete node;
			return;
		}
		// 자식이 하나만 있는 경우 - 왼쪽에 있을 때 (즉 오른쪽 자식이 NULL)
		else if (node->rightTree->isEmpty()) {
			if (node->getData().getArr_time() < parent_node->getData().getArr_time())
				parent_node->leftTree = node->leftTree;
			else 
				parent_node->rightTree = node->leftTree;
			delete node;
			return;
		}
		// 자식이 하나만 있는 경우 - 오른쪽에 있을 때 (즉 왼쪽 자식이 NULL)
		else if (node->leftTree->isEmpty()) {
			if (node->getData().getArr_time() < parent_node->getData().getArr_time())
				parent_node->leftTree = node->rightTree;
			else
				parent_node->rightTree = node->rightTree;
			delete node;
			return;
		}
		// 자식이 양쪽 모두 있는 경우
		// 오른쪽 자식 중 가장 작은 값을 올림(할당)
		// 그리고 그 오른쪽 자식 중 가장 작은 값을 삭제, 단 올린 부분부터 탐색하면 됨
		BST * temp = (BST <btElementType> *)node->rightTree;
		while (!(temp->leftTree->isEmpty())) {
			temp = (BST <btElementType> *)temp->leftTree;
		}
		//cout << "찾았다!" << "\n";
		node->treeData = temp->treeData;
		deletes((BST<btElementType> *)node->rightTree, temp->treeData, (BST <btElementType> *)node);
	}
	else if (d < node->treeData) {
		// 왼쪽 노드 탐색
		deletes((BST <btElementType> *)node->leftTree, d, (BST <btElementType> *)node);
	}
	else {
		// 오른쪽 노드 탐색
		deletes((BST <btElementType> *)node->rightTree, d, (BST <btElementType> *)node);
	}

	return;
}

template < class btElementType >
BST < btElementType >
::BST() : BinaryTree < btElementType >()
{
}

#endif