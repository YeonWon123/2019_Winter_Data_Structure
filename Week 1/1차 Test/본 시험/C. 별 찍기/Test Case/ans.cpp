#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	string str;
	for (int j = 1; j <= 100; j++) {
	str = to_string(j) + ".in";
	ofstream outfile(str);
	outfile << j;

	str = to_string(j) + ".out";
	ofstream outfiles(str);

	int N = j;
	int last = 2 * N - 1;
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= ((last - (2 * i - 1)) / 2); k++)
			outfiles << " ";
			
		for (int k = 1; k <= 2*i-1; k++)
			outfiles << "*";

		if (i != N)
			outfiles << "\n";
	}
	outfile.close();
	outfiles.close();
	}
	return 0;

}