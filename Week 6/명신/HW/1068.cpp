//배열 이용 트리구현
#include<iostream>
#include<set>
using namespace std;

int arr[50];
int numofdelete=0;

void makeTree(int size);
void deleteNode(int target,int size);
void search(int size);

int main()
{
	int size,input,Dtarget;
	cin >> size;
	//1. 첫째,둘째줄을 이용해 트리를 만든다.
	makeTree(size);
	cin >> Dtarget;

	//2. 주어진 번호의 node를 지운다.
	deleteNode(Dtarget, size);

	//3. 트리를 탐색해 lead node의 개수를 찾는다.
	search(size);
}

void makeTree(int size)
{
	int input;
	for (int i = 0; i < size; i++)
	{
		cin >> input;
		arr[i] = input;
	}
}

void deleteNode(int target,int size)
{
	numofdelete++;
	arr[target] = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			arr[i] = -1;
			deleteNode(i,size);
		}
	}
}

void search(int size)
{
	set<int> s;
	if (size < 2) cout << 0;
	else
	{
		int Rootnode = 0;
		for (int i = 0; i < size; i++)
		{
			s.insert(arr[i]);
		}
		if (s.find(-1) != s.end()) Rootnode = s.size() - 1;
		else Rootnode = s.size();

		//cout << "size:" << size << endl;
		//cout << "Rootnode: " << Rootnode << endl;
		//cout << "numofdelete: " << numofdelete << endl;
		cout << size - Rootnode - numofdelete << endl;
	}
}