#include<iostream>
using namespace std;
int main(void)

{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int N;
	cin >> N;

	// 26 -> 2+6 = 8 -> 68
	// 6+8 = 14 -> 84
	// 8+4 -> 12
	// 42 -> 4+2 -> 6
	int n = 2;
	int A = 0;
	int B = 0;
	int sum1 = 0;
	int a1=0, b1 = 0;
	while (n != 0)
	{
		if (N > 9 && N<100)
		{
			A = N % 10; // 6�� ����
			B = N / 10; // 2��

			cout << "A: " << A << "\n";
			cout << "B :" << B << "\n";
			sum1 = A + B; // 14 
			a1 = sum1 % 10; // 4 ���ڸ�
			b1 = sum1 / 10; // 1 ���ڸ� 

			
		}


	}
	return 0;
}