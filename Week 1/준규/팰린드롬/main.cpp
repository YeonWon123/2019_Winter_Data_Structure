#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream in_stream;
	in_stream.open("input.txt"); // 테스트 케이스 입력받기

	if (in_stream.fail())
	{
		cout << "file open failure";
		return 0;
	}
	int test_case_n;

	bool* result;
	string in_str;

	char stack[1000];
	int stack_size;

	in_stream >> test_case_n;
	in_stream.ignore(1, '\n');

	result = new bool[test_case_n] {false};

	for (int i = 0; i < test_case_n; i++)
	{
		int isOdd;
		int str_length;

		getline(in_stream, in_str);
		str_length = (int)in_str.length();
		if (str_length == 1)
		{
			result[i] = true;
			continue;
		}
		isOdd = str_length % 2 == 1 ? true : false;
		stack[0] = in_str[0];
		stack_size = 1; // 위에서 한 개 먼저 넣음.
		for (int j = 1; j < str_length; j++)
		{

			if (isOdd && j == str_length / 2)
				continue;

			else if (stack_size == 0)
			{
				stack[stack_size] = in_str[j];
				stack_size++;
			}

			else if (tolower(stack[stack_size - 1]) == tolower(in_str[j]))
			{
				stack[stack_size - 1] = 0;
				stack_size--;
			}

			else
			{
				stack[stack_size] = in_str[j];
				stack_size++;
			}
		}
		if (stack_size == 0)
			result[i] = true;
	}
	for (int i = 0; i < test_case_n; i++)
	{
		if (result[i] == true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	delete[] result;
	return 0;
}