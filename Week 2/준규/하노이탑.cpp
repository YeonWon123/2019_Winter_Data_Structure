#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

int N;
//string str[100000];
//string str2 = "";

// 원판 개수 n, 출발지, 목적지, 반환하는 건 연산수
void hanoi1(int n, int src, int dst) // 최대한 빠르게 출력하기 위해 return을 없앴음.
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
	hanoi1(n - 1, src, mid); // 위에 n-1개를 src도 dst도 아닌 쪽으로 옮김.
	printf("%d %d\n", src, dst); // 그럼 원래 거에는 한 개만 남으니까 그냥 dst로 옮기면 됨.
	//str2.append(to_string(src) + " " + to_string(dst) + "\n");
	hanoi1(n - 1, mid, dst); //옮긴걸 다시 원래 목적지 옮김.
	//return ++cnt;
}

int main(void)
{
	ios::sync_with_stdio(false); // 최대한 빠르게 출력하기 위함
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	string big_num = to_string(pow(2, N)); // 문자열로 매우 큰 정수 처리 신박하네
	int idx = big_num.find('.');
	big_num = big_num.substr(0, idx);
	big_num[big_num.length() - 1] -= 1; // 2^n - 1 이건 그냥 점화식 일반항 구한거

	cout << big_num << endl;
	if (N <= 20)
		hanoi1(N, 1, 3);

	return 0;
}
