#include<iostream>
using namespace std;


// ���� �� Ǯ���� �ڵ�
int main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int e, f, c;
	cin >> e >> f >> c;
	int sum = e + f;
	int num = c;
	if (1)
	{

	}
	// 9 0 3 -> 4   --> 9 -1 = 8 
	// 5 5 2 -> 9   --> 10 - 1 

	// �� ���� �� 9�� �������� �ٲٴµ� �ʿ��� �� ���� 3��
	// �� ���� ���� 5�� �������� �ٲٴµ� �ʿ��� �� ���� 2��

	return 0;
}

// �ٽ� Ǭ �ڵ� 
/*
int main(void)
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int e, f, c;
	cin >> e >> f >> c;
	int total = e + f;
	int sum = 0;
	int k = 0;
	while (total >= c)
	{
		sum += total / c;
		total = total % c + total / c;
	}
	cout << sum;
}
*/