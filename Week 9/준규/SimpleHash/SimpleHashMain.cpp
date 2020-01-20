
#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k) {
	return k % 100;
}

int main(void) {
	Table myTbl;
	Person* np;
	Person* sp;
	Person* rp;
	TBLInit(&myTbl, MyHashFunc);

	// ������ �Է�
	np = MakePersonData(20120001, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);
	np = MakePersonData(20120002, "Kim", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);
	np = MakePersonData(20120003, "Han", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	// ������ Ž��
	sp = TBLSearch(&myTbl, 20120001);
	if (sp != NULL) {
		ShowPerInfo(sp);
	}
	sp = TBLSearch(&myTbl, 20120002);
	if (sp != NULL) {
		ShowPerInfo(sp);
	}
	sp = TBLSearch(&myTbl, 20120003);
	if (sp != NULL) {
		ShowPerInfo(sp);
	}

	// ������ ����
	rp = TBLDelete(&myTbl, 20120001);
	if (rp != NULL) {
		free(rp);
	}
	rp = TBLDelete(&myTbl, 20120002);
	if (rp != NULL) {
		free(rp);
	}
	rp = TBLDelete(&myTbl, 20120003);
	if (rp != NULL) {
		free(rp);
	}

	return 0;
}