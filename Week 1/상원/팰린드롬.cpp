#include<iostream>
#include<string>
using namespace std;


int main(void)
{
	int N;
	cin >> N;

	string Buffer;
	getline(cin, Buffer);
	// ������ �����ؼ� �Է¹��� 
	for (int i = 0; i < N; i++)
	{
		string Word;
		getline(cin, Word);
		bool result = true;
		// 
		for (int i = 0; i < Word.length() / 2; i++)
		{
			// ��ҹ��� ���о��ֱ� ���� �빮�ڷ� ���� 
			int A = toupper(Word[i]);
			int B = toupper(Word[Word.length() - i - 1]);
			if (A != B)
			{
				result = false;
				break;
			}
			else
			{
				result = true;
			}
		}
		if (result)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}

}