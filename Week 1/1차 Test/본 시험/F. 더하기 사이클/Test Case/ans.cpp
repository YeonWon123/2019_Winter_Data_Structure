#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(void)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i <= 99; i++) {

	string str1;
	string str2;

	str1 = to_string(i+1) + ".in";
	str2 = to_string(i+1) + ".out";

	ofstream in(str1);
	ofstream out(str2);	

	in << i;

	int input = i;
	int answer = 0;
	int original = i;

	while (!(original == input && answer != 0)) {
		int temp = input % 10 * 10;
		input = input / 10 + input % 10;
		input = temp + input % 10;
		answer++;
	}
	out << answer;

	in.close();
	out.close();
	}
	return 0;
}