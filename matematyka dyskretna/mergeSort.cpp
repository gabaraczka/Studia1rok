#include <iostream>

using std::cin;
using std::cout;


void Merge(int* array, int low, int high, int mid)
{

	int i = low;
	int j = mid + 1;
	int k = 0;
	int* temp = new int[high - low + 1];


	while (i <= mid && j <= high)
	{
		if (array[i] < array[j])
		{
			temp[k] = array[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = array[j];
			k++;
			j++;
		}
	}


	while (i <= mid)
	{
		temp[k] = array[i];
		k++;
		i++;
	}


	while (j <= high)
	{
		temp[k] = array[j];
		k++;
		j++;
	}

	for (i = low; i <= high; i++)
	{
		array[i] = temp[i - low];
	}

	delete[] temp;
}


void MergeSort(int* array, int low, int high) 
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;

		MergeSort(array, low, mid);
		MergeSort(array, mid + 1, high);


		Merge(array, low, high, mid);
	}
}

int main()
{
	int n, i;
	cout << "\nEnter the number of elements to be sorted: ";
	cin >> n;

	int* array = new int[n];
	for (i = 0; i < n; i++)
	{
		cout << "Enter element " << i + 1 << ": ";
		cin >> array[i];
	}

	MergeSort(array, 0, n - 1);


	cout << "\nSorted Data: ";
	for (i = 0; i < n; i++)
		cout << array[i] << " ";

	delete[] array;


	return 0;
}
