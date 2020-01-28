#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - i) - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		
		}
	}

}

int main(void)
{
	int arr[4] = { 3,2,4,1 };
	BubbleSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}