#include<iostream>
using namespace std;

int sw = 0;
int var = 0;
void HanoiMove(int num, int from, int by, int to)
{

	if (num == 1)
	{
		if (sw == 1)
			cout << from << " " << to << "\n";
		var += 1;
	}

	else
	{
		HanoiMove(num - 1, from, to, by);
		if (sw == 1)
			cout << from << " " << to << "\n";
		HanoiMove(num - 1, by, from, to);
		var += 1;
	}
	
}

int main(void)
{
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	if (N <= 20)
	{
		HanoiMove(N, 1, 2, 3);
		cout << var << "\n";
		sw = 1;
		HanoiMove(N, 1, 2, 3);
	}
	else
	{
		HanoiMove(N, 1, 2, 3);
		cout << var << "\n";
		sw = 1;
		HanoiMove(N, 1, 2, 3);

	}
	return 0;
}