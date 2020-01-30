#pragma once
#include<string>
#include<iostream>
using namespace std;

class CCustomer
{
public:
	CCustomer();
	~CCustomer();
	void setName(string name); //main�Լ����� ���� �޾� private�� �ִ� Class������ ���� 
	void setnoc(int num);
	void setnog(int inum);
	void settime(int itime);
	
	string getName();
	int getnoc(); 	//Class������ ����� ���� �ҷ����� �Լ�
	int getnog();
	int gettime();
	bool operator < (CCustomer Time); //operator overloading ����:
	bool operator <= (CCustomer Time);
	void operator = (CCustomer Time);

private:
	int numberofcustomer;
	int numberofgroup;
	int time;
	string name;
};

