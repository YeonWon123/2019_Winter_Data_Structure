#include<iostream>
using namespace std;

int g_count = 0;
/*
�ϳ���ž�� ��Ģ
n���� ������ �̵��ؾ� �� ���
1. n-1���� ������ from ���� by �� �̵���Ų��.
2. �ǹ��� ������ from ���� to �� �̵���Ų��.
3. n-1���� ������ by ���� to �� �̵���Ų��
*/
//n���� ������ from���� by�� ���� to�� �̵�
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
		hanoitop1(n - 1, from, to, by); //1. n - 1���� ������ from ���� by �� �̵���Ų��.
		hanoitop1(n - 1, by, from, to); //3. n - 1���� ������ by ���� to �� �̵���Ų��
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
		hanoitop2(n - 1, from, to, by); //1. n - 1���� ������ from ���� by �� �̵���Ų��.
		cout << from << " " << to << "\n"; //2. �ǹ��� ������ from ���� to �� �̵���Ų��.
		hanoitop2(n - 1, by, from, to); //3. n - 1���� ������ by ���� to �� �̵���Ų��
	}
}