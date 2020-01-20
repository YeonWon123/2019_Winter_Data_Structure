
#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"
#include <iostream>

using namespace std;

int GetSSN(Person* p) {
	return p->ssn;
}

void ShowPerInfo(Person* p) {
	cout << "�ι�: " << p->ssn << endl;
	cout << "�̸�: " << p->name << endl;
	cout << "�ּ�: " << p->addr << endl;
}

Person* MakePersonData(int ssn, string name, string addr) {
	Person* newP = (Person*)malloc(sizeof(Person));
	newP->ssn = ssn;
	strcpy(newP->name, name.c_str());
	strcpy(newP->addr, addr.c_str());
	return newP;
}