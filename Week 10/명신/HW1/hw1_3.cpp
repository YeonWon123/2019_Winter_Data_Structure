#include "pch.h"				
#include <iostream>
#include <string>
#include <cstdlib>		//�ð��� �����ϰ� �����ϱ����� ���
#include <ctime>
#include "CCustomer.h"		//Ŭ������ �ҷ���
using namespace std;


void insertionSort(CCustomer b[], int n);	//���������Ÿ���� �迭�� �Էº����� �޴´�
void insertNextItem(CCustomer b[], int i);
void quicksort(CCustomer a[], int first, int last);
int partition(CCustomer a[], int first, int last);
void swapElements(CCustomer a[], int v, int x);

int main()
{
	int i;

	CCustomer a[10];			//���������Ÿ���� �迭�� ���� ��
	a[0].setName("a");			// �̸��� �ϳ��ϳ� �־��ִ� ����̴�
	a[1].setName("b");
	a[2].setName("c");
	a[3].setName("d");
	a[4].setName("e");
	a[5].setName("f");
	a[6].setName("g");
	a[7].setName("h");
	a[8].setName("i");
	a[9].setName("j");

	for (i = 0; i < 10; i++) {			//�׷����� ������ 1~10���� ������ ����
		a[i].setnoc(i);
		a[i].setnog(i);
	}
	for (i = 0; i < 10; i++)	//�����ð��� �����ϰ� ������
	{
		a[i].settime(rand() % 10);
	}

	for (i = 0; i < 10; i++) {	//������
		cout << "����:" << a[i].getnoc() << "\t�׷��ο���:" << a[i].getnog() << "\t�����ð�:" << a[i].gettime() << "\t�̸�:" << a[i].getName() << endl;
	}


	quicksort(a, 0, 9);
	
	cout << endl;

	for (i = 0; i < 10; i++) { //������
		cout << "����:" << a[i].getnoc() << "\t�׷��ο���:" << a[i].getnog() << "\t�����ð�:" << a[i].gettime() << "\t�̸�:" << a[i].getName() << endl;
	}
	cout << endl;
}
void insertionSort(CCustomer a[], int n)	// insertionSort���Ǻ�
{
	int i;
	for (i = 1; i < n; i++)
		insertNextItem(a, i);
}

void insertNextItem(CCustomer a[], int i)
{
	CCustomer newItem = a[i];
	int insertPos = i;
	for (; insertPos && newItem < a[insertPos - 1]; insertPos--)
		a[insertPos] = a[insertPos - 1];
	a[insertPos] = newItem;
}

void quicksort(CCustomer a[], int first, int last)	//quicksort���Ǻ�
{
	if (first >= last)		//��??
		return;

	int split(partition(a, first, last));	//�����Լ�  split

	quicksort(a, first, split - 1);		//������ partition�� ���� quicksort ����
	quicksort(a, split + 1, last);
}


int partition(CCustomer a[], int first, int last)
{
	int lastSmall(first), i;	//lastsmall = first �� �´� ��Ȥ first + 1 �� �δ� ��찡 ����

	for (i = first + 1; i <= last; i++)
	{
		if (a[i] <= a[first])
		{
			++lastSmall;
			swapElements(a, lastSmall, i);
		}
	}
	swapElements(a, first, lastSmall);

	return lastSmall;
}

void swapElements(CCustomer a[], int v, int x)
{
	CCustomer temp;
	temp = a[v];  a[v] = a[x]; a[x] = temp;
}

