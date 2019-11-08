#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream in_stream;
	in_stream.open("input.txt"); // �׽�Ʈ ���̽� �Է¹ޱ�

	if (in_stream.fail())
	{
		cout << "file open failure";
		return 0;
	}
	int test_case_n;

	bool* result;
	string in_str;

	char stack[50];
	int stack_size;

	in_stream >> test_case_n;
	in_stream.ignore(1, '\n');

	result = new bool[test_case_n] {false};

	for (int i = 0; i < test_case_n; i++)
	{
		getline(in_stream, in_str);
		if (in_str.length() == 0)
			return 0;

		stack[0] = in_str[0];
		stack_size = 1; // ������ �� �� ���� ����.
		for (int j = 1; j < (int)in_str.length(); j++)
		{
			if (stack[0] == ')')
				result[i] = false;

			else if (stack_size == 0)
			{
				stack[stack_size] = in_str[j];
				stack_size++;
			}

			else if (stack[stack_size - 1] == in_str[j])
			{
				stack[stack_size] = in_str[j];
				stack_size++;
			}

			else
			{
				stack[stack_size - 1] = 0;
				stack_size--;
			}
		}
		if (stack_size == 0)
			result[i] = true;
	}
	for (int i = 0; i < test_case_n; i++)
	{
		if (result[i] == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	delete[] result;
	return 0;
}