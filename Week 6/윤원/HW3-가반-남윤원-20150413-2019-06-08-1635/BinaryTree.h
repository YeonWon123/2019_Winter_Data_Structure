#pragma once
#define _CRT_SECURE_NO_WARNINGS
// cx11-1.h
// Code Example 11-1: Interface File: Binary Tree

#ifndef BINARYTREE
#define BINARYTREE

#include <iostream>
#include <cstdio>
#include <assert.h>
using namespace std;

template < class btElementType >
class BinaryTree {
public:
	BinaryTree();
	bool isEmpty() const;
	// Precondition: None.
	// Postcondition: None.
	// Returns: true if and only if T is an empty tree
	btElementType getData() const; // getData is an accessor
	  // Precondition: !this->isEmpty()
	  // Postcondition: None
	  // Returns: The data associated with the root of the tree
	virtual void insert(const btElementType & d);
	// Precondition: none
	// Postconditions: this->getData() == d; !this->isEmpty()
	virtual void deletes(const btElementType & d);
	// Precondition: none
	// Postconditions: this->getData() == d; !this->isEmpty()
	BinaryTree * left();
	// Precondition: !this->isEmpty()
	// Postcondition: None
	// Returns: (a pointer to) the left child of T
	BinaryTree * right();
	// Precondition: !this->isEmpty()
	// Postcondition: None
	// Returns: (a pointer to) the right child of T
	void makeLeft(BinaryTree * T1);
	// Precondition: !this->isEmpty(); this->left()->isEmpty()
	// Postcondition: this->left() == T1
	void makeRight(BinaryTree * T1);
	// Precondition: !this->isEmpty(); this->right()->isEmpty()
	// Postcondition: this->right() == T1
	void printTree(BinaryTree * Node, int start_y, int start_x, int level, char print_area[28][140]);
	void print_node(BinaryTree * Node, int start_y, int start_x, char print_area[28][140]);

protected: // 멤버 변수들을 상속해서 사용하고자 하면, protected로 변경해야 함
	bool nullTree;
	btElementType treeData;
	BinaryTree * leftTree;
	BinaryTree * rightTree;
};

// cx11-2.cpp
// Code Example 11-2: Implementation File: Binary Tree

template < class btElementType >
BinaryTree < btElementType > ::BinaryTree()
{
	nullTree = true;
	leftTree = 0;
	rightTree = 0;
}

template < class btElementType >
bool
BinaryTree < btElementType > ::isEmpty() const
{
	return nullTree;
}

template < class btElementType >
btElementType
BinaryTree < btElementType > ::getData() const
{
	assert(!isEmpty());
	return treeData;
}


template < class btElementType >
void
BinaryTree < btElementType >
::insert(const btElementType & d)
{
	treeData = d;
	if (nullTree) {
		nullTree = false;
		leftTree = new BinaryTree;
		rightTree = new BinaryTree;
	}
}

template < class btElementType >
void
BinaryTree < btElementType >
::deletes(const btElementType & d)
{
}

template < class btElementType >
BinaryTree < btElementType > *
BinaryTree < btElementType > ::left()
{
	assert(!isEmpty());
	return leftTree;
}

template < class btElementType >
BinaryTree < btElementType > *
BinaryTree < btElementType > ::right()
{
	assert(!isEmpty());
	return rightTree;
}



template < class btElementType >
void
BinaryTree < btElementType >
::makeLeft(BinaryTree * T1)
{
	assert(!isEmpty());
	assert(left()->isEmpty());
	delete left();
	leftTree = T1;
}

template < class btElementType >
void
BinaryTree < btElementType >
::makeRight(BinaryTree * T1)
{
	assert(!isEmpty());
	assert(right()->isEmpty());
	delete right();
	rightTree = T1;
}

template<class btElementType>
void
BinaryTree<btElementType>::printTree(BinaryTree * Node, int start_y, int start_x, int level, char print_area[28][140])
{
	int y = start_y - 1;
	int x = start_x - 1;

	if (Node == NULL) {
		cout << "NULL\n";
		return;
	}
	if (Node->isEmpty()) {
	//	cout << "비어 있음!\n";
		return;
	}
	   
	// 각 노드에 맞게 print
	print_node(Node, y, x, print_area);

	// 좌우로 퍼뜨림
	printTree(Node->left(), start_y + 7, start_x - (36 / level), level * 2, print_area);
	printTree(Node->right(), start_y + 7, start_x + (36 / level), level * 2, print_area);
}

template<class btElementType>
void
BinaryTree<btElementType>::print_node(BinaryTree * Node, int start_y, int start_x, char print_area[28][140]) {

	//cout << "start_y : " << start_y << ", start_x : " << start_x << endl;

	// ********* //
	int i;
	for (i = start_x; i < start_x + 9; i++) {
		print_area[start_y][i] = '*';
	}

	//printf("1구역 완료\n");

	// *   8   * // 
	print_area[start_y + 1][start_x] = '*';
	print_area[start_y + 1][start_x+8] = '*';
	char index[3];
	sprintf(index, "%d", Node->getData().getTurn());
	//cout << "구한 값 : " << index << endl;

	if (Node->getData().getTurn() > 9) {
		print_area[start_y + 1][start_x + 3] = index[0];
		print_area[start_y + 1][start_x + 4] = index[1];
	}
	else {
		print_area[start_y + 1][start_x + 4] = index[0];
	}

	//cout << "배열에 넣은 값 : " << print_area[start_y + 1][start_x + 4] << endl;
	//printf("2구역 완료\n");

	// *       * // 
	print_area[start_y + 2][start_x] = '*';
	print_area[start_y + 2][start_x + 8] = '*';
	//printf("3구역 완료: 프린트해보면 %s\n", print_area[start_y + 2]);


	// Kang      //
	print_area[start_y + 3][start_x] = '*';
	print_area[start_y + 3][start_x + 8] = '*';
	string name = Node->getData().getName();

	for (i = 1; i <= name.length(); i++) {
		print_area[start_y + 3][start_x + i] = name[i - 1];
	}
	for (; i < 8; i++) {
		print_area[start_y + 3][start_x + i] = ' ';
	}
	//printf("4구역 완료: 프린트해보면 %s\n", print_area[start_y + 3]);


	// 3people   //
	print_area[start_y + 4][start_x] = '*';
	char people[8];
	sprintf(people, "%dpeople", Node->getData().getGroup_num());
	for (int i = 1; i <= 7; i++) {
		print_area[start_y + 4][start_x + i] = people[i - 1];
	}
	print_area[start_y + 4][start_x + 8] = '*';
	//printf("5구역 완료: 프린트해보면 %s\n", print_area[start_y + 4]);


	// 15:26PM   //
	print_area[start_y + 5][start_x] = '*';
	char times[8];
	if (Node->getData().getAM_PM() == "AM")
		sprintf(times, "%d:%dAM", Node->getData().getHour(), Node->getData().getMinute());
	else
		sprintf(times, "%d:%dPM", Node->getData().getHour(), Node->getData().getMinute());

	for (int i = 1; i <= 7; i++) {
		print_area[start_y + 5][start_x + i] = times[i - 1];
	}
	print_area[start_y + 5][start_x + 8] = '*';
	//printf("6구역 완료: 프린트해보면 %s\n", print_area[start_y + 5]);


	// ********* //
	for (i = start_x; i < start_x + 9; i++) {
		print_area[start_y + 6][i] = '*';
	}
	//printf("7구역 완료: 프린트해보면 %s\n", print_area[start_y + 6]);

}

#endif


