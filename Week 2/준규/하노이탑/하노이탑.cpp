#include <iostream>
#include <string>

using namespace std;

string str[100000];


// 원판 개수 n, 출발지, 목적지, 반환하는 건 연산수
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
		cnt += hanoi1(n - 1, src, mid); // 위에 n-1개를 src도 dst도 아닌 쪽으로 옮김.
		cnt += hanoi1(1, src, dst); // 그럼 원래 거에는 한 개만 남으니까 그냥 dst로 옮기면 됨.
		cnt += hanoi1(n - 1, mid, dst); //옮긴걸 다시 원래 목적지 옮김.
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