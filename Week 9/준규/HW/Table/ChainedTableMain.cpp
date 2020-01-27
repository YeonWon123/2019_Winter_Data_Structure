
#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table2.h"
#include <iostream>

using namespace std;

int MyHashFunc(int k)
{
	return k & 100;
}

int main(void)
{
	Table myTbl;
	Person* np;
	Person* sp;
	Person* rp;

	TBLInit(&myTbl, MyHashFunc);

	// ������ �Է�
	np = MakePersonData(900123, "A", "seoul");
	TBLInsert(&myTbl, GetSSN(np), np);
	sp = MakePersonData(900456, "B", "suwon");
	TBLInsert(&myTbl, GetSSN(sp), sp);
	rp = MakePersonData(900789, "C", "busan");
	TBLInsert(&myTbl, GetSSN(rp), rp);
	
	// ������ Ž��
	sp = TBLSearch(&myTbl, 900123);
	if (sp != nullptr)
		ShowPerInfo(sp);
	sp = TBLSearch(&myTbl, 900456);
	if (sp != nullptr)
		ShowPerInfo(sp);
	sp = TBLSearch(&myTbl, 900789);
	if (sp != nullptr)
		ShowPerInfo(sp);

	//�����ͻ���
	rp = TBLDelete(&myTbl, 900123);
	if (rp != nullptr)
		free(rp);
	rp = TBLDelete(&myTbl, 900456);
	if (rp != nullptr)
		free(rp);
	rp = TBLDelete(&myTbl, 900789);
	if (rp != nullptr)
		free(rp);
}