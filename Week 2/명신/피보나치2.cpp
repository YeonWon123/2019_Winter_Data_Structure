#include<iostream>
using namespace std;



//n�� �־����� ��, n��° �Ǻ���ġ ���� ���ϴ� �Լ�.
int pivonachi1(int n);
int pivonachi2(int n);

int main()
{
	int input;
	cin >> input;
	cout << pivonachi2(input) << endl;

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
	int fibonacci[50];
	fibonacci[0] = 0;
	fibonacci[1] = 1;

	int sum;
	// ??
	for (int i = 2; i <= n; i++)
	{
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}

	return fibonacci[n];;
}
