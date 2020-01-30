#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

int GetSSN(Person* p)
{
	return p->ssn;
}

void ShowPerInfo(Person* p)
{
	cout << "�ֹε�Ϲ�ȣ : " << p->ssn << '\n';
	cout << "�̸� : " << p->name << '\n';
	cout << "�ּ� : " << p->addr << '\n' << '\n';
}

Person* MakePersonData(int ssn, const char* name, const char* addr)
{
	Person* newP = new Person;
	newP->ssn = ssn;
	strcpy_s(newP->name, name);
	strcpy_s(newP->addr, addr);
	return newP;
}