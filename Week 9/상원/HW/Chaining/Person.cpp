#include <stdio.h>
#include<iostream>
#include "Person.h"
using namespace std;
int GetSSN(Person * p)
{
	return p->ssn;
}

void ShowPerInfo(Person * p)
{
	cout << "�ֹε�Ϲ�ȣ :" << p->ssn << '\n';
	cout << "�̸� :" << p->name << "\n";
	cout << "�ּ� :" << p->addr << "\n";
	
}

Person * MakePersonData(int ssn, const char * name, const char * addr)
{
	Person * newP = (Person*)malloc(sizeof(Person));

	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);
	return newP;
}
