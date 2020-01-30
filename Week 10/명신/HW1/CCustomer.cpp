#include "pch.h"
#include "CCustomer.h"


CCustomer::CCustomer()
{
}


CCustomer::~CCustomer()
{
}

void CCustomer::setName(string iname)
{
	name = iname;
}
void CCustomer::setnoc(int num)
{
	numberofcustomer = num;
}

void CCustomer::setnog(int inum)
{
	numberofgroup = inum;
}

void CCustomer::settime(int itime)
{
	time = itime;
}

string CCustomer::getName()
{
	return name;
}

int CCustomer::getnoc()
{
	return numberofcustomer;
}

int CCustomer::gettime()
{
	return time;
}
int CCustomer::getnog()
{
	return numberofgroup;
}

bool CCustomer::operator<(CCustomer Time)
{
	if (time < Time.time) {
		return true;
	}
	else
		return false;
}

bool CCustomer::operator <= (CCustomer Time)
{
	if (time <= Time.time) {
		return true;
	}
	else
		return false;
}


void CCustomer::operator=(CCustomer Time)
{
	time = Time.time;
}
