#include<iostream>
using namespace std;

//n�� �־����� ��, n��° �Ǻ���ġ ���� ���ϴ� �Լ�.
int pivonachi1(int n);
int pivonachi2(int n);

int main()
{
	//int input;
	//cin >> input;
	//cout << pivonachi1(input) << endl;

	for (int i = 1; i < 15; i++)
	{
		cout << pivonachi1(i) << endl;
	}
}

//������ �Ʒ��� �������� ���
int pivonachi1(int n)
{
	if (n == 1)
	{
		return 0;
	}
	else if (n == 2)
	{
		return 1;
	}
	else
	{
		return pivonachi1(n-1) + pivonachi1(n-2);
	}
}
//�Ʒ����� ���� �ö󰡴� ���
int pivonachi2(int n)
{
	int sum;
	// ??
	for (int i = 1; i < n; i++)
	{

	}

	return 0;
}
