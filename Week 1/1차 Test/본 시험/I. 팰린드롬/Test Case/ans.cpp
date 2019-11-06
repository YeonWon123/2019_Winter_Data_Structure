#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{

	string str1;
	string str2;
	int a;
	cin >> a;
	str1 = to_string(a) + ".in";
	str2 = to_string(a) + ".out";

	ofstream in(str1);
	ofstream out(str2);

	int N;
	cin >> N;
	in << N << endl;

	string flushBuffer;
	getline(cin, flushBuffer);
	in << flushBuffer;
	for (int n = 0; n < N; n++)
	{
		string s;
		getline(cin, s);
		in << s << endl;

		bool flag = true;
		for(int i=0; i<s.length() / 2; i++)
			if (toupper(s[i]) != toupper(s[s.length() - i - 1]))
			{
				flag = false;
				break;
			}

		if (flag) {
			out << "Yes\n";
			cout << "Yes\n";
		}
		else {
			out << "No\n";
			cout << "No\n";
		}
	}
	return 0;
}
