#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<char> l;
	char c[100000];
	int n;
	cin >> c >> n;

	for (int i = 0; c[i] != '\0'; i++)
	{
		l.push_back(c[i]);
	}


	list<char>::iterator iter = l.end();
	char c1;
	char p;

	for (int i = 0; i < n; i++)
	{
		cin >> c1;
		switch (c1)
		{
		case 'L':
			if (iter != l.begin()) {
				iter--;
			}
			break;
		case 'D':
			if (iter != l.end()) {
				iter++;
			}
			break;
		case 'B':
			if (iter != l.begin())	//커서의 위치를 유지하기 위해 iter-- 를 해준다.
			{
				iter--;
				iter = l.erase(iter);	//erase 반환값 : 삭제된 데이터의 다음 데이터
			}
			break;
		case 'P':
			cin >> p;
			l.insert(iter, p);
			break;
		default:
			break;
		}
	}

	list<char>::iterator i;
	for (i = l.begin(); i != l.end(); i++) {
		cout << *i;
	}

}