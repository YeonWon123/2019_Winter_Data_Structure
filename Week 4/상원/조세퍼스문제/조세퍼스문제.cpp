#include<iostream>
#include<vector>
using namespace std;


vector <int> v;

// erase - �ش��ϴ� ��ġ ���� �����.
// v.erase(v.begin()+4) = vector �� �ټ���° ���� �����. 
int main(void)
{
	/*
	int N, K;
	cin.sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		v.push_back(i); // ���Ϳ� i �ִ´� 
	}
	
	// index 3��° ��ġ
	int idx = K - 1;
	
	// ó���� ���Ϳ� 7�� �����Ƿ� ������ 7
	cout << "<";
	while (v.size() > 1)
	{
		cout << v[idx] << ", ";
		v.erase(v.begin() + idx);
		// 3��� �� ���� v�� idx ���� ���� 
		// 6��� �� ���� v�� 4��° ���� �����.
		// 2��� �� ���� v�� �ι�° ��������
		// 3��° �迭�� ����ϰ� ����
		
		// ó�� �迭  1 2 3 4 5 6 7
		// �ϳ� �����ǰ� ���� �迭 1 2 4 5 6 7 
		idx += K - 1;  // 6�� ����� ���� idx�� 4�� �ǰ���.
		// idx �� 6�̵�
		idx = idx % v.size(); // v.size()�� 7 idx�� 4 idx ��  = 4
		// 6�� 5�� ������ 1 
		// 1 2 4 5 7 
		// ���⼭ 2�� ��������
	}
	// while�� �������� ũ�Ⱑ 1���� ũ�� �ʴ�.
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