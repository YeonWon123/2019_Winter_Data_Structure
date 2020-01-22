#include <iostream>

using namespace std;

int vertex[100000];

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int u, v;
	int e = 0;
	int T = 0;
	int ver_size = 0;

	for (T = 0; true; T++) {

		for (e = 0; true; e++) {
			int find_u = 0;
			int find_v = 0;

			cin >> u >> v;

			if (u < 0 && v < 0)
				return 0;

			if (u == 0 && v == 0) {
				break;
			}

			for (int i = 0; i < ver_size ; i++) {
				if (vertex[i] == u) {
					find_u = 1;
					break;
				}
			}

			if (find_u == 0 || ver_size == 0)
				vertex[ver_size++] = u;

			for (int i = 0; i < ver_size; i++) {
				if (vertex[i] == v) {
					find_v = 1;
					break;
				}
			}

			if (find_v == 0 && u != v)
				vertex[ver_size++] = v;
		}
		if (ver_size - e == 1 || ver_size == 0) {
			cout << "Case " << T + 1 << " is a tree." << '\n';
		}
		else {
			cout << "Case " << T + 1 << " is not a tree." << '\n';
		}

		ver_size = 0;
	}

	return 0;
}