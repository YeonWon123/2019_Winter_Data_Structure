#include<iostream>
#include<string>
using namespace std;

class stack_imake
{
public:
	stack_imake(); //���� �ʱ�ȭ ���� (���û����� �� ���� ȣ��Ǿ�� �ϴ� �Լ�)
	void push(char data); //���ÿ� ����������, �ŰԺ��� data�� ���޵� ���� ������
	void pop(); //�������� ����� ��Ҹ� ����, �����ϴ� �����ʹ� ��ȯ��, ���Լ��� ȣ���Ϸ��� �ϳ��̻��� ���� ���ÿ� �־����
	int top(); //�������� ����� ��Ҹ� ��ȯ�ϵ� ������������
	bool empty(); //stack�� ����ִ��� Ȯ��
	~stack_imake();
private:
	//char* cp = new char  //�迭�� �̷��� �����ϸ� runtime_error ��?
	char* cp = new char[1000];
	int topindex; //-1�� �ʱ�ȭ
};

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
		stack_imake st;
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


stack_imake::stack_imake()
{
	topindex = -1;
}
void stack_imake::push(char input)
{
	topindex++;
	cp[topindex] = input;

	return;
}
void stack_imake::pop()
{
	cp[topindex] = '\0';
	topindex--;

	return;
}
int stack_imake::top()
{
	return topindex;
}
bool stack_imake::empty()
{
	if (topindex >= 0) return false;
	else return true;
}
stack_imake::~stack_imake()
{
	delete[] cp;
}