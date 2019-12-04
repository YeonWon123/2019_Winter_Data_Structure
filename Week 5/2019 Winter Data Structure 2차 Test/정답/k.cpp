// 키로거
// 백준 5397
// 리스트를 사용하여 해결하는 문제
// ACM-ICPC : BAPC 2010 I번

#include <cstdio>
#include <cstdlib>
#include <string>
#include <list>

using namespace std;

#define MAX_NUM 1000010
char line[MAX_NUM];

int main() {
	int t;
	scanf("%d\n", &t);
	while (t--) {
		scanf("%s\n", line);
		list<char> ret;
		list<char>::iterator position = ret.begin();
		for (int i = 0; line[i]; i++) {
			if (line[i] == '-') {
				if (position != ret.begin()) {
					position = ret.erase(--position);
				}
			}
			else if (line[i] == '<') {
				if (position != ret.begin()) {
					position--;
				}
			}
			else if (line[i] == '>') {
				if (position != ret.end()) {
					position++;
				}
			}
			else {
				position = ret.insert(position, line[i]);
				position++;
			}
		}
		for (position = ret.begin(); position != ret.end(); position++) {
			putchar(*position);
		}
		putchar('\n');
	}
}
