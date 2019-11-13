#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> v;
void HanoiMove(int num, int from, int by, int to)
{
	if (num == 1)
		v.push_back({ from,to });

	else
	{
		HanoiMove(num - 1, from, to, by);
		v.push_back({ from,to });
		HanoiMove(num - 1, by, from, to);
	}

}

int main(void)
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	HanoiMove(N, 1, 2, 3);
	
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}