//�迭 �̿� Ʈ������
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
	//1. ù°,��°���� �̿��� Ʈ���� �����.
	makeTree(size);
	cin >> Dtarget;

	//2. �־��� ��ȣ�� node�� �����.
	deleteNode(Dtarget, size);

	//3. Ʈ���� Ž���� lead node�� ������ ã�´�.
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