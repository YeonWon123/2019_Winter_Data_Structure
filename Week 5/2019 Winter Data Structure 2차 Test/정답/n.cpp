// Passport Control
// ���� 16288
// ���� �Ǵ� ť�� ����Ͽ� Ǯ �� �ִ� ����
// ACM-ICPC : Seoul Nationalwide Internet Competition 2018 G��

#include <iostream>
#include <stack>
using namespace std;
stack<int> s[101];
int a[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= k; i++)
	{
		s[i].push(0);
	}
	for (int i = 1; i <= n; i++)
	{
		bool b = false;
		for (int j = 1; j <= k; j++)
		{
			if (a[i] > s[j].top())
			{
				s[j].push(a[i]);
				b = false;
				break;
			}
			else
			{
				b = true;
			}
		}
		if (b)
		{
			cout << "NO" << "\n";
			return 0;
		}
	}
	cout << "YES" << "\n";

	return 0;
}