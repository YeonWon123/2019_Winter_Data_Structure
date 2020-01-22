//����ü
#include <iostream>
#include <set>
#include <vector>
#include <iterator>
using namespace std;

vector<pair<int, int>>v;	//v.first���� node ��ȣ, v.second���� �θ� node ��ȣ ����
set<int>s;					//�θ� ����� ��ȣ�� �ߺ� ���� ����

//n�� node ����
void func(int n)	//n�� ������ node ��ȣ
{
	vector<pair<int, int>>::iterator iter;
	int arr[2] = { -1,-1 };	//node n�� �θ�� ������ node ��ȣ ����
	int i = 0;
	
	//n�� node ����
	for (iter = v.begin(); iter != v.end(); iter++) {
		if (iter->first == n) {
			v.erase(iter);
			break;
		}
	}

	//n�� node�� �θ�� ���� node ��ȣ ����
	for (iter = v.begin(); iter != v.end(); iter++) {
		if (iter->second == n) {
			arr[i++] = iter->first;
		}
	}

	//n�� node�� �θ�� ���� node ����
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

	cin >> r;	//������ node ��ȣ �Է�

	func(r);

	for (int i = 0; i < v.size(); i++) {
		s.insert(v[i].second);
	}

	if (v.size() == 0) {
		cout << 0;
	}
	else {
		//leaf node�� ���� = ��ü node�� ���� - �θ� node�� ����
		cout << v.size() - s.size() + 1;

	}
}