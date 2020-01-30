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
	cout << "주민등록번호 : " << p->ssn << '\n';
	cout << "이름 : " << p->name << '\n';
	cout << "주소 : " << p->addr << '\n' << '\n';
}

Person* MakePersonData(int ssn, const char* name, const char* addr)
{
	Person* newP = new Person;
	newP->ssn = ssn;
	strcpy_s(newP->name, name);
	strcpy_s(newP->addr, addr);
	return newP;
}