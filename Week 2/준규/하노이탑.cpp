#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int N;
//string str[100000];
//string str2 = "";

// ���� ���� n, �����, ������, ��ȯ�ϴ� �� �����
void hanoi1(int n, int src, int dst) // �ִ��� ������ ����ϱ� ���� return�� ������.
{
	//int cnt = 0;
	int mid = 6 - src - dst;
	if (n == 1)
	{
		//str->append(to_string(src) + " " +5 to_string(dst) + "\n");
		printf("%d %d\n", src, dst);
		//str2.append(to_string(src) + " " + to_string(dst) + "\n");
		return;
	}
	hanoi1(n - 1, src, mid); // ���� n-1���� src�� dst�� �ƴ� ������ �ű�.
	printf("%d %d\n", src, dst); // �׷� ���� �ſ��� �� ���� �����ϱ� �׳� dst�� �ű�� ��.
	//str2.append(to_string(src) + " " + to_string(dst) + "\n");
	hanoi1(n - 1, mid, dst); //�ű�� �ٽ� ���� ������ �ű�.
	//return ++cnt;
}

int main(void)
{
	ios::sync_with_stdio(false); // �ִ��� ������ ����ϱ� ����
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	string big_num = to_string(pow(2, N)); // ���ڿ��� �ſ� ū ���� ó�� �Ź��ϳ�
	int idx = big_num.find('.');
	big_num = big_num.substr(0, idx);
	big_num[big_num.length() - 1] -= 1; // 2^n - 1 �̰� �׳� ��ȭ�� �Ϲ��� ���Ѱ�

	cout << big_num << endl;
	if (N <= 20)
		hanoi1(N, 1, 3);

	return 0;
}
