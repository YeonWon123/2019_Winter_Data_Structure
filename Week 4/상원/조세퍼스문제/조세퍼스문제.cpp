#include<iostream>
#include<vector>
using namespace std;


vector <int> v;

// erase - 해당하는 위치 원소 지운다.
// v.erase(v.begin()+4) = vector 의 다섯번째 원소 지운다. 
int main(void)
{
	/*
	int N, K;
	cin.sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		v.push_back(i); // 벡터에 i 넣는다 
	}
	
	// index 3번째 위치
	int idx = K - 1;
	
	// 처음에 벡터에 7개 있으므로 사이즈 7
	cout << "<";
	while (v.size() > 1)
	{
		cout << v[idx] << ", ";
		v.erase(v.begin() + idx);
		// 3출력 후 벡터 v의 idx 원소 지움 
		// 6출력 후 벡터 v의 4번째 원소 지운다.
		// 2출력 후 벡터 v의 두번째 원소지움
		// 3번째 배열값 출력하고 지움
		
		// 처음 배열  1 2 3 4 5 6 7
		// 하나 삭제되고 남은 배열 1 2 4 5 6 7 
		idx += K - 1;  // 6을 지우기 위해 idx가 4가 되게함.
		// idx 가 6이됨
		idx = idx % v.size(); // v.size()는 7 idx는 4 idx 는  = 4
		// 6을 5로 나누면 1 
		// 1 2 4 5 7 
		// 여기서 2를 지워야함
	}
	// while문 빠져나옴 크기가 1보다 크지 않다.
	cout << v[0] << ">\n";6
	}
	*/

	cin.tie(NULL); cout.tie(NULL); cin.sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		v.push_back(i);
	}

	int position = K - 1;
	cout << "<";
	while (v.size() > 1)
	{
		cout << v[position] << ", ";
		v.erase(v.begin() + position);
		position += K - 1;
		position %= v.size();
	}
	cout << v[0] << ">\n";
	return 0;
}