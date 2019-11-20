#include <stdio.h>
#include <math.h>
#include <string.h>
#pragma warning(disable: 4996)
#define MAX 1000000

//막대 from에 쌓여있는 원판을 tmp를 이용해 to로 옮겨보자
//from: 시작점, tmp: 중간지점, to: 도착지점
void hanoi_tower(int N, int from, int tmp, int to) {            
	if (N <= 20) {
		if (N == 1) {
			printf("%d %d\n", from, to);
		}
		else {
			//1. 1개(제일 밑)를 제외한 모든 원판을 to를 이용해 tmp로 옮긴다.
			hanoi_tower(N - 1, from, to, tmp); 
			//2. from막대에 있는 1개(제일 바닥에 있는 원판)를 to로 옮긴다.
			printf("%d %d\n", from, to);
			//3. tmp에 있는 제일 밑 원판을 제외한 모든 원판을 from을 이용해 to로 옮긴다.
			hanoi_tower(N - 1, tmp, from, to);
		}
	}
}

int main() {
	int n = 0;
	char k_result[MAX];
	long double pow_d = 2.0, tmp;
	scanf("%d", &n);

	tmp = pow(pow_d, n);					//2의 n승한 값을 tmp변수에 저장

	sprintf(k_result, "%.0Lf", tmp);        //숫자나 문자 등을 문자열에 넣을 때 sprintf 사용
	int size = strlen(k_result);
	k_result[size - 1] = (char)(((int)(k_result[size - 1] - 48) - 1) + 48);
	printf("%s\n", k_result);

	if (n <= 20) {
		hanoi_tower(n, 1, 2, 3);
	}
	return 0;
}