//�迭 �̿� Ʈ������
#include<iostream>
using namespace std;

int arr[50];
int ForCheck[50];
int numofdelete=0;

void makeTree(int size);
void deleteNode(int target,int size);
void search(int size);

int main()
{
	int size,input,Dtarget,numofdelete;
	cin >> size;
	//1. ù°,��°���� �̿��� Ʈ���� �����.
	makeTree(size);
	cin >> Dtarget;
	if (Dtarget == 0)
	{
		cout << "0" << endl;
	}
	else
	{
		//2. �־��� ��ȣ�� node�� �����.
		deleteNode(Dtarget, size);

		//for (int i = 0; i < size; i++)
		//{
		//	cout << arr[i];
		//}
		//cout << endl;

		//3. Ʈ���� Ž���� lead node�� ������ ã�´�.

		search(size);
	}
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
	if (size < 2) cout << 0;
	else 
	{
		int sum = 0;
		int temp=333;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] != -1 &&arr[i]!=temp)
			{
				sum++;
				temp = arr[i];
			}
		}
		cout << size - sum - numofdelete << endl;

		//for (int i = 0; i < size; i++)
		//{
		//	ForCheck[arr[i]+1] = 1;
		//}
		//int sum = 0;

		//for (int i = 0; i < size; i++)
		//{
		//	cout << ForCheck[i]; 
		//}
		//cout << endl;

		//for (int i = 0; i < size-numofdelete; i++)
		//{
		//	if (ForCheck[i] != 1) sum++;
		//}
		//cout << sum+1 << endl;
	}
}