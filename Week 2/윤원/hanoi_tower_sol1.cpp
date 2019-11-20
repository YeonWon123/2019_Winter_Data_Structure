#include <stdio.h>
#include <math.h>
#include <string.h>
#pragma warning(disable: 4996)
#define MAX 1000000

//���� from�� �׿��ִ� ������ tmp�� �̿��� to�� �Űܺ���
//from: ������, tmp: �߰�����, to: ��������
void hanoi_tower(int N, int from, int tmp, int to) {            
	if (N <= 20) {
		if (N == 1) {
			printf("%d %d\n", from, to);
		}
		else {
			//1. 1��(���� ��)�� ������ ��� ������ to�� �̿��� tmp�� �ű��.
			hanoi_tower(N - 1, from, to, tmp); 
			//2. from���뿡 �ִ� 1��(���� �ٴڿ� �ִ� ����)�� to�� �ű��.
			printf("%d %d\n", from, to);
			//3. tmp�� �ִ� ���� �� ������ ������ ��� ������ from�� �̿��� to�� �ű��.
			hanoi_tower(N - 1, tmp, from, to);
		}
	}
}

int main() {
	int n = 0;
	char k_result[MAX];
	long double pow_d = 2.0, tmp;
	scanf("%d", &n);

	tmp = pow(pow_d, n);					//2�� n���� ���� tmp������ ����

	sprintf(k_result, "%.0Lf", tmp);        //���ڳ� ���� ���� ���ڿ��� ���� �� sprintf ���
	int size = strlen(k_result);
	k_result[size - 1] = (char)(((int)(k_result[size - 1] - 48) - 1) + 48);
	printf("%s\n", k_result);

	if (n <= 20) {
		hanoi_tower(n, 1, 2, 3);
	}
	return 0;
}