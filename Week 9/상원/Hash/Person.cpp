#include<iostream>
#include"Person.h"
using namespace std;
#pragma warning (disable 4996)
int GetSSN(Person* p)
{
	return p->ssn;
}

void ShowPerInfo(Person* p)
{
	cout << "주민등록번호 :" << p->ssn << "\n";
	cout << "이름 :" << p->name << "\n";
	cout << "주소 :" << p->addr << "\n\n";
}

Person* MakePersonData(int ssn, const char* name,const  char* addr)
{
	Person* newP = new Person[sizeof(Person)];
	newP->ssn = ssn;
	strcpy_s(newP->name, name);
	strcpy_s(newP->addr, addr);
	return newP;
}