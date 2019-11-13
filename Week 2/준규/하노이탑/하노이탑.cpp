#include <iostream>
#include <string>

using namespace std;

string str[100000];


// ���� ���� n, �����, ������, ��ȯ�ϴ� �� �����
int hanoi1(int n, int src, int dst)
{
	int cnt;
	int mid = 6 - src - dst;
	if (n == 1)
	{
		cnt = 0;
		str->append(to_string(src) + " " + to_string(dst) + "\n");
		//cout << to_string(src) + " " + to_string(dst) + "\n";
		cnt++;
		return cnt;
	}
	else
	{
		cnt = 0;
		cnt += hanoi1(n - 1, src, mid); // ���� n-1���� src�� dst�� �ƴ� ������ �ű�.
		cnt += hanoi1(1, src, dst); // �׷� ���� �ſ��� �� ���� �����ϱ� �׳� dst�� �ű�� ��.
		cnt += hanoi1(n - 1, mid, dst); //�ű�� �ٽ� ���� ������ �ű�.
		return cnt;
	}
}

int main(void)
{
	int n;
	cin >> n;

	if (n <= 20)
		cout << hanoi1(n, 1, 3) << endl;
	else
		cout << hanoi1(n, 1, 3) << endl;
	//else
	//	cout << hanoi2(n) << endl;
	for (int i = 0; i < str->length() && n <= 20; i++)
		cout << str[i];
	return 0;
}