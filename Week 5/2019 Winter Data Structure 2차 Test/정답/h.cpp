// h. 조세퍼스 문제
// 리스트 사용 - 배열로 구현함
// 백준 1158

#include <iostream>
using namespace std;
int N, K;
int arr[5001] = { 0 };
int index = 0;
void index_up();
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	cout << "<";
	for (int i = 0; i < N; i++) {
		index_up();
		if (i != N - 1) {
			cout << ", ";
		}
	}
	cout << ">";

}

void index_up() {
	for (int i = 0; i < K; i++) {

		index++;
		while (arr[index] == 1) {
			index++;
			if (index > N) {
				index = 1;
				while (arr[index] == 1) {
					index++;
				}
			}
		}

		if (index > N) {
			index = 1;
			while (arr[index] == 1) {
				index++;
			}
		}
	}
	cout << index;
	arr[index] = 1;
}