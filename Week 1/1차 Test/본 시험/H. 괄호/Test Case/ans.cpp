#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
	string str1;
	string str2;

	int aaaa;
	cin >> aaaa;

	str1 = to_string(aaaa) + ".in";
	str2 = to_string(aaaa) + ".out";

	ofstream ins(str1);
	ofstream outs(str2);	

	int N;
	scanf("%d\n", &N);

	ins << N << "\n";
	
	for (int i = 0; i < N; i++) {
		int sum = 0;
		int sw = 0;
		char a[51];

		scanf("%s", a);
		ins << a << "\n";

		int j = 0;
		while(1) {
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

		if (sw == 0 && sum == 0) {
			outs << "YES\n";
			printf("YES\n");
		}
		else {
			outs << "NO\n";
			printf("NO\n");
		}
	}

	ins.close();
	outs.close();
	return 0;
}