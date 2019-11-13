#include<iostream>
using namespace std;
int main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cout << fixed;
	cout.precision(3);
	int C;
	cin >> C;
	int Student_Num;
	int count = 1;
	int sum = 0;
	int StudentArr[1000] = { 0 };
	double avg = 0.0;
	double avg_over = 0.0;
	int avg_greator_count = 0;
	while (count <= C)
	{
		sum = 0;
		avg = 0;
		avg_greator_count = 0;
		cin >> Student_Num;
		for (int i = 0; i < Student_Num; i++)
		{
			cin >> StudentArr[i];
			sum += StudentArr[i];
		}
		avg = (double)sum / Student_Num;
		for (int i = 0; i < Student_Num; i++)
		{
			if (StudentArr[i] > avg)
			{
				avg_greator_count += 1;
			}
		
		}
		avg_over = (double)avg_greator_count / Student_Num;
		cout << avg_over*100 << "%\n";
		count += 1;

	}
	return 0;
}