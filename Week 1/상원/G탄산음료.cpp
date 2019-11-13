#include<iostream>
using namespace std;


// 시험 때 풀었던 코드
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

	// 총 빈병의 수 9개 새병으로 바꾸는데 필요한 빈병 개수 3개
	// 총 빈병의 개수 5개 새병으로 바꾸는데 필요한 빈병 개수 2개

	return 0;
}

// 다시 푼 코드 
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