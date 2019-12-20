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
	Customer();		// 기본 생성자
	Customer(string m_name, int m_group_num, int m_turn, int m_hour, int m_minute, string m_AM_PM);	// 생성자
	~Customer();	// 기본 소멸자

// 멤버 함수
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
	// Precondition : 이 함수는 입력값으로 환자가 병원에 도착한 시간과, 평균 대기 시간을 입력받는다.
	// Postconditions : 이 함수 종료시, 예측되는 진료시간을 출력한다.
	// return : void형 함수이므로 return값은 없으며 예측되는 진료시간(대기시간)을 출력한다.
	
	// get 함수
	string getName();
	// Precondition : 이 함수는 인자로 받는 매개 변수가 없다.
	// Postconditions : 이 함수가 종료되면, string값을 반환하므로 
	//                  = 우측에 있음으로서 string 변수에 값을 할당해줄 수 있다.
	//                  예를 들어, string a; a = getName(); 이라는 코드를 짰을 경우,
	//                  string 변수 a에 값을 할당할 수가 있게 된다.
	// return : 이 함수는 이 클래스의 멤버 변수(private)인 name(이름)을 반환한다.

	int getTurn();
	// Precondition : 이 함수는 인자로 받는 매개 변수가 없다.
	// Postconditions : 이 함수가 종료되면, int값을 반환하므로 
	//                  = 우측에 있음으로서 int 변수에 값을 할당해줄 수 있다.
	//                  예를 들어, int b; b = getTurn(); 이라는 코드를 짰을 경우,
	//                  int 변수 b에 값을 할당할 수가 있게 된다.
	// return : 이 함수는 이 클래스의 멤버 변수(private)인 turn(순번)을 반환한다.

	int getGroup_num();
	// Precondition : 이 함수는 인자로 받는 매개 변수가 없다.
	// Postconditions : 이 함수가 종료되면, int값을 반환하므로 
	//                  = 우측에 있음으로서 int 변수에 값을 할당해줄 수 있다.
	//                  예를 들어, int c; c = getGroup_num(); 이라는 코드를 짰을 경우,
	//                  int 변수 c에 값을 할당할 수가 있게 된다.
	// return : 이 함수는 이 클래스의 멤버 변수(private)인 group_num(그룹 인원)을 반환한다.

	int getArr_time();
	// Precondition : 이 함수는 인자로 받는 매개 변수가 없다.
	// Postconditions : 이 함수가 종료되면, int값을 반환하므로 
	//                  = 우측에 있음으로서 int 변수에 값을 할당해줄 수 있다.
	//                  예를 들어, int d; d = getArr_time(); 이라는 코드를 짰을 경우,
	//                  int 변수 d에 값을 할당할 수가 있게 된다.
	// return : 이 함수는 이 클래스의 멤버 변수(private)인 arr_time(도착 시간 - 분으로 모두 환산한 값)을 반환한다.

	int getHour();
	// Precondition : 이 함수는 인자로 받는 매개 변수가 없다.
	// Postconditions : 이 함수가 종료되면, int값을 반환하므로 
	//                  = 우측에 있음으로서 int 변수에 값을 할당해줄 수 있다.
	//                  예를 들어, int e; e = getHour(); 이라는 코드를 짰을 경우,
	//                  int 변수 d에 값을 할당할 수가 있게 된다.
	// return : 이 함수는 이 클래스의 멤버 변수(private)인 hour(도착 시간 - 시간)을 반환한다.

	int getMinute();
	// Precondition : 이 함수는 인자로 받는 매개 변수가 없다.
	// Postconditions : 이 함수가 종료되면, int값을 반환하므로 
	//                  = 우측에 있음으로서 int 변수에 값을 할당해줄 수 있다.
	//                  예를 들어, int f; f = getMinute(); 이라는 코드를 짰을 경우,
	//                  int 변수 f에 값을 할당할 수가 있게 된다.
	// return : 이 함수는 이 클래스의 멤버 변수(private)인 minute(도착 시간 - 분)을 반환한다.

	string getAM_PM();
	// Precondition : 이 함수는 인자로 받는 매개 변수가 없다.
	// Postconditions : 이 함수가 종료되면, string값을 반환하므로 
	//                  = 우측에 있음으로서 string 변수에 값을 할당해줄 수 있다.
	//                  예를 들어, string m_AM_PM; m_AM_PM = getAM_PM(); 이라는 코드를 짰을 경우,
	//                  string 변수 m_AM_PM에 값을 할당할 수가 있게 된다.
	// return : 이 함수는 이 클래스의 멤버 변수(private)인 AM_PM(도착 시간 - AM 또는 PM)을 반환한다.

	// set 함수
	void setName(string m_name);
	// Precondition : 이 함수는 인자로 string형 변수를 받는다.
	// Postconditions : 이 함수가 종료되면, 이 클래스의 멤버 변수(private)인 name에 
	//					인자로 받은 값을 할당하게 된다.
	//					예를 들어, string str1 = "Me"; setName(str1);의 경우
	//					이 클래스의 멤버 변수인 name에 str1의 값 "Me"가 들어가게 된다.
	// return : void형이므로 리턴값이 없다.

	void setArr_time(int m_arr_time);
	// Precondition : 이 함수는 인자로 int형 변수를 받는다.
	// Postconditions : 이 함수가 종료되면, 이 클래스의 멤버 변수(private)인 m_arr_time에 
	//					인자로 받은 값을 할당하게 된다.
	//					예를 들어, int m_arr_time = 3004; setArr_time(m_arr_time);의 경우
	//					이 클래스의 멤버 변수인 arr_time에 m_arr_time의 값 3004가 들어가게 된다.
	// return : void형이므로 리턴값이 없다.

	void setTurn(int m_turn);
	// Precondition : 이 함수는 인자로 int형 변수를 받는다.
	// Postconditions : 이 함수가 종료되면, 이 클래스의 멤버 변수(private)인 m_arr_time에 
	//					인자로 받은 값을 할당하게 된다.
	//					예를 들어, int m_arr_time = 3004; setArr_time(m_arr_time);의 경우
	//					이 클래스의 멤버 변수인 arr_time에 m_arr_time의 값 3004가 들어가게 된다.
	// return : void형이므로 리턴값이 없다.

	void setGroup_num(int m_group_num);
	// Precondition : 이 함수는 인자로 int형 변수를 받는다.
	// Postconditions : 이 함수가 종료되면, 이 클래스의 멤버 변수(private)인 group_num에 
	//					인자로 받은 값을 할당하게 된다.
	//					예를 들어, int m_group_num = 4; setArr_time(m_group_num);의 경우
	//					이 클래스의 멤버 변수인 group_num에 m_group_num의 값 4가 들어가게 된다.
	// return : void형이므로 리턴값이 없다.
	
	void setHour(int m_hour);
	// Precondition : 이 함수는 인자로 int형 변수를 받는다.
	// Postconditions : 이 함수가 종료되면, 이 클래스의 멤버 변수(private)인 hour에 
	//					인자로 받은 값을 할당하게 된다.
	//					예를 들어, int m_hour = 5; setHour(m_hour);의 경우
	//					이 클래스의 멤버 변수인 hour에 m_hour의 값 5가 들어가게 된다.
	// return : void형이므로 리턴값이 없다.

	void setMinute(int m_Minute);
	// Precondition : 이 함수는 인자로 int형 변수를 받는다.
	// Postconditions : 이 함수가 종료되면, 이 클래스의 멤버 변수(private)인 minute에 
	//					인자로 받은 값을 할당하게 된다.
	//					예를 들어, int m_minute = 36; setMinute(m_minute);의 경우
	//					이 클래스의 멤버 변수인 minute에 m_minute의 값 36이 들어가게 된다.
	// return : void형이므로 리턴값이 없다.

	void setAM_PM(string m_AM_PM);
	// Precondition : 이 함수는 인자로 string형 변수를 받는다.
	// Postconditions : 이 함수가 종료되면, 이 클래스의 멤버 변수(private)인 AM_PM에 
	//					인자로 받은 값을 할당하게 된다.
	//					예를 들어, string m_AM_PM = "AM"; setAM_PM(m_AM_PM);의 경우
	//					이 클래스의 멤버 변수인 AM_PM에 m_AM_PM의 값 AM이 들어가게 된다.
	// return : void형이므로 리턴값이 없다.


	// operator overloading - member 함수로 선언
	bool operator == (Customer& custom_a) const;
		// Precondition : 이 함수는 인자로 Customer 클래스 변수를 받는다. 
		//				  단, 함수로 호출한 객체는 바뀌지 않을 것이다. (const)
		// Postconditions : 이 함수가 종료되면, 앞서 말한 것처럼 함수로 호출한 객체는 바뀌지 않는다.
		//					다만, 호출된 객체와 현재 자신의 클래스 변수 중 도착 시간(클래스 안 멤버 변수)을 비교하여,
		//					true 또는 false를 리턴한다.
		// return : (인자로 받은 클래스 변수 중 도착 시간 - 분으로 모두 환산한 값)과 (현재 가진 클래스 변수 중 
		// 도착 시간)이 같을 경우 true(1)를, 다를 경우 false(0)를 반환한다.

	bool operator < (Customer& custom_a) const;
		// Precondition : 이 함수는 인자로 Customer 클래스 변수를 받는다. 
		//				  단, 함수로 호출한 객체는 바뀌지 않을 것이다. (const)
		// Postconditions : 이 함수가 종료되면, 앞서 말한 것처럼 함수로 호출한 객체는 바뀌지 않는다.
		//					다만, 호출된 객체와 현재 자신의 클래스 변수 중 도착 시간(클래스 안 멤버 변수)을 비교하여,
		//					true 또는 false를 리턴한다.		
		// return : (인자로 받은 클래스 변수 중 도착 시간 - 분으로 모두 환산한 값)에 비해 (현재 가진 클래스 변수 중 
		// 도착 시간)이 클 경우 true(1)를, 다를 경우 false(0)를 반환한다.


	bool operator <= (Customer& custom_a) const;
		// Precondition : 이 함수는 인자로 Customer 클래스 변수를 받는다. 
		//				  단, 함수로 호출한 객체는 바뀌지 않을 것이다. (const)
		// Postconditions : 이 함수가 종료되면, 앞서 말한 것처럼 함수로 호출한 객체는 바뀌지 않는다.
		//					다만, 호출된 객체와 현재 자신의 클래스 변수 중 도착 시간(클래스 안 멤버 변수)을 비교하여,
		//					true 또는 false를 리턴한다.
		// return : (인자로 받은 값 중 도착 시간 - 분으로 모두 환산한 값)에 비해 (현재 가진 값 중 
		// 도착 시간)이 같거나 클을 경우 true(1)를, 다를 경우 false(0)를 반환한다.
	

// 필수 멤버변수들은 private으로 선언한다.
private:
	string name;		// 고객 이름
	int group_num;		// 그룹 인원 수
	int turn;			// 순번
	int arr_time;	    // 도착 시간 - 분으로 모두 환산한 값

	int hour;			// 도착 시간 - 시각
	int minute;			// 도착 시간 - 분
	string AM_PM;		// 도착 시간 - am or pm
};

