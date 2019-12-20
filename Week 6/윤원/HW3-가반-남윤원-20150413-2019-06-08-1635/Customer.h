#pragma once
#include <iostream>
#include <string>
using namespace std;

// full definition of class Customer
class Customer
{
//
// Characteristics:
//
//   A Time consists of some number of hours and minutes. 
//	 For example, 0335 is 3 hours(3 AM) and 35 minutes.
//	 Another example, 1549 is 15 hours(3 PM) and 49 minutes.
//	 A time has correct lange, 0 to 23.
//	 A minute has correct lange, 0 to 59.
//
//   All Times are assumed to fall on the same day.
//
	
public:
	Customer();		// �⺻ ������
	Customer(string m_name, int m_group_num, int m_turn, int m_hour, int m_minute, string m_AM_PM);	// ������
	~Customer();	// �⺻ �Ҹ���

// ��� �Լ�
public:
	void readTime(bool & errorFlag);
	//   Precondition: Standard input has characters available.
	//   Postconditions: Leading whitespace characters are ignored; 
	//      readTime attempts to read, from standard input, a time in 
	//      the format <HH>:<MM><A>, where <HH> is an integer between 
	//      1 and 12, <MM> is an integer between 0 and 59, and <A> is 
	//      either "AM" or "PM". If a properly formatted time can be 
	//      read, errorFlag is set to false, and the value of the Time
	//      variable is set to the time read; otherwise, errorFlag is 
	//      set to true.

	int subtractTimes(Customer t);
	//   Precondition: This Time variable contains a proper value.
	//   Postcondition: None.
	//   Returns: The difference, in minutes, between this Time and Time t. 
	//      If this Time occurs prior to Time t, the returned difference 
	//      is negative.

	void Addtime(int arrival_minutes, int future_time);
	// Precondition : �� �Լ��� �Է°����� ȯ�ڰ� ������ ������ �ð���, ��� ��� �ð��� �Է¹޴´�.
	// Postconditions : �� �Լ� �����, �����Ǵ� ����ð��� ����Ѵ�.
	// return : void�� �Լ��̹Ƿ� return���� ������ �����Ǵ� ����ð�(���ð�)�� ����Ѵ�.
	
	// get �Լ�
	string getName();
	// Precondition : �� �Լ��� ���ڷ� �޴� �Ű� ������ ����.
	// Postconditions : �� �Լ��� ����Ǹ�, string���� ��ȯ�ϹǷ� 
	//                  = ������ �������μ� string ������ ���� �Ҵ����� �� �ִ�.
	//                  ���� ���, string a; a = getName(); �̶�� �ڵ带 ®�� ���,
	//                  string ���� a�� ���� �Ҵ��� ���� �ְ� �ȴ�.
	// return : �� �Լ��� �� Ŭ������ ��� ����(private)�� name(�̸�)�� ��ȯ�Ѵ�.

	int getTurn();
	// Precondition : �� �Լ��� ���ڷ� �޴� �Ű� ������ ����.
	// Postconditions : �� �Լ��� ����Ǹ�, int���� ��ȯ�ϹǷ� 
	//                  = ������ �������μ� int ������ ���� �Ҵ����� �� �ִ�.
	//                  ���� ���, int b; b = getTurn(); �̶�� �ڵ带 ®�� ���,
	//                  int ���� b�� ���� �Ҵ��� ���� �ְ� �ȴ�.
	// return : �� �Լ��� �� Ŭ������ ��� ����(private)�� turn(����)�� ��ȯ�Ѵ�.

	int getGroup_num();
	// Precondition : �� �Լ��� ���ڷ� �޴� �Ű� ������ ����.
	// Postconditions : �� �Լ��� ����Ǹ�, int���� ��ȯ�ϹǷ� 
	//                  = ������ �������μ� int ������ ���� �Ҵ����� �� �ִ�.
	//                  ���� ���, int c; c = getGroup_num(); �̶�� �ڵ带 ®�� ���,
	//                  int ���� c�� ���� �Ҵ��� ���� �ְ� �ȴ�.
	// return : �� �Լ��� �� Ŭ������ ��� ����(private)�� group_num(�׷� �ο�)�� ��ȯ�Ѵ�.

	int getArr_time();
	// Precondition : �� �Լ��� ���ڷ� �޴� �Ű� ������ ����.
	// Postconditions : �� �Լ��� ����Ǹ�, int���� ��ȯ�ϹǷ� 
	//                  = ������ �������μ� int ������ ���� �Ҵ����� �� �ִ�.
	//                  ���� ���, int d; d = getArr_time(); �̶�� �ڵ带 ®�� ���,
	//                  int ���� d�� ���� �Ҵ��� ���� �ְ� �ȴ�.
	// return : �� �Լ��� �� Ŭ������ ��� ����(private)�� arr_time(���� �ð� - ������ ��� ȯ���� ��)�� ��ȯ�Ѵ�.

	int getHour();
	// Precondition : �� �Լ��� ���ڷ� �޴� �Ű� ������ ����.
	// Postconditions : �� �Լ��� ����Ǹ�, int���� ��ȯ�ϹǷ� 
	//                  = ������ �������μ� int ������ ���� �Ҵ����� �� �ִ�.
	//                  ���� ���, int e; e = getHour(); �̶�� �ڵ带 ®�� ���,
	//                  int ���� d�� ���� �Ҵ��� ���� �ְ� �ȴ�.
	// return : �� �Լ��� �� Ŭ������ ��� ����(private)�� hour(���� �ð� - �ð�)�� ��ȯ�Ѵ�.

	int getMinute();
	// Precondition : �� �Լ��� ���ڷ� �޴� �Ű� ������ ����.
	// Postconditions : �� �Լ��� ����Ǹ�, int���� ��ȯ�ϹǷ� 
	//                  = ������ �������μ� int ������ ���� �Ҵ����� �� �ִ�.
	//                  ���� ���, int f; f = getMinute(); �̶�� �ڵ带 ®�� ���,
	//                  int ���� f�� ���� �Ҵ��� ���� �ְ� �ȴ�.
	// return : �� �Լ��� �� Ŭ������ ��� ����(private)�� minute(���� �ð� - ��)�� ��ȯ�Ѵ�.

	string getAM_PM();
	// Precondition : �� �Լ��� ���ڷ� �޴� �Ű� ������ ����.
	// Postconditions : �� �Լ��� ����Ǹ�, string���� ��ȯ�ϹǷ� 
	//                  = ������ �������μ� string ������ ���� �Ҵ����� �� �ִ�.
	//                  ���� ���, string m_AM_PM; m_AM_PM = getAM_PM(); �̶�� �ڵ带 ®�� ���,
	//                  string ���� m_AM_PM�� ���� �Ҵ��� ���� �ְ� �ȴ�.
	// return : �� �Լ��� �� Ŭ������ ��� ����(private)�� AM_PM(���� �ð� - AM �Ǵ� PM)�� ��ȯ�Ѵ�.

	// set �Լ�
	void setName(string m_name);
	// Precondition : �� �Լ��� ���ڷ� string�� ������ �޴´�.
	// Postconditions : �� �Լ��� ����Ǹ�, �� Ŭ������ ��� ����(private)�� name�� 
	//					���ڷ� ���� ���� �Ҵ��ϰ� �ȴ�.
	//					���� ���, string str1 = "Me"; setName(str1);�� ���
	//					�� Ŭ������ ��� ������ name�� str1�� �� "Me"�� ���� �ȴ�.
	// return : void���̹Ƿ� ���ϰ��� ����.

	void setArr_time(int m_arr_time);
	// Precondition : �� �Լ��� ���ڷ� int�� ������ �޴´�.
	// Postconditions : �� �Լ��� ����Ǹ�, �� Ŭ������ ��� ����(private)�� m_arr_time�� 
	//					���ڷ� ���� ���� �Ҵ��ϰ� �ȴ�.
	//					���� ���, int m_arr_time = 3004; setArr_time(m_arr_time);�� ���
	//					�� Ŭ������ ��� ������ arr_time�� m_arr_time�� �� 3004�� ���� �ȴ�.
	// return : void���̹Ƿ� ���ϰ��� ����.

	void setTurn(int m_turn);
	// Precondition : �� �Լ��� ���ڷ� int�� ������ �޴´�.
	// Postconditions : �� �Լ��� ����Ǹ�, �� Ŭ������ ��� ����(private)�� m_arr_time�� 
	//					���ڷ� ���� ���� �Ҵ��ϰ� �ȴ�.
	//					���� ���, int m_arr_time = 3004; setArr_time(m_arr_time);�� ���
	//					�� Ŭ������ ��� ������ arr_time�� m_arr_time�� �� 3004�� ���� �ȴ�.
	// return : void���̹Ƿ� ���ϰ��� ����.

	void setGroup_num(int m_group_num);
	// Precondition : �� �Լ��� ���ڷ� int�� ������ �޴´�.
	// Postconditions : �� �Լ��� ����Ǹ�, �� Ŭ������ ��� ����(private)�� group_num�� 
	//					���ڷ� ���� ���� �Ҵ��ϰ� �ȴ�.
	//					���� ���, int m_group_num = 4; setArr_time(m_group_num);�� ���
	//					�� Ŭ������ ��� ������ group_num�� m_group_num�� �� 4�� ���� �ȴ�.
	// return : void���̹Ƿ� ���ϰ��� ����.
	
	void setHour(int m_hour);
	// Precondition : �� �Լ��� ���ڷ� int�� ������ �޴´�.
	// Postconditions : �� �Լ��� ����Ǹ�, �� Ŭ������ ��� ����(private)�� hour�� 
	//					���ڷ� ���� ���� �Ҵ��ϰ� �ȴ�.
	//					���� ���, int m_hour = 5; setHour(m_hour);�� ���
	//					�� Ŭ������ ��� ������ hour�� m_hour�� �� 5�� ���� �ȴ�.
	// return : void���̹Ƿ� ���ϰ��� ����.

	void setMinute(int m_Minute);
	// Precondition : �� �Լ��� ���ڷ� int�� ������ �޴´�.
	// Postconditions : �� �Լ��� ����Ǹ�, �� Ŭ������ ��� ����(private)�� minute�� 
	//					���ڷ� ���� ���� �Ҵ��ϰ� �ȴ�.
	//					���� ���, int m_minute = 36; setMinute(m_minute);�� ���
	//					�� Ŭ������ ��� ������ minute�� m_minute�� �� 36�� ���� �ȴ�.
	// return : void���̹Ƿ� ���ϰ��� ����.

	void setAM_PM(string m_AM_PM);
	// Precondition : �� �Լ��� ���ڷ� string�� ������ �޴´�.
	// Postconditions : �� �Լ��� ����Ǹ�, �� Ŭ������ ��� ����(private)�� AM_PM�� 
	//					���ڷ� ���� ���� �Ҵ��ϰ� �ȴ�.
	//					���� ���, string m_AM_PM = "AM"; setAM_PM(m_AM_PM);�� ���
	//					�� Ŭ������ ��� ������ AM_PM�� m_AM_PM�� �� AM�� ���� �ȴ�.
	// return : void���̹Ƿ� ���ϰ��� ����.


	// operator overloading - member �Լ��� ����
	bool operator == (Customer& custom_a) const;
		// Precondition : �� �Լ��� ���ڷ� Customer Ŭ���� ������ �޴´�. 
		//				  ��, �Լ��� ȣ���� ��ü�� �ٲ��� ���� ���̴�. (const)
		// Postconditions : �� �Լ��� ����Ǹ�, �ռ� ���� ��ó�� �Լ��� ȣ���� ��ü�� �ٲ��� �ʴ´�.
		//					�ٸ�, ȣ��� ��ü�� ���� �ڽ��� Ŭ���� ���� �� ���� �ð�(Ŭ���� �� ��� ����)�� ���Ͽ�,
		//					true �Ǵ� false�� �����Ѵ�.
		// return : (���ڷ� ���� Ŭ���� ���� �� ���� �ð� - ������ ��� ȯ���� ��)�� (���� ���� Ŭ���� ���� �� 
		// ���� �ð�)�� ���� ��� true(1)��, �ٸ� ��� false(0)�� ��ȯ�Ѵ�.

	bool operator < (Customer& custom_a) const;
		// Precondition : �� �Լ��� ���ڷ� Customer Ŭ���� ������ �޴´�. 
		//				  ��, �Լ��� ȣ���� ��ü�� �ٲ��� ���� ���̴�. (const)
		// Postconditions : �� �Լ��� ����Ǹ�, �ռ� ���� ��ó�� �Լ��� ȣ���� ��ü�� �ٲ��� �ʴ´�.
		//					�ٸ�, ȣ��� ��ü�� ���� �ڽ��� Ŭ���� ���� �� ���� �ð�(Ŭ���� �� ��� ����)�� ���Ͽ�,
		//					true �Ǵ� false�� �����Ѵ�.		
		// return : (���ڷ� ���� Ŭ���� ���� �� ���� �ð� - ������ ��� ȯ���� ��)�� ���� (���� ���� Ŭ���� ���� �� 
		// ���� �ð�)�� Ŭ ��� true(1)��, �ٸ� ��� false(0)�� ��ȯ�Ѵ�.


	bool operator <= (Customer& custom_a) const;
		// Precondition : �� �Լ��� ���ڷ� Customer Ŭ���� ������ �޴´�. 
		//				  ��, �Լ��� ȣ���� ��ü�� �ٲ��� ���� ���̴�. (const)
		// Postconditions : �� �Լ��� ����Ǹ�, �ռ� ���� ��ó�� �Լ��� ȣ���� ��ü�� �ٲ��� �ʴ´�.
		//					�ٸ�, ȣ��� ��ü�� ���� �ڽ��� Ŭ���� ���� �� ���� �ð�(Ŭ���� �� ��� ����)�� ���Ͽ�,
		//					true �Ǵ� false�� �����Ѵ�.
		// return : (���ڷ� ���� �� �� ���� �ð� - ������ ��� ȯ���� ��)�� ���� (���� ���� �� �� 
		// ���� �ð�)�� ���ų� Ŭ�� ��� true(1)��, �ٸ� ��� false(0)�� ��ȯ�Ѵ�.
	

// �ʼ� ����������� private���� �����Ѵ�.
private:
	string name;		// �� �̸�
	int group_num;		// �׷� �ο� ��
	int turn;			// ����
	int arr_time;	    // ���� �ð� - ������ ��� ȯ���� ��

	int hour;			// ���� �ð� - �ð�
	int minute;			// ���� �ð� - ��
	string AM_PM;		// ���� �ð� - am or pm
};

