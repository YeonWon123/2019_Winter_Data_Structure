#include<iostream>
#include<string>
#include<stack>
using namespace std;

int Array_size(char*arr);

int main()
{

	int size;
	int arrSize;
	bool flag;
	cin >> size;

	//arr[0]���� arrSize ���� Ȯ��
	for (int i = 0; i < size; i++)
	{
		//����� ���� �ʱ�ȭ
		stack<char> st;
		char arr[100];
		cin >> arr;		//space,enter �� ���ö����� �Է¹���
		arrSize = Array_size(arr);
		flag = true;

		//VPS ����
		for (int j = 0; j < arrSize; j++)
		{
			// '('�̸� push ')'�̸�pop  �� stack�� empty�� ���¿��� pop�̸� false
			if (arr[j] == '(')
			{
				st.push('(');
			}
			else if (arr[j] == ')')
			{
				if (st.empty())
				{
					flag = false;
					break;
				}
				else
				{
					st.pop();
				}
			}
		}

		//for�� ������ st.empty != true �̸� false
		if (!st.empty())
		{
			flag = false;
		}


		//flag true�� YES, �ƴϸ� NO ���
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

//�������� ���� ����ϴ� �Լ� ��� ���� �����س�����

int Array_size(char *arr)
{
	int arrSize = 0;

	for (int i = 0;; i++)
	{
		if (arr[i] == '\0') break;
		arrSize++;
	}

	return arrSize;
}

/*
stack ����
1.#include<stack>	//stack class �޾ƿ���
2.stack<datatype> st(object��)  // datatype�� stack ����
3. st.push('char')	//stack�� 'char'data ����ֱ�
	st.pop()	//stack ������ data ������
	st.empty() //stack ����ִ��� Ȯ�� ������ true
*/
