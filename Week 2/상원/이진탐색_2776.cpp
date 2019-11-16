#include<iostream>
#include<algorithm>
using namespace std;
// ���� ���Ŀ� Binary search

/*
<STL sort>  -> #include<algorithm>

���� sort(arr, arr+n);
arr[i] ���� arr[n-1]���� �������� ��������.

sort(arr,arr+n,����); -> ���� �־ ���İ���.
*/
int Bsearch(int arr[], int target,int len)
{
	int mid;

	int start = 0;
	int last = len - 1;

	while (start <= last)
	{
		mid = (start + last) / 2;
		if (arr[mid] == target)
		{
			return mid;
		}
		else if (arr[mid] > target)
		{
			last = mid - 1;
		}
		else if (arr[mid] < target)
		{
			start = mid + 1;
		}
	}
	return -1;
}
/*
int Bsearch2(int arr[], int target, int start,int last)
{
	int mid = (start + last) / 2;

	if (start > last)
	{
		return -1;
	}
	else if (arr[mid] > target)
	{
		return Bsearch2(arr, target, start, mid - 1);
	}
	else if (arr[mid] < target)
	{
		return Bsearch2(arr, target, mid+1, last);
	}

}
*/

int main()
{
	int arr[10000];
	int T, N, M;
	cin >> T;
	cin >> N;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j];
		}
		sort(arr, arr + N);
		cin >> M;
		int val, check;
		for (int k = 0; k < M; k++)
		{
			cin >> val;
			check = Bsearch(arr, val, N);
			if (check == -1)
			{
				puts("0");
			}
			else
			{
				puts("1");
			}
		}

	}
	return 0;
}