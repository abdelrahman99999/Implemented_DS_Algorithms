/* C++ implementation of QuickSort */
#include<iostream>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
/* The function that picks an element as pivot and partitions the given array around the pivot
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index 

return the positon after putting it in the right position
*/

int partition(int arr[], int low, int high)
{
	int pivot = arr[low]; // pivot
	int i =low;
	int j = high;
	while (i != j) {
		if (arr[j] > arr[i]) {
			/*move the index not positioned at pivot*/
			if (arr[j] == pivot)
			{
				i++;
			}
			else {
				j--;
			}
		}
		else {
			swap(&arr[i], &arr[j]);
			if (arr[j] == pivot)
			{
				i++;
			}
			else {
				j--;
			}
		}
	}
	return i; //or return j;
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Driver Code
int main()
{
	int arr[] = { 41,62,13,84,35,96,57,28,79};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

