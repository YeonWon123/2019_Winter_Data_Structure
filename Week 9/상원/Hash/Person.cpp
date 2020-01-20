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
	cout << "�ֹε�Ϲ�ȣ :" << p->ssn << "\n";
	cout << "�̸� :" << p->name << "\n";
	cout << "�ּ� :" << p->addr << "\n\n";
}

Person* MakePersonData(int ssn, const char* name,const  char* addr)
{
	Person* newP = new Person[sizeof(Person)];
	newP->ssn = ssn;
	strcpy_s(newP->name, name);
	strcpy_s(newP->addr, addr);
	return newP;
}