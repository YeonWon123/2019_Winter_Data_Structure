#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

struct info {
	int x, y, z;
};

int main(void) {
	info a, c;

	string str;
	string str2;
	int b; cin>> b;
	str = to_string(b) + ".in";
	str2 = to_string(b) + ".out";
	ofstream outfile(str);
	ofstream outfile2(str2);

	scanf("%d %d %d", &a.x, &a.y, &a.z);
	scanf("%d %d %d", &c.x, &c.y, &c.z);

	outfile << a.x << " " << a.y << " " << a.z << "\n";
	outfile << c.x << " " << c.y << " " << c.z << "\n";

	printf("%d %d %d\n", c.x - a.z, c.y / a.y, c.z - a.x);
	outfile2 << c.x - a.z << " " << c.y / a.y << " " << c.z - a.x << "\n";
}