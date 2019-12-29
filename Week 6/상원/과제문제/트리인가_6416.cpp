#include<iostream>
#include<set>
#include<vector>
#include<map>

using namespace std;
/*
STL : set - �ߺ��Ǵ� ���� ���� set�� ���� ���� �����ϴ�.
set func : insert() ���һ��� (�ڵ�����)
		 : clear() ��� ���� ���� 

������ ���� + 1 = ����� ���� 

*/
int main()
{
	set<int> s;
	int num = 1;
	while (1)
	{
		bool exit = false;
		int count = 0;
		while (1)
		{
			int u, v;
			cin >> u >> v;

			if (u == 0 && v == 0)
				break;
			if (u == -1 && v == -1)
			{
				exit = true;
				break;
			}
			++count;
			s.insert(u);
			s.insert(v);
		}
		if (exit)
			break;
		/*
		set<int>::iterator iter;
		for (iter = s.begin(); iter != s.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout << "\n";
		cout << "count :" << count << "\n";
		cout << "s.size() :" << s.size() << "\n";
		*/
		if (count == 0 || count + 1 == s.size())
		{
			cout << "Case " << num << " is a tree.\n";
		}
		else
		{
			cout << "Case " << num << " is not a tree.\n";
		}
		++num;
		s.clear();
	}


	return 0;
}
