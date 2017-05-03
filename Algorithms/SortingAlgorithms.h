#pragma once
#include <string>
#include <iostream>

using namespace std;

/*Bubble Sorting O(n^2)*/
void bubbleSort(int arr[], int size) 
{
	for (int i = 0; i < size; i++) //repeatedly swap adjacent elements if they are in the wrong order
		for (int j = 0; j < size - i - 1; j++) //***note*** j < size - i - 1
			if (arr[j] > arr[j + 1]) //if element in index j > j+1 switch
			{
				int temp = arr[j]; //put element of j in temp
				arr[j] = arr[j + 1]; // put element of j+1 into j
				arr[j + 1] = temp; // put temp into element of j+1
			}
}
/*Selection Sorting O(n^2)*/
void selectionSort(int arr[], int size)
{
	int min; //minimum index
	for (int i = 0; i < size - 1; i++) //moves boundary of sorted array and unsorted array ***note*** i < size - 1
	{
		/*find the minimimum element in the array*/
		min = i;
		for (int j = i + 1; j < size; j++) //***not**** j = i + 1
			if (arr[j] < arr[min])
				min = j;
		/*swap the found minimum with the first element*/
		if (min != i)
			swap(arr[min], arr[i]);
	}
}
/*Insertion Sorting O(n^2)*/
void insertionSort(int arr[], int size)
{
	int j, temp;
	for (int i = 1; i < size; i++) //i = 1
	{
		j = i;
		while (j > 0 && arr[j] < arr[j - 1]) //if element in j is less than the element before it in the array then switch
		{
			/*Swap array integers if condition until condition is met*/
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--; //decrement j until it is in it's proper spot in the sorted array
		}
	}
}
/*Quick Sorting O(nlogn)*/
void quickSort(int arr[], int low, int high)
{
	int pivot, i, j, temp;
	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j) //partition
		{
			while (arr[i] <= arr[pivot] && i <= high)
				i++;
			while (arr[j] > arr[pivot] && j >= low)
				j--;
			if (i < j) // if i is less than j then switch j and i
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		temp = arr[j];
		arr[j] = arr[pivot];
		arr[pivot] = temp;
		quickSort(arr, low, j - 1);
		quickSort(arr, j + 1, high);
	}
}
/*Merge Sorting O(nlogn)*/
void merge(int arr[], int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	/*Temp Arrays*/
	int* L = new int[n1];
	int* R = new int[n2];

	/*Copy data to temp arrays L[] and R[]*/
	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[middle + 1 + j];

	/*Merge the temp arrays back into arr[l..r] */
	i = 0, j = 0;
	k = left; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/*Copy the remaining elements of L[], if there are any*/
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	/*Copy the remaining elements of R[], if there are any*/
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[]L;
	delete[]R;

}
void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		// Sort first and second halves
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}
/*Heap Sorting O(nlogn)*/
void heapify(int arr[], int size, int index)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && arr[left] > arr[largest])
		largest = left;
	if (right < size && arr[right] > arr[largest])
		largest = right;
	if (largest != index)
	{
		swap(arr[index], arr[largest]);
		heapify(arr, size, largest);
	}
}
void heapSort(int arr[], int size)
{
	for (int i = (size / 2 - 1); i >= 0; i--)
		heapify(arr, size, i);
	for (int j = size - 1; j >= 0; j--)
	{
		swap(arr[0], arr[j]);
		heapify(arr, j, 0);
	}
}
/*Shell Sorting O(n)*/
void shellSort(int arr[], int size)
{
	int j;
	//Narrow the array by 2 everytime
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; ++i)
		{
			int temp = arr[i];
			for (j = i; j >= gap && temp < arr[j - gap]; j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}
/*Print Array*/
void print(int arr[], int size)
{
	cout << "Array: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}