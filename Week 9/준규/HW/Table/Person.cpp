
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
	cout << "민번: " << p->ssn << endl;
	cout << "이름: " << p->name << endl;
	cout << "주소: " << p->addr << endl;
}

Person* MakePersonData(int ssn, string name, string addr) {
	Person* newP = (Person*)malloc(sizeof(Person));
	newP->ssn = ssn;
	strcpy(newP->name, name.c_str());
	strcpy(newP->addr, addr.c_str());
	return newP;
}