#include <stdio.h>
#include<stdlib.h>
#include "Person.h"
#include "Table2.h"
using namespace std;

int MyHashFunc(int k)
{
	return k % 100;
}

int main() {
	Table myTbl;
	Person* np;
	Person* sp;
	Person* rp;

	//초기화 후 삽입
	TBLInit(&myTbl, MyHashFunc);
	np = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);
	np = MakePersonData(900139, "Kim", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);
	np = MakePersonData(900827, "Han", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	sp = TBLSearch(&myTbl, 900254);
	if (sp != NULL) 
	{
		ShowPerInfo(sp);
	}
	sp = TBLSearch(&myTbl, 900139);
	if (sp != NULL) 
	{
		ShowPerInfo(sp);
	}
	sp = TBLSearch(&myTbl, 900827);
	if (sp != NULL) 
	{
		ShowPerInfo(sp);
	}

	//삭제
	rp = TBLDelete(&myTbl, 900254);
	if (rp != NULL) 
	{
		delete(rp);
	}

	rp = TBLDelete(&myTbl, 900139);
	if (rp != NULL) 
	{
		delete(rp);
	}

	rp = TBLDelete(&myTbl, 900827);
	if (rp != NULL) 
	{
		delete(rp);
	}
}