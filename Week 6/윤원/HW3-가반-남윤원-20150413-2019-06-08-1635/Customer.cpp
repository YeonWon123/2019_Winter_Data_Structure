#include "Customer.h"

Customer::Customer()
{
}

Customer::Customer(string m_name, int m_group_num, int m_turn, int m_hour, int m_minute, string m_AM_PM)
{
	name = m_name;
	group_num = m_group_num;
	turn = m_turn;
	hour = m_hour;
	minute = m_minute;
	AM_PM = m_AM_PM;

	if (hour == 12)
		arr_time = minute;
	else
		arr_time = hour * 60 + minute;

	if (AM_PM == "PM")
		arr_time += 60 * 12;
}

Customer::~Customer()
{
}

// get 함수
string Customer::getName()
{
	return name;
}


int Customer::getTurn()
{
	return turn;
}


int Customer::getGroup_num()
{
	return group_num;
}


int Customer::getArr_time()
{
	return arr_time;
}


int Customer::getHour()
{
	return hour;
}


int Customer::getMinute()
{
	return minute;
}


string Customer::getAM_PM()
{
	return AM_PM;
}


// set 함수
void Customer::setName(string m_name)
{
	name = m_name;
}


void Customer::setArr_time(int m_arr_time)
{
	arr_time = m_arr_time;
}


void Customer::setTurn(int m_turn)
{
	turn = m_turn;
}


void Customer::setGroup_num(int m_group_num)
{
	group_num = m_group_num;
}

void Customer::setHour(int m_hour)
{
	hour = m_hour;
}

void Customer::setMinute(int m_minute)
{
	minute = m_minute;
}

void Customer::setAM_PM(string m_AM_PM)
{
	AM_PM = m_AM_PM;
}

// operator overloading
bool Customer::operator == (Customer& custom_a) const {
	if ((arr_time == custom_a.getArr_time()) && (name == custom_a.getName())
		&& (group_num == custom_a.getGroup_num()) && (turn == custom_a.getTurn()))
		return true;
	else
		return false;
}

bool Customer::operator < (Customer& custom_a) const {
	return (arr_time < custom_a.getArr_time());
}

bool Customer::operator <= (Customer& custom_a) const {
	return (arr_time == custom_a.getArr_time() || arr_time < custom_a.getArr_time());
}

void Customer::readTime(bool & errorFlag)
{
	// The time must be formatted as <HH>:<MM><AMorPM>, where
	// <HH> is an int in the range 0 to 12, <MM> is an int in
	// the range 0 to 59, and <AMorPM> is either AM or PM.
	enum AM_PM { AM, PM } AM_or_PM;
	int hours, minutes;
	const char delimiter = ':';

	// Assume that the format is bad -- once valid data is extracted,
	// reset errorFlag to false

	errorFlag = true;
	// formatted input -- fail if not an int
	if (!(cin >> hours))
		return;
	if (hours < 0 || hours > 12)
		return;

	char c;
	cin >> c;
	if (c != delimiter)
		return;
	if (!(cin >> minutes)) // formatted input
		return;
	if (minutes < 0 || minutes > 59)
		return;

	cin >> c;
	if (c == 'A' || c == 'a')
		AM_or_PM = AM;
	else if (c == 'P' || c == 'p')
		AM_or_PM = PM;
	else
		return;
	cin >> c;
	if (c != 'M' && c != 'm')
		return;


	errorFlag = false;

	if (hours == 12)
		arr_time = minutes;
	else
		arr_time = hours * 60 + minutes;
	if (AM_or_PM == PM)
		arr_time += 60 * 12;

}

int Customer::subtractTimes(Customer t)
{
	return arr_time - t.arr_time;
}

void Customer::Addtime(int arrival_minutes, int future_time)
{
	// arrival_minutes에서 시간, 분, PM 추출
	int hours = arrival_minutes / 60;
	// 평균 대기 시간을 더해서 예측되는 진료시간 출력
	int minutes = arrival_minutes - (arrival_minutes / 60) * 60 + future_time;
	string AM_PMs = "AM";
	while (minutes >= 60) {
		hour++;
		minutes = minutes - 60;
	}
	if (hour > 12) {
		hours = hours - 12;
		AM_PMs = "PM";
	}

	cout << "예측되는 진료시간은 약 " << hours << ": " << minutes << " " << AM_PMs << " 입니다!";

}