#include<iostream>
using namespace std;

void Swap(int arr[], int left, int right)
{
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;
	while (low <= high)
	{
		//피벗보다 큰 값을 찾는 과정
		while (pivot > arr[low])
			low++;
		//피벗보다 작은 값을 찾는 과정
		while (pivot < arr[high])
			high--;

		if (low <= high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high);
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int main()
{
	int arr[8] = { 3,2,4,1,7,6,5,8};

	int len = sizeof(arr) / sizeof(int);

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}