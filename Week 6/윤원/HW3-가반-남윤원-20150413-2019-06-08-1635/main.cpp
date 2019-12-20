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

	cout << endl << "�����������к� it�������� 20150413 ������ - HW3";
	cout << endl << endl << "1�� ���� : BST insert�� �̿��Ͽ� BST ����" << endl << endl;

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

	cout << endl << endl << "2�� ���� : BST delete�� �̿��Ͽ� ��� �����ϱ�" << endl << endl;
	cout << " 2-1 : (\"1�� ����\"�� ������� ������ �õ���) �ڽ��� ���� ��带 �����ϱ�" << endl << endl;
	cout << "< ������ ��� : 4�� ���, Kim >" << endl << endl;
	b->deletes(b, { "Kim", 2, 4, 12, 00, "PM" }, b);
	b->printTree(b, 1, 64, 1, print_BST_area);
	print_BST_tree();
	print_BST_area_default();

	cout << endl << endl << " 2-2 : (2-1�� ������� ������ �õ���) �ڽ��� �� �� �ִ� ��带 �����ϱ�" << endl << endl;
	cout << "< ������ ��� : 1�� ���, Lee >" << endl << endl;
	b->deletes(b, { "Lee", 3, 1, 11, 15, "AM" }, b);
	b->printTree(b, 1, 64, 1, print_BST_area);
	print_BST_tree();
	print_BST_area_default();

	cout << endl << endl << " 2-3 : (2-2�� ������� ������ �õ���) �ڽ��� �� �� �ִ� ��带 �����ϱ�" << endl << endl;
	cout << "< ������ ��� : 8�� ���, Kang >" << endl << endl;
	b->deletes(b, { "Kang", 3, 8, 15, 26, "PM" }, b);
	b->printTree(b, 1, 64, 1, print_BST_area);
	print_BST_tree();
	print_BST_area_default();

	cout << endl << endl << "3�� ���� : RBT�� �����ϰ�, insert �Լ��� ����Ͽ� ��� ����ϱ�" << endl << endl;
	cout << " 3-1 : parent�� �������� �� uncle�� �������� ���" << endl << endl;
	cout << "RBT insert ���� �� ��" << endl << endl;

	typedef RBT < Customer > CustomerRBT;
	typedef CustomerRBT * CustomerRBTPtr;

	CustomerRBTPtr d(new CustomerRBT);

	// insert�ϰ�, d�� root���� �������ְ�...
	d->insert(d, { "Park", 1, 3, 10, 00, "AM" }, NULL);
	d = d->getroot(d);
	d->insert(d, { "Lee", 2, 7, 11, 30, "AM" }, NULL);
	d = d->getroot(d);
	d->insert(d, { "Nam", 4, 18, 13, 23, "PM" }, NULL);
	d = d->getroot(d);
	d->printTree(d, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();

	cout << "< insert�� ��� : 5�� ���, Ha >" << endl << endl;
	cout << "5�� ��� insert �� parent(3�� ���) : ������, uncle(18�� ���) : ������" << endl << endl;
	cout << "insert ���� RBT ���" << endl << endl;
	d->insert(d, { "Ha", 2, 5, 11, 00, "AM" }, NULL);
	d = d->getroot(d);
	d->printTree(d, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();



	cout << endl << endl << " 3-2 (1) : parent�� �������� �� uncle�� �������� ��� - (1) : ���� ���" << endl << endl;
	cout << "RBT insert ���� �� ��" << endl << endl;

	CustomerRBTPtr e(new CustomerRBT);

	// insert�ϰ�, e�� root���� �������ְ�...
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

	cout << "< insert�� ��� : 15�� ���, Ha >" << endl << endl;
	cout << "15 ��带 insert�� �� ����, 3-1���� �õ��� parent�� �������� �� uncle�� �������� ��쿡 �ش���" << endl << endl;
	cout << "(15 ��� insert�� parent(11�� ���) ������, uncle(8�� ���) ������" << endl << endl;
	cout << "�� ����, 10 ��尡 ���������� �ٲ�鼭, 3(��)-7(uncle:��)-18(parent:��)-10(me:��) ��尣 3-2 (1) ���� ������ ������" << endl << endl;
	cout << "insert ���� RBT ���" << endl << endl;
	e->insert(e, { "Ha", 2, 15, 13, 00, "PM" }, NULL);
	e = e->getroot(e);
	e->printTree(e, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();


	cout << " 3-2 (2) : parent�� �������� �� uncle�� �������� ��� - (2) : ������ ���" << endl << endl;
	cout << "RBT insert ���� �� ��" << endl << endl;

	CustomerRBTPtr f(new CustomerRBT);

	// insert�ϰ�, e�� root���� �������ְ�...
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

	cout << "< insert�� ��� : 25�� ���, Ha >" << endl << endl;
	cout << "25 ��带 insert�� �� ����, 3-1���� �õ��� parent�� �������� �� uncle�� �������� ��쿡 �ش���" << endl << endl;
	cout << "�� ����, 22 ��尡 ���������� �ٲ�鼭, 3(��)-7(uncle:��)-18(parent:��)-22(me: ��) ��尣 3-2 (2) ���� ������ ������" << endl << endl;
	cout << "insert ���� RBT ���" << endl << endl;
	f->insert(f, { "Ha", 2, 25, 16, 15, "PM" }, NULL);
	f = f->getroot(f);
	f->printTree(f, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();

	cout << endl << endl << "4�� ���� : RBT�� delete �Լ� ����, double black�� �� �� �ִ� ��带 �����" << endl << endl;
	cout << "double black�� �� �� �ִ� ����, black�� ��带 ������ �� �߻��Ѵ�. ���� black�� ��带 ����� ��츦 ���캸��" << endl << endl;
	cout << " 4-1 (1) sibling�� black�̰� sibling�� child�� red�� ��� - (1) : ���� ���" << endl << endl;
	cout << "RBT delete ���� �� ��" << endl << endl;
	CustomerRBTPtr g(new CustomerRBT);

	// insert�ϰ�, g�� root���� �������ְ�...
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

	cout << "< delete�� ��� : 28�� Kim ��� >" << endl << endl;
	cout << "�� ��� 28�� ��� �ڸ��� leaf node�� ���鼭 double black�� �߻��ϸ�,\n"
		<< "sibling�� 31�� ���� BLACK�̰� sibling�� child�� 30�� ���� RED�̹Ƿ� ���� ����̴�." << endl << endl;
	g->deletes(g, { "Kim", 4, 28, 19, 40, "PM" }, NULL);
	g = g->getroot(g);
	
	g->printTree(g, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();
		

	cout << endl << endl << " 4-1 (2) sibling�� black�̰� sibling�� child�� red�� ��� - (2) : ������ ���" << endl << endl;
	cout << "RBT delete ���� �� ��" << endl << endl;
	CustomerRBTPtr h(new CustomerRBT);

	// insert�ϰ�, h�� root���� �������ְ�...
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

	cout << "< delete�� ��� : 21�� Lee ��� >" << endl << endl;
	cout << "�� ��� 21�� ��� �ڸ��� leaf node�� ���鼭 double black�� �߻��ϸ�,\n"
		<< "sibling�� 31�� ���� BLACK�̰� sibling�� child�� 41�� ���� RED�̹Ƿ� ������ ����̴�."
		<< "(28�� ����� ��� don't care�̴�.)" << endl << endl;
	h->deletes(h, { "Lee", 2, 21, 18, 30, "PM" }, NULL);
	h = h->getroot(h);

	h->printTree(h, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();

	cout << endl << endl << " 4-2 sibling�� black�̰� sibling�� children�� ��� black�� ���" << endl << endl;
	cout << "RBT delete ���� �� ��" << endl << endl;

	CustomerRBTPtr k(new CustomerRBT);

	// insert�ϰ�, e�� root���� �������ְ�...
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
	
	cout << "< delete�� ��� : 23�� Park ��� >" << endl << endl;
	cout << "�� ��� 23�� ��� �ڸ��� 30�� ��尡 ���鼭 double black�� �߻��ϸ�,\n"
		<< "sibling�� 6�� ���� BLACK�̰� sibling�� child�� 3�� ���� 7�� ��尡 ��� BLACK�̴�." << endl << endl;
	k->deletes(k, { "Park", 1, 23, 15, 30, "PM" }, NULL);
	k = k->getroot(k);
	k->printTree(k, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();
	
	cout << endl << endl << " 4-3 sibling�� red�� ���" << endl << endl;
	cout << "RBT delete ���� �� ��" << endl << endl;

	CustomerRBTPtr w(new CustomerRBT);

	// insert�ϰ�, w�� root���� �������ְ�...
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

	cout << endl << "< delete�� ��� : 31�� Nam ��� >" << endl << endl;
	cout << "�� ��� 31�� ��� �ڸ��� leaf node�� ���鼭 double black�� �߻��ϸ�,\n"
		<< "sibling�� 6�� ��尡 red�̴�." << endl << endl;
	w->deletes(w, { "Nam", 4, 31, 16, 20, "PM" }, NULL);
	w = w->getroot(w);
	w->printTree(w, 1, 64, 1, print_RBT_area);
	print_RBT_tree();
	print_RBT_area_default();

	return 0;
}