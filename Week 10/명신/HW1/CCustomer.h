#pragma once
#include<string>
#include<iostream>
using namespace std;

class CCustomer
{
public:
	CCustomer();
	~CCustomer();
	void setName(string name); //main함수에서 값을 받아 private에 있는 Class변수에 저장 
	void setnoc(int num);
	void setnog(int inum);
	void settime(int itime);
	
	string getName();
	int getnoc(); 	//Class변수에 저장된 값을 불러오는 함수
	int getnog();
	int gettime();
	bool operator < (CCustomer Time); //operator overloading 역할:
	bool operator <= (CCustomer Time);
	void operator = (CCustomer Time);

private:
	int numberofcustomer;
	int numberofgroup;
	int time;
	string name;
};

