
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::sort;

int binarySearch(int arr[], int left, int right, int target)
{
	if (right >= left) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == target)
			return mid;

		if (arr[mid] > target)
			return binarySearch(arr, left, mid - 1, target);

		return binarySearch(arr, mid + 1, right, target);
	}

	return -1;
}

int main(void)
{
	
    int arr[100];
    int size;

    cout << "Enter the number of elements in the array: ";
    cin >> size;


    if (size <= 0 || size > 100) {
        cout << "Invalid size! Must be less than 100. ";
        return 1;
    }

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    sort(arr, arr + size); 

    int target;
    cout << "Enter the element to search: ";
    cin >> target;
	
	int result = binarySearch(arr, 0, size - 1, target);
	(result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
	return 0;
}

