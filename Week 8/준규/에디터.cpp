#include <iostream>
#include <string>
#include <list>

using namespace std;

list<char> inStr;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	getline(cin, str); // 문자열 받아오고
	int str_size = str.size();
	for (int i = 0; i < str_size; i++) // 리스트로 만들고
	{
		inStr.push_back(str[i]);
	}
	int M; // 명령어 
	cin >> M;

	list<char>::iterator cur, q;
	cur = inStr.end(); // 커서 시작지점

	for (int i = 0; i < M; i++)
	{
		char a1, a2;

		cin >> a1;
		switch (a1)
		{
		case 'L':
			if (cur != inStr.begin())
				--cur;
			break;
		case 'D':
			if (cur != inStr.end())
				++cur;
			break;
		case 'B':
			if (cur != inStr.begin())
			{
				cur = inStr.erase(--cur);
				str_size--;
			}
			break;
		case 'P':
			cin >> a2;
			inStr.insert(cur, a2);
			str_size++;
			break;
		default:
			break;
		}
		int j = 0;
	}
	int j = 0;
	for (q = inStr.begin(); j < str_size; j++, q++)
		cout << *q;

	return 0;
}