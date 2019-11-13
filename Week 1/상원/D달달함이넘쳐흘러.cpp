#include<iostream>
using namespace std;
int main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int A_X, A_Y, A_Z;
	int C_X, C_Y, C_Z;
	int B_X, B_Y, B_Z;
	cin >> A_X >> A_Y >> A_Z;
	cin >> C_X >> C_Y >> C_Z;
	B_X = C_X - A_Z;
	B_Y = C_Y / A_Y;
	B_Z = C_Z - A_X;
	cout << B_X <<" "<< B_Y <<" "<< B_Z;


	return 0;
}