#include <iostream>
#include <chrono>
using namespace std;

int rank_arr[100], sorted_temp[100], Count = 0;

void ranksort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		rank_arr[i] = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			Count++;
			if (arr[j] <= arr[i])
				rank_arr[i]++;
			else
				rank_arr[j]++;
		}
	}
	for (i = 0; i < n; i++)
		sorted_temp[rank_arr[i]] = arr[i];
	for (i = 0; i < n; i++)
		arr[i] = sorted_temp[i];
}

int main()
{
	int n, arr[100];
	cout << "Enter the number of elements : ";
	cin >> n;
	cout << "Enter the elements" << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	auto start = std::chrono::high_resolution_clock::now();
	ranksort(arr, n);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

	cout << "array after sorting is:"<<endl;
	for (int j = 0; j < n; j++)
		cout << arr[j] << " ";
	cout << endl;
	cout << "Time complexity T(" << Count << ")" << endl;
	cout << "Time taken = " << elapsed.count() << " ns" << endl;
	return 0;
}