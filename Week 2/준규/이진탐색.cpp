#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <typeinfo>

using namespace std;

#define IN_STREAM cin
#define OUT_STREAM cout // in, out_stream 쓸때 본문에서 주석 제거

ifstream in_stream;
ofstream out_stream;
string N_str, M_str;
int T; // Test case num, N: source, M: target
int N, M;
int N_arr[1000000];
int M_arr[1000000];

void get_case()
{
	IN_STREAM >> N;
	for (int i = 0; i < N; i++)
		IN_STREAM >> N_arr[i];

	IN_STREAM >> M;
	for (int i = 0; i < M; i++)
		IN_STREAM >> M_arr[i];
}

int recur_bin_search(int* arr, int target, int start, int end)
{
	int mid = (start + end) / 2;
	if (start > end)
		return 0;
	if (target == arr[mid])
		return 1;
	else if (target < arr[mid])
		return recur_bin_search(arr, target, start, mid - 1);
	else
		return recur_bin_search(arr, target, mid + 1, end);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	open_file();

	IN_STREAM >> T;

	for (int i = 0; i < T; i++)
	{
		get_case();
		sort(N_arr, N_arr + N);
		for (int j = 0; j < M; j++)
			OUT_STREAM << recur_bin_search(N_arr, M_arr[j], 0, N - 1) << "\n";
	}
	return 0;
}