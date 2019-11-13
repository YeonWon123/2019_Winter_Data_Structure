#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int N;
	cin >> N;

	string flushBuffer;
	getline(cin, flushBuffer);
	for (int n = 0; n < N; n++)
	{
		string s;
		getline(cin, s);

		bool flag = true;
		for(int i=0; i<s.length() / 2; i++)
			if (toupper(s[i]) != toupper(s[s.length() - i - 1]))
			{
				flag = false;
				break;
			}

		if (flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}