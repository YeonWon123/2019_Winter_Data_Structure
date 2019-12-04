// g. 괄호
// 백준 9012
// 스택 사용하여 해결, STL 스택을 사용하거나 배열 또는 리스트를 사용
// ACM-ICPC : Daejeon Nationalwide Internet Competition 2012 G번 문제

#include <cstdio>
using namespace std;

int main(void)
{
	int N;
	scanf("%d\n", &N);

	for (int i = 0; i < N; i++) {
		int sum = 0;
		int sw = 0;
		char a[51];

		scanf("%s", a);

		int j = 0;
		while (1) {
			if (a[j] == '(')
				sum++;
			else if (a[j] == ')')
				sum--;
			else // 엔터키나 종료키
				break;

			j++;

			if (sum < 0) {
				sw = 1;
				break;
			}
		}

		if (sw == 0 && sum == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}