#pragma once
#ifndef RBT_H
#define RBT_H

#include "BST.h"
using namespace std;

template < class btElementType >
class RBT : public BST <btElementType> {

protected:
	enum TreeColor { BlackTree, RedTree };
	TreeColor color;
	RBT * parentTree;
	RBT * root_node; // ��Ʈ ��带 ������ �ָ� �ɵ�

public:
	RBT();
	RBT * getparent(RBT * n);
	RBT * getgrandparent(RBT * n);
	RBT * getroot(RBT * n);
	RBT * sibling(RBT * n);
	RBT * uncle(RBT * n);
	void rotate_left(RBT * n);
	void rotate_right(RBT * n);
	void setcolor(int n);

	void insert_repair_tree(RBT * n);
	void insert_case_0(RBT * n);
	void insert_case_1(RBT * n);
	void insert_case_2(RBT * n);
	void insert_case_3(RBT * n);
	
	virtual void insert(RBT * node, const btElementType & d, RBT * parent_node);

	void printTree(RBT * Node, int start_y, int start_x, int level, char print_area[32][140]);
	void print_node(RBT * Node, int start_y, int start_x, char print_area[32][140]);

	void replace_node(RBT * n, RBT * child);
	virtual void deletes(RBT * node, const btElementType & d, RBT * parent_node);

	// precondition : n has at most one non-leaf child.
	void delete_one_child(RBT * node);
	void delete_case1(RBT * n);
	void delete_case2(RBT * n);
	void delete_case3(RBT * n);
	void delete_case4(RBT * n);
	void delete_case5(RBT * n);
	void delete_case6(RBT * n);
};


template < class btElementType >
RBT < btElementType >
::RBT() : BST < btElementType >()
{
	color = BlackTree;
	parentTree = NULL;
}

template<class btElementType>
RBT < btElementType > * 
RBT < btElementType >
::getparent(RBT * n)
{
	if (n->parentTree == NULL)
		return NULL;
	return n->parentTree;	// root node�� ��� null�̴�.
}

template<class btElementType>
RBT < btElementType > *
RBT < btElementType >
::getgrandparent(RBT * n)
{
	RBT * p = getparent(n);
	if (p == NULL)
		return NULL;		// parent node�� ���ٴ� �� grandparent ���� ���ٴ� ��
	return getparent(p);	// parent node�� root node�� ��� null�̴�.
}

template<class btElementType>
RBT < btElementType > *
RBT < btElementType >
::getroot(RBT * n)
{
	RBT * temp = n;
	while (temp->getparent(temp) != NULL)
		temp = temp->getparent(temp);

	return temp;
}

template<class btElementType>
RBT < btElementType > *
RBT < btElementType >
::sibling(RBT * n)
{
	RBT * p = getparent(n);
	if (p == NULL)
		return NULL; // parent node�� ���ٴ� �� sibling ���� ���ٴ� ��
	if (n == p->leftTree)
		return (RBT <btElementType> *)p->rightTree;
	else
		return (RBT <btElementType> *)p->leftTree;
}

template<class btElementType>
RBT < btElementType > *
RBT<btElementType>
::uncle(RBT * n)
{
	RBT * p = getparent(n);
	RBT * g = getgrandparent(n);
	if (g == NULL)
		return NULL; // grandparent node�� ���ٴ� �� uncle�� ���ٴ� ��
	return sibling(p);
}

template<class btElementType>
void
RBT<btElementType>
::rotate_left(RBT * n)
{
	RBT * nnew = (RBT <btElementType> *)n->rightTree;
	RBT * p = getparent(n);
	assert(!(nnew->isEmpty()));
	n->rightTree = nnew->leftTree;
	nnew->leftTree = n;
	n->parentTree = nnew;
	// handle other child/parent pointers
	// if (n->rightTree != NULL) {
	if (!(n->rightTree->isEmpty())) {
		((RBT <btElementType> *)n->rightTree)->parentTree = n;
	}
	if (p != NULL) { // n�� root node�� ���
		if (n == p->leftTree)
			p->leftTree = nnew;
		else if (n == p->rightTree)
			p->rightTree = nnew;
	}
	nnew->parentTree = p;
}

template<class btElementType>
void
RBT<btElementType>
::rotate_right(RBT * n)
{
	RBT * nnew = (RBT <btElementType> *)n->leftTree;
	RBT * p = getparent(n);
	assert(!(nnew->isEmpty()));
	n->leftTree = nnew->rightTree;
	nnew->rightTree = n;
	n->parentTree = nnew;
	// handle other child/parent pointers
	// if (n->rightTree != NULL) {
	if (!(n->leftTree->isEmpty())) {
		((RBT <btElementType> *)n->leftTree)->parentTree = n;
	}
	if (p != NULL) { // n�� root node�� ���
		if (n == p->leftTree)
			p->leftTree = nnew;
		else if (n == p->rightTree)
			p->rightTree = nnew;
	}
	nnew->parentTree = p;
}

template<class btElementType>
void
RBT<btElementType>
::setcolor(int n)
{
	if (n == 0)
		color = BlackTree;
	else
		color = RedTree;
}

template<class btElementType>
void
RBT<btElementType>
::insert_repair_tree(RBT * n)
{
	//cout << "repair tree ��" << n->color << endl;
	if (getparent(n) == NULL) {
	//	cout << "case�� 0" << endl;
		insert_case_0(n);
	}
	else if (getparent(n)->color == BlackTree) {
	//	cout << "case�� 1" << endl;
		insert_case_1(n);
	}
	else if (uncle(n) != NULL && uncle(n)->color == RedTree) {
	//	cout << "case�� 2" << endl;
		insert_case_2(n);
	}
	else {
	//	cout << "case�� 3" << endl;
		insert_case_3(n);
	}
	//cout << "repair tree ����� " << n->color << endl;
	//printTree(n, 0);
}

// case 0 : The current node N is at the root of the tree
template<class btElementType>
void
RBT<btElementType>
::insert_case_0(RBT * n)
{
	if (getparent(n) == NULL)
		n->color = BlackTree;
}

// case 1 : The current node's parent P is black
template<class btElementType>
void
RBT<btElementType>
::insert_case_1(RBT * n)
{
	return;
}

// case 2 : both the parent P and the uncle U are red
template<class btElementType>
void
RBT<btElementType>
::insert_case_2(RBT * n)
{
	getparent(n)->color = BlackTree;
	uncle(n)->color = BlackTree;
	getgrandparent(n)->color = RedTree;
	insert_repair_tree(getgrandparent(n));
}


// case 3 : The parent P is red but the uncle U is black
template<class btElementType>
void
RBT<btElementType>
::insert_case_3(RBT * n)
{
	RBT * p = getparent(n);
	RBT * g = getgrandparent(n);

	if (n == p->rightTree && p == g->leftTree) {
		rotate_left(p);
		n = (RBT <btElementType> *)n->leftTree;
	}
	else if (n == p->leftTree && p == g->rightTree) {
		rotate_right(p);
		n = (RBT <btElementType> *)n->rightTree;
	}

	// The current node N is now certain 
	// to be on the "outside" of the subtree under G
	// (left of left child or right of right child). 
	p = getparent(n);
	g = getgrandparent(n);

	if (n == p->leftTree)
		rotate_right(g);
	else
		rotate_left(g);
	p->color = BlackTree;
	g->color = RedTree;
}

// ���� : (d, {}, null);
// parent tree �������� ��!
template < class btElementType >
void
RBT < btElementType >
::insert(RBT * node, const btElementType & d, RBT * parent_node)
{
	// 1. BST insert
	if (this->nullTree) {
		this->nullTree = false;
		this->leftTree = new RBT;
		this->rightTree = new RBT;
		this->treeData = d;
		this->parentTree = parent_node;

		// 2. insert�� node�� color�� RED�� ����
		this->color = RedTree;

		// 3. x�� parent x�� �� �� �������� Ȯ��
		//   - �浹�� ������ ��
		//   - �浹�� ������ recoloring (��������� ����)
		//   - recoloring�� �ȵǸ�, restructing ���� �ִ� 2������
		insert_repair_tree(node);
	//	cout << "1��" << this->color << endl;
	}
	else if (d == this->treeData) {
		this->treeData = d;

		// 2. insert�� node�� color�� RED�� ����
		this->color = RedTree;

		// 3. x�� parent x�� �� �� �������� Ȯ��
		//   - �浹�� ������ ��
		//   - �浹�� ������ recoloring (��������� ����)
		//   - recoloring�� �ȵǸ�, restructing ���� �ִ� 2������
		insert_repair_tree(node);
	//	cout << "2��" << this->color << endl;
	}
	else if (d < this->treeData)
		((RBT <btElementType> *)this->leftTree)->insert((RBT <btElementType> *)node->leftTree, d, (RBT <btElementType> *)node);
	else
		((RBT <btElementType> *)this->rightTree)->insert((RBT <btElementType> *)node->rightTree, d, (RBT <btElementType> *)node);

	return;
}

template<class btElementType>
void
RBT <btElementType>
::printTree(RBT * Node, int start_y, int start_x, int level, char print_area[32][140])
{
	//cout << "y : " << start_y << ", x : " << start_x << ", level : " << level << endl;

	int y = start_y - 1;
	int x = start_x - 1;

	if (Node == NULL) {
		cout << "NULL\n";
		return;
	}
	if (Node->isEmpty()) {
		//	cout << "��� ����!\n";
		return;
	}
	//cout << "�����ʹ�" << Node->getData().getName() << ", " << Node->nullTree << endl;

	// �� ��忡 �°� print
	print_node(Node, y, x, print_area);

	// �¿�� �۶߸�
	printTree((RBT < btElementType > *)Node->left(), start_y + 8, start_x - (36 / level), level * 2, print_area);
	printTree((RBT < btElementType > *)Node->right(), start_y + 8, start_x + (36 / level), level * 2, print_area);
}


template<class btElementType>
void
RBT < btElementType >
::print_node(RBT * Node, int start_y, int start_x, char print_area[32][140])
{
	// ********* //
	int i;
	for (i = start_x; i < start_x + 9; i++) {
		print_area[start_y][i] = '*';
	}
	
	// *   8   * // 
	print_area[start_y + 1][start_x] = '*';
	print_area[start_y + 1][start_x + 8] = '*';
	char index[3];
	sprintf(index, "%d", Node->getData().getTurn());

	if (Node->getData().getTurn() > 9) {
		print_area[start_y + 1][start_x + 3] = index[0];
		print_area[start_y + 1][start_x + 4] = index[1];
	}
	else {
		print_area[start_y + 1][start_x + 4] = index[0];
	}

	// *       * // 
	print_area[start_y + 2][start_x] = '*';
	print_area[start_y + 2][start_x + 8] = '*';

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

	// 3people   //
	print_area[start_y + 4][start_x] = '*';
	char people[8];
	sprintf(people, "%dpeople", Node->getData().getGroup_num());
	for (int i = 1; i <= 7; i++) {
		print_area[start_y + 4][start_x + i] = people[i - 1];
	}
	print_area[start_y + 4][start_x + 8] = '*';

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

	// BLACK     // �Ǵ� // RED      //
	print_area[start_y + 6][start_x] = '*';
	print_area[start_y + 6][start_x + 8] = '*';
	if (Node->color == RedTree) {
		print_area[start_y + 6][start_x + 1] = 'R';
		print_area[start_y + 6][start_x + 2] = 'E';
		print_area[start_y + 6][start_x + 3] = 'D';
	}
	else {
		print_area[start_y + 6][start_x + 1] = 'B';
		print_area[start_y + 6][start_x + 2] = 'L';
		print_area[start_y + 6][start_x + 3] = 'A';
		print_area[start_y + 6][start_x + 4] = 'C';
		print_area[start_y + 6][start_x + 5] = 'K';
	}

	// ********* //
	for (i = start_x; i < start_x + 9; i++) {
		print_area[start_y + 7][i] = '*';
	}
}

template<class btElementType>
void 
RBT<btElementType>
::deletes(RBT * node, const btElementType & d, RBT * parent_node)
{
	if (node->isEmpty())
		return;

	// �ϴ� Ž���� �Ѵ�.
	if (d == node->treeData) {
		// �� ���� �ڽ��� ��带 ������.
		// �ڽ��� ���� ���
		if (node->leftTree->isEmpty() && node->rightTree->isEmpty()) {
			delete_one_child(node);
			return;
		}
		// �ڽ��� �ϳ��� �ִ� ��� - ���ʿ� ���� �� (�� ������ �ڽ��� NULL)
		else if (node->rightTree->isEmpty()) {
			if (node->getData().getArr_time() < parent_node->getData().getArr_time())
				parent_node->leftTree = node->leftTree;
			else
				parent_node->rightTree = node->leftTree;
			delete_one_child(node);
			return;
		}
		// �ڽ��� �ϳ��� �ִ� ��� - �����ʿ� ���� �� (�� ���� �ڽ��� NULL)
		else if (node->leftTree->isEmpty()) {
			if (node->getData().getArr_time() < parent_node->getData().getArr_time())
				parent_node->leftTree = node->rightTree;
			else
				parent_node->rightTree = node->rightTree;
			delete_one_child(node);
			return;
		}
		// �ڽ��� ���� ��� �ִ� ���
		// ������ �ڽ� �� ���� ���� ���� �ø�(�Ҵ�)
		// �׸��� �� ������ �ڽ� �� ���� ���� ���� ����, �� �ø� �κк��� Ž���ϸ� ��
		RBT * temp = (RBT <btElementType> *)node->rightTree;
		while (!(temp->leftTree->isEmpty())) {
			temp = (RBT <btElementType> *)temp->leftTree;
		}
		//cout << "ã�Ҵ�!" << "\n";
		node->treeData = temp->treeData;
		deletes((RBT<btElementType> *)node->rightTree, temp->treeData, (RBT <btElementType> *)node);
	}
	else if (d < node->treeData) {
		// ���� ��� Ž��
		deletes((RBT <btElementType> *)node->leftTree, d, (RBT <btElementType> *)node);
	}
	else {
		// ������ ��� Ž��
		deletes((RBT <btElementType> *)node->rightTree, d, (RBT <btElementType> *)node);
	}

	return;
}

template<class btElementType>
void
RBT<btElementType>
::replace_node(RBT * n, RBT * child)
{
	child->parentTree = n->parentTree;
	if (n == ((RBT <btElementType> *)n->parentTree)->leftTree)
		((RBT <btElementType> *)n->parentTree)->leftTree = child;
	else
		((RBT <btElementType> *)n->parentTree)->rightTree = child;
}

// precondition : n has at most one non-leaf child.
template<class btElementType>
void 
RBT<btElementType>
::delete_one_child(RBT * node)
{
	RBT * child = ((RBT <btElementType> *)node->rightTree->isEmpty()) ? (RBT <btElementType> *)node->leftTree : (RBT <btElementType> *)node->rightTree;
	replace_node(node, child);
		
	if (node->color == BlackTree) {
		if (child->color == RedTree)
			child->color = BlackTree;
		else
			delete_case1(child);
	}
	free(node);
}

template<class btElementType>
void 
RBT<btElementType>
::delete_case1(RBT * n)
{
	if (n->parentTree != NULL)
		delete_case2(n);
}

template<class btElementType>
void
RBT<btElementType>
::delete_case2(RBT * n)
{
	RBT * s = sibling(n);
	
	if (s->color == RedTree) {
		n->parentTree->color = RedTree;
		s->color = BlackTree;
		if (n == n->parentTree->leftTree)
			rotate_left(n->parentTree);
		else
			rotate_right(n->parentTree);
	}
	delete_case3(n);
}

template<class btElementType>
void
RBT<btElementType>
::delete_case3(RBT * n)
{
	RBT *s = sibling(n);

	if ((((RBT <btElementType> *)n->parentTree)->color == BlackTree) && (((RBT <btElementType> *)s)->color == BlackTree)
		&& (((RBT <btElementType> *)s->leftTree)->color == BlackTree) && (((RBT <btElementType> *)s->rightTree)->color == BlackTree)) {
		s->color = RedTree;
		delete_case1(n->parentTree);		
	}
	else {
		delete_case4(n);
	}
}

template<class btElementType>
void 
RBT<btElementType>
::delete_case4(RBT * n)
{
	RBT * s = sibling(n);

	if ((((RBT <btElementType> *)n->parentTree)->color == RedTree) && (s->color == BlackTree)
		&& (((RBT <btElementType> *)s->leftTree)->color == BlackTree) && (((RBT <btElementType> *)s->rightTree)->color == BlackTree)) {
		s->color = RedTree;
		n->parentTree->color = BlackTree;
	}
	else
		delete_case5(n);
}

template<class btElementType>
void
RBT<btElementType>
::delete_case5(RBT * n)
{
	RBT * s = sibling(n);

	if (s->color == BlackTree) {
		if ((n == ((RBT <btElementType> *)n->parentTree)->leftTree) && (((RBT <btElementType> *)s->rightTree)->color == BlackTree)
			&& (((RBT <btElementType> *)s->leftTree)->color == RedTree)) {
			s->color = RedTree;
			((RBT <btElementType> *)s->leftTree)->color = BlackTree;
			rotate_right(s);
		}
		else if ((n == n->parentTree->rightTree) && (((RBT <btElementType> *)s->leftTree)->color == BlackTree)
			&& (((RBT <btElementType> *)s->rightTree)->color == RedTree)) {
			s->color = RedTree;
			((RBT <btElementType> *)s->rightTree)->color = BlackTree;
			rotate_left(s);
		}
	}
	delete_case6(n);
}

template<class btElementType>
void 
RBT<btElementType>
::delete_case6(RBT * n)
{
	RBT * s = sibling(n);

	s->color = n->parentTree->color;
	n->parentTree->color = BlackTree;

	if (n == n->parentTree->leftTree) {
		((RBT <btElementType> *)s->rightTree)->color = BlackTree;
		rotate_left(n->parentTree);
	}
	else {
		((RBT <btElementType> *)s->leftTree)->color = BlackTree;
		rotate_right(n->parentTree);
	}
}

#endif