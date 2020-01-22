//유기체
#include <iostream>
#include <set>
#include <vector>
#include <iterator>
using namespace std;

vector<pair<int, int>>v;	//v.first에는 node 번호, v.second에는 부모 node 번호 저장
set<int>s;					//부모 노드의 번호를 중복 없이 저장

//n번 node 삭제
void func(int n)	//n은 삭제할 node 번호
{
	vector<pair<int, int>>::iterator iter;
	int arr[2] = { -1,-1 };	//node n을 부모로 가지는 node 번호 저장
	int i = 0;
	
	//n번 node 삭제
	for (iter = v.begin(); iter != v.end(); iter++) {
		if (iter->first == n) {
			v.erase(iter);
			break;
		}
	}

	//n번 node를 부모로 갖는 node 번호 저장
	for (iter = v.begin(); iter != v.end(); iter++) {
		if (iter->second == n) {
			arr[i++] = iter->first;
		}
	}

	//n번 node를 부모로 갖는 node 삭제
	for (int j = 0; j < 2; j++) {
		if (arr[j] == -1) {
			break;
		}
		else {
			func(arr[j]);
		}
	}
}

int main() {
	int n, r;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		v.push_back({ i,input });
	}

	cin >> r;	//삭제할 node 번호 입력

	func(r);

	for (int i = 0; i < v.size(); i++) {
		s.insert(v[i].second);
	}

	if (v.size() == 0) {
		cout << 0;
	}
	else {
		//leaf node의 개수 = 전체 node의 개수 - 부모 node의 개수
		cout << v.size() - s.size() + 1;

	}
}