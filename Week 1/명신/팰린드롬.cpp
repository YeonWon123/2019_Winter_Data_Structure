#include<iostream>
#include<string>
using namespace std;

int Array_size(string arr);

int main()
{
	//�ʿ��� ������ ���� �� �ʱ�ȭ
	int arrSize;
	bool flag;

	//��ü �ݺ���
	while (1)
	{
		string arr;
		getline(cin, arr);	//������� �޾ƿ��� �Լ�
		arrSize = Array_size(arr);
		flag = true;
		for (int i = 0; i < arrSize / 2; i++)
		{
			if (arr[i] != arr[arrSize - 1 - i])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}

	int Array_size(string arr)
	{
	
		int arrSize = 0;

		for (int i = 0;; i++)
		{
			if (arr[i] == '\0') break;
			arrSize++;
		}

		return arrSize;
	}
