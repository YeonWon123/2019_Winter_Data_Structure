#include<iostream>
using namespace std;

int g_count = 0;
/*
하노이탑의 규칙
n개의 원반을 이동해야 할 경우
1. n-1개의 원반을 from 에서 by 로 이동시킨다.
2. 맨밑의 원반을 from 에서 to 로 이동시킨다.
3. n-1개의 원반을 by 에서 to 로 이동시킨다
*/
//n개의 원반을 from에서 by를 거쳐 to로 이동
void hanoitop1(int n, int from, int by, int to);
void hanoitop2(int n, int from, int by, int to);

int main()
{
	int num;
	cin >> num;
	if (num <= 20)
	{
		hanoitop1(num, 1, 2, 3);
		cout << g_count << "\n";
		hanoitop2(num, 1, 2, 3);
	}
	else
	{
		hanoitop1(num, 1, 2, 3);
		cout << g_count << "\n";
	}

}
void hanoitop1(int n, int from, int by, int to)
{
	if (n == 1)
	{
		g_count++;
	}
	else
	{
		g_count ++;
		hanoitop1(n - 1, from, to, by); //1. n - 1개의 원반을 from 에서 by 로 이동시킨다.
		hanoitop1(n - 1, by, from, to); //3. n - 1개의 원반을 by 에서 to 로 이동시킨다
	}
}
void hanoitop2(int n, int from, int by, int to)
{
	if (n == 1)
	{
		g_count++;
		cout << from << " " << to << "\n";
	}
	else
	{
		g_count ++;
		hanoitop2(n - 1, from, to, by); //1. n - 1개의 원반을 from 에서 by 로 이동시킨다.
		cout << from << " " << to << "\n"; //2. 맨밑의 원반을 from 에서 to 로 이동시킨다.
		hanoitop2(n - 1, by, from, to); //3. n - 1개의 원반을 by 에서 to 로 이동시킨다
	}
}