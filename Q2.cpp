#include <iostream>
using namespace std;
int getMax(int arr[], int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}
void countSort(int arr[], int size, int mod)
{
	int count[10] = {0};
	int output[size];
	
	for (int i = 0; i < size; i++)
	{
		count[(arr[i] / mod) % 10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(arr[i] / mod) % 10] -1] = arr[i];
//		count[(arr[i] / mod) % 10]--;
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = output[i];
	}
}
void radixSort(int arr[], int size)
{
	int max = getMax(arr, size);

	for (int i = 1; max / i > 0; i *= 10)
	{
		countSort(arr, size, i);
	}
}
int main()
{
	int arr[] = {120, 300, 200, 150, 90, 600};
	//	int arr[]={1,5,7,9,3,2};
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Unsorted Array: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	radixSort(arr, size);
	cout << "Sorted Array: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}