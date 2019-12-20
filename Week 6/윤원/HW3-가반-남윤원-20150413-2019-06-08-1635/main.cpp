#include "BST.h"
#include "BinaryTree.h"
#include "RBT.h"
#include "Customer.h"
#include <iostream>
using namespace std;

char print_BST_area[28][140];
char print_RBT_area[32][140];

void print_BST_area_default() {
	memset(print_BST_area, ' ', sizeof(print_BST_area));
	for (int i = 0; i < 28; i++) {
		print_BST_area[i][138] = '\n';
		print_BST_area[i][139] = '\0';
	}
}

void print_BST_tree() {
	for (int i = 0; i < 28; i++) {
		for (int j = 0; j < 139; j++) {
			printf("%c", print_BST_area[i][j]);
		}
	}
}

void print_RBT_area_default() {
	memset(print_RBT_area, ' ', sizeof(print_RBT_area));
	for (int i = 0; i < 32; i++) {
		print_RBT_area[i][138] = '\n';
		print_RBT_area[i][139] = '\0';
	}
}

void print_RBT_tree() {
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 136; j++) {
			if (j == 135) {
				printf("\n");
				break;
			}
			printf("%c", print_RBT_area[i][j]);
		}
	}
}

int main(void)
{
	print_BST_area_default();
	print_RBT_area_default();

	cout << endl << "전자정보공학부 it융합전공 20150413 남윤원 - HW3";
	cout << endl << endl << "1번 문제 : BST insert를 이용하여 BST 구성" << endl << endl;

	typedef BST < Customer > CustomerBST;
	typedef CustomerBST * CustomerBSTPtr;

	CustomerBSTPtr b(new CustomerBST);
	b->insert({ "Sin", 2, 6, 12, 17, "PM" });
	b->insert({ "Kang", 3, 8, 15, 26, "PM" });
	b->insert({ "Lee", 3, 1, 11, 15, "AM" });
	b->insert({ "Park", 1, 2, 11, 30, "AM" });
	b->insert({ "Jin", 3, 10, 16, 02, "PM" });
	b->insert({ "Kim", 2, 4, 12, 00, "PM" });
	b->insert({ "Nam", 4, 9, 15, 43, "PM" });
	b->insert({ "Song", 2, 7, 12, 36, "PM" });

	b->printTree(b, 1, 64, 1, print_BST_area);
	print_BST_tree();
	print_BST_area_default();

	cout << endl << endl << "2번 문제 : BST delete를 이용하여 노드 삭제하기" << endl << endl;
	cout << " 2-1 : (\"1번 문제\"의 결과값을 가지고 시도함) 자식이 없는 노드를 삭제하기" << endl << endl;
	cout << "< 삭제할 노드 : 4번 노드, Kim >" << endl << endl;
	b->deletes(b, { "Kim", 2, 4, 12, 00, "PM" }, b);
	b->printTree(b, 1, 64, 1, print_BST_area);
	print_BST_tree();
	print_BST_area_default();

	cout << endl << endl << " 2-2 : (2-1의 결과값을 가지고 시도함) 자식이 한 개 있는 노드를 삭제하기" << endl << endl;
	cout << "< 삭제할 노드 : 1번 노드, Lee >" << endl << endl;
	b->deletes(b, { "Lee", 3, 1, 11, 15, "AM" }, b);
	b->printTree(b, 1, 64, 1, print_BST_area);
	print_BST_tree();
	print_BST_area_default();

	cout << endl << endl << " 2-3 : (2-2의 결과값을 가지고 시도함) 자식이 두 개 있는 노드를 삭제하기" << endl << endl;
	cout << "< 삭제할 노드 : 8번 노드, Kang >" << endl << endl;
	b->deletes(b, { "Kang", 3, 8, 15, 26, "PM" }, b);
	b->printTree(b, 1, 64, 1, print_BST_area);
	print_BST_tree();
	print_BST_area_default();

	cout << endl << endl << "3번 문제 : RBT를 구현하고, insert 함수를 사용하여 노드 출력하기" << endl << endl;
	cout << " 3-1 : parent가 빨간색일 때 uncle이 빨간색인 경우" << endl << endl;
	cout << "RBT insert 수행 전 값" << endl << endl;

	typedef RBT < Customer > CustomerRBT;
	typedef CustomerRBT * CustomerRBTPtr;

	CustomerRBTPtr d(new CustomerRBT);

	// insert하고, d를 root노드로 설정해주고...
	d->insert(d, { "Park", 1, 3, 10, 00, "AM" }, NULL);
	d = d->getroot(d);
	d->insert(d, { "Lee", 2, 7, 11, 30, "AM" }, NULL);
	d = d->getroot(d);
	d->insert(d, { "Nam", 4, 18, 13, 23, "PM" }, NULL);
	d = d->getroot(d);
	d->printTree(d, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();

	cout << "< insert할 노드 : 5번 노드, Ha >" << endl << endl;
	cout << "5번 노드 insert 시 parent(3번 노드) : 빨간색, uncle(18번 노드) : 빨간색" << endl << endl;
	cout << "insert 이후 RBT 출력" << endl << endl;
	d->insert(d, { "Ha", 2, 5, 11, 00, "AM" }, NULL);
	d = d->getroot(d);
	d->printTree(d, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();



	cout << endl << endl << " 3-2 (1) : parent가 빨간색일 때 uncle이 검은색인 경우 - (1) : 굽은 경우" << endl << endl;
	cout << "RBT insert 수행 전 값" << endl << endl;

	CustomerRBTPtr e(new CustomerRBT);

	// insert하고, e를 root노드로 설정해주고...
	e->insert(e, { "Park", 1, 3, 10, 00, "AM" }, NULL);
	e = e->getroot(e);
	e->insert(e, { "Lee", 2, 7, 11, 30, "AM" }, NULL);
	e = e->getroot(e);
	e->insert(e, { "Nam", 4, 18, 13, 23, "PM" }, NULL);
	e = e->getroot(e);
	e->insert(e, { "Jin", 3, 10, 12, 02, "PM" }, NULL);
	e = e->getroot(e);
	e->insert(e, { "Sin", 2, 22, 13, 30, "PM" }, NULL);
	e = e->getroot(e);
	e->insert(e, { "Kang", 3, 11, 12, 10, "PM" }, NULL);
	e = e->getroot(e);
	e->insert(e, { "Kim", 2, 8, 11, 43, "AM" }, NULL);
	e = e->getroot(e);
	e->insert(e, { "Song", 2, 26, 16, 21, "PM" }, NULL);
	e = e->getroot(e);
	e->printTree(e, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();

	cout << "< insert할 노드 : 15번 노드, Ha >" << endl << endl;
	cout << "15 노드를 insert시 그 순간, 3-1에서 시도한 parent가 빨간색일 때 uncle이 빨간색인 경우에 해당함" << endl << endl;
	cout << "(15 노드 insert시 parent(11번 노드) 빨간색, uncle(8번 노드) 빨간색" << endl << endl;
	cout << "그 이후, 10 노드가 빨간색으로 바뀌면서, 3(검)-7(uncle:검)-18(parent:빨)-10(me:빨) 노드간 3-2 (1) 굽은 조건이 성립함" << endl << endl;
	cout << "insert 이후 RBT 출력" << endl << endl;
	e->insert(e, { "Ha", 2, 15, 13, 00, "PM" }, NULL);
	e = e->getroot(e);
	e->printTree(e, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();


	cout << " 3-2 (2) : parent가 빨간색일 때 uncle이 검은색인 경우 - (2) : 직선인 경우" << endl << endl;
	cout << "RBT insert 수행 전 값" << endl << endl;

	CustomerRBTPtr f(new CustomerRBT);

	// insert하고, e를 root노드로 설정해주고...
	f->insert(f, { "Park", 1, 3, 10, 00, "AM" }, NULL);
	f = f->getroot(f);
	f->insert(f, { "Lee", 2, 7, 11, 30, "AM" }, NULL);
	f = f->getroot(f);
	f->insert(f, { "Nam", 4, 18, 13, 23, "PM" }, NULL);
	f = f->getroot(f);
	f->insert(f, { "Jin", 3, 10, 12, 02, "PM" }, NULL);
	f = f->getroot(f);
	f->insert(f, { "Sin", 2, 22, 14, 25, "PM" }, NULL);
	f = f->getroot(f);
	f->insert(f, { "Kang", 3, 21, 13, 26, "PM" }, NULL);
	f = f->getroot(f);
	f->insert(f, { "Kim", 2, 8, 11, 43, "AM" }, NULL);
	f = f->getroot(f);
	f->insert(f, { "Song", 2, 26, 16, 21, "PM" }, NULL);
	f = f->getroot(f);
	f->printTree(f, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();

	cout << "< insert할 노드 : 25번 노드, Ha >" << endl << endl;
	cout << "25 노드를 insert시 그 순간, 3-1에서 시도한 parent가 빨간색일 때 uncle이 빨간색인 경우에 해당함" << endl << endl;
	cout << "그 이후, 22 노드가 빨간색으로 바뀌면서, 3(검)-7(uncle:검)-18(parent:빨)-22(me: 빨) 노드간 3-2 (2) 직선 조건이 성립함" << endl << endl;
	cout << "insert 이후 RBT 출력" << endl << endl;
	f->insert(f, { "Ha", 2, 25, 16, 15, "PM" }, NULL);
	f = f->getroot(f);
	f->printTree(f, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();

	cout << endl << endl << "4번 문제 : RBT의 delete 함수 구현, double black이 될 수 있는 노드를 지우기" << endl << endl;
	cout << "double black이 될 수 있는 경우는, black인 노드를 지웠을 때 발생한다. 따라서 black인 노드를 지우는 경우를 살펴보자" << endl << endl;
	cout << " 4-1 (1) sibling이 black이고 sibling의 child가 red인 경우 - (1) : 굽은 경우" << endl << endl;
	cout << "RBT delete 수행 전 값" << endl << endl;
	CustomerRBTPtr g(new CustomerRBT);

	// insert하고, g를 root노드로 설정해주고...
	g->insert(g, { "Park", 1, 23, 19, 00, "PM" }, NULL);
	g = g->getroot(g);
	g->insert(g, { "Lee", 2, 21, 18, 30, "PM" }, NULL);
	g = g->getroot(g);
	g->insert(g, { "Nam", 4, 31, 21, 00, "PM" }, NULL);
	g = g->getroot(g);
	g->insert(g, { "Kim", 4, 28, 19, 40, "PM" }, NULL);
	g = g->getroot(g);
	g->insert(g, { "Jin", 1, 29, 20, 00, "PM" }, NULL);
	g = g->getroot(g);
	g->insert(g, { "Seok", 3, 30, 20, 30, "PM" }, NULL);
	g = g->getroot(g);
	g->printTree(g, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();

	cout << "< delete할 노드 : 28번 Kim 노드 >" << endl << endl;
	cout << "이 경우 28번 노드 자리에 leaf node가 들어가면서 double black이 발생하며,\n"
		<< "sibling인 31번 노드는 BLACK이고 sibling의 child인 30번 노드는 RED이므로 굽은 경우이다." << endl << endl;
	g->deletes(g, { "Kim", 4, 28, 19, 40, "PM" }, NULL);
	g = g->getroot(g);
	
	g->printTree(g, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();
		

	cout << endl << endl << " 4-1 (2) sibling이 black이고 sibling의 child가 red인 경우 - (2) : 직선인 경우" << endl << endl;
	cout << "RBT delete 수행 전 값" << endl << endl;
	CustomerRBTPtr h(new CustomerRBT);

	// insert하고, h를 root노드로 설정해주고...
	h->insert(h, { "Park", 1, 23, 19, 00, "PM" }, NULL);
	h = h->getroot(h);
	h->insert(h, { "Lee", 2, 21, 18, 30, "PM" }, NULL);
	h = h->getroot(h);
	h->insert(h, { "Nam", 4, 31, 21, 00, "PM" }, NULL);
	h = h->getroot(h);
	h->insert(h, { "Kim", 4, 28, 19, 40, "PM" }, NULL);
	h = h->getroot(h);
	h->insert(h, { "Jin", 1, 41, 22, 00, "PM" }, NULL);
	h = h->getroot(h);
	h->printTree(h, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();

	cout << "< delete할 노드 : 21번 Lee 노드 >" << endl << endl;
	cout << "이 경우 21번 노드 자리에 leaf node가 들어가면서 double black이 발생하며,\n"
		<< "sibling인 31번 노드는 BLACK이고 sibling의 child인 41번 노드는 RED이므로 직선인 경우이다."
		<< "(28번 노드의 경우 don't care이다.)" << endl << endl;
	h->deletes(h, { "Lee", 2, 21, 18, 30, "PM" }, NULL);
	h = h->getroot(h);

	h->printTree(h, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();

	cout << endl << endl << " 4-2 sibling이 black이고 sibling의 children이 모두 black인 경우" << endl << endl;
	cout << "RBT delete 수행 전 값" << endl << endl;

	CustomerRBTPtr k(new CustomerRBT);

	// insert하고, e를 root노드로 설정해주고...
	k->insert(k, { "Park", 1, 23, 15, 30, "PM" }, NULL);
	k = k->getroot(k);
	k->insert(k, { "Lee", 2, 21, 14, 40, "PM" }, NULL);
	k = k->getroot(k);
	k->insert(k, { "Nam", 4, 31, 16, 20, "PM" }, NULL);
	k = k->getroot(k);
	k->insert(k, { "Jin", 3, 41, 18, 02, "PM" }, NULL);
	k = k->getroot(k);
	k->insert(k, { "Sin", 2, 6, 10, 20, "AM" }, NULL);
	k = k->getroot(k);
	k->insert(k, { "Kang", 3, 3, 10, 00, "AM" }, NULL);
	k = k->getroot(k);
	k->insert(k, { "Kim", 2, 2, 9, 40, "AM" }, NULL);
	k = k->getroot(k);
	k->insert(k, { "Song", 2, 7, 10, 30, "AM" }, NULL);
	k = k->getroot(k);
	k->insert(k, { "Seok", 2, 8, 10, 50, "AM" }, NULL);
	k = k->getroot(k);
	k->insert(k, { "Min", 3, 13, 11, 21, "AM" }, NULL);
	k = k->getroot(k);
	k->insert(k, { "Soo", 2, 14, 11, 40, "AM" }, NULL);
	k = k->getroot(k);
	k->insert(k, { "Jeong", 2, 15, 11, 54, "AM" }, NULL);
	k = k->getroot(k);
	k->deletes(k, { "Seo", 2, 15, 11, 54, "AM" }, NULL);
	k = k->getroot(k);
	k->insert(k, { "Ki", 2, 30, 16, 10, "PM" }, NULL);
	k = k->getroot(k);
	k->insert(k, { "Jo", 2, 28, 15, 50, "PM" }, NULL);
	k = k->getroot(k);
	k->deletes(k, { "Jo", 2, 28, 15, 50, "PM" }, NULL);
	k = k->getroot(k);

	k->printTree(k, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();
	
	cout << "< delete할 노드 : 23번 Park 노드 >" << endl << endl;
	cout << "이 경우 23번 노드 자리에 30번 노드가 들어가면서 double black이 발생하며,\n"
		<< "sibling인 6번 노드는 BLACK이고 sibling의 child인 3번 노드와 7번 노드가 모두 BLACK이다." << endl << endl;
	k->deletes(k, { "Park", 1, 23, 15, 30, "PM" }, NULL);
	k = k->getroot(k);
	k->printTree(k, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();
	
	cout << endl << endl << " 4-3 sibling이 red인 경우" << endl << endl;
	cout << "RBT delete 수행 전 값" << endl << endl;

	CustomerRBTPtr w(new CustomerRBT);

	// insert하고, w를 root노드로 설정해주고...
	w->insert(w, { "Park", 1, 23, 15, 30, "PM" }, NULL);
	w = w->getroot(w);
	w->insert(w, { "Lee", 2, 21, 14, 40, "PM" }, NULL);
	w = w->getroot(w);
	w->insert(w, { "Nam", 4, 31, 16, 20, "PM" }, NULL);
	w = w->getroot(w);
	w->insert(w, { "Jin", 3, 41, 18, 02, "PM" }, NULL);
	w = w->getroot(w);
	w->insert(w, { "Sin", 2, 6, 10, 20, "AM" }, NULL);
	w = w->getroot(w);
	w->insert(w, { "Kang", 3, 3, 10, 00, "AM" }, NULL);
	w = w->getroot(w);
	w->insert(w, { "Song", 2, 33, 16, 30, "PM" }, NULL);
	w = w->getroot(w);
	w->insert(w, { "Seok", 2, 35, 16, 50, "PM" }, NULL);
	w = w->getroot(w);
	w->insert(w, { "Min", 3, 38, 17, 7, "PM" }, NULL);
	w = w->getroot(w);
	w->insert(w, { "Soo", 2, 39, 17, 40, "PM" }, NULL);
	w = w->getroot(w);
	w->insert(w, { "Kim", 2, 22, 14, 50, "PM" }, NULL);
	w = w->getroot(w);
	w->deletes(w, { "Kim", 2, 22, 14, 50, "PM" }, NULL);
	w = w->getroot(w);
	w->printTree(w, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();

	cout << endl << "< delete할 노드 : 31번 Nam 노드 >" << endl << endl;
	cout << "이 경우 31번 노드 자리에 leaf node가 들어가면서 double black이 발생하며,\n"
		<< "sibling인 6번 노드가 red이다." << endl << endl;
	w->deletes(w, { "Nam", 4, 31, 16, 20, "PM" }, NULL);
	w = w->getroot(w);
	w->printTree(w, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();

	return 0;
}