#include<iostream>
#include<string>
using namespace std;


int main(void)
{
	string word;
	cin >> word;
	int sum = 0;
	for (int i = word.length() -1; i>=0; i--)
	{
		if (word[i] == 'A')
		{
			sum += 10;
		}
		else if (word[i] == 'B')
		{
			sum += 11;
		}
		else if (word[i] == 'C')
		{
			sum += 12;
		}
		else if (word[i] == 'D')
		{
			sum += 13;
		}
		else if (word[i] == 'E')
		{
			sum += 14;
		}
		else if (word[i] == 'F')
		{
			sum += 15;
		}
		else if (word[i] == '0')
		{
			sum += 0;
		}
		else if (word[i] == '1')
		{
			sum += 1;
		}
		else if (word[i] == '2')
		{
			sum += 2;
		}
		else if (word[i] == '3')
		{
			sum += 3;
		}
		else if (word[i] == '4')
		{
			sum += 4;
		}
		else if (word[i] == '5')
		{
			sum += 5;
		}
		else if (word[i] == '6')
		{
			sum += 6;
		}
		else if (word[i] == '7')
		{
			sum += 7;
		}
		else if (word[i] == '8')
		{
			sum += 8;
		}
		else if (word[i] == '9')
		{
			sum += 9;
		}

	}
	cout << sum;

	return 0;
}