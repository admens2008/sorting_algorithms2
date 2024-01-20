#include "sort.h"
/**
 * swap_quick - swap
 * @a: first data
 * @b: second ...
 * Return: null
 */
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * partition - Function to partition the array
 * and return the index of the pivot
 * @arr: array
 * @low: left partition index
 * @high: right sub array/ pertition index
 * @size: array size
 * Return: NULL
 */
int partition(int arr[], int low, int high, int size) {
    /* Choose the pivot */
    int pivot = arr[high];
    int j;
    
    /* Index of smaller element and indicate*/
    /* the right position of pivot found so far*/
    int i = (low - 1);

    for (j = low; j <= high; j++) {
        /* If current element is smaller than the pivot*/
        if (arr[j] < pivot) {
            /* Increment index of smaller element*/
            i++;
            swap(&arr[i], &arr[j]);
            print_array(arr, size);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    print_array(arr, size);
    return (i + 1);
}

/**
 * quickSort_helper - Function to perform Quick Sort
 * @arr: ==
 * @low: ==
 * @high: ==
 * @size: ==
 * Return: NULL
 */
void quickSort_helper(int arr[], int low, int high, int size) {
    /* When low is less than high*/
    if (low < high) {
        /* pi is the partition return index of pivot*/
        int pi = partition(arr, low, high, size);
        
        /* Recursion call*/
        /* Smaller element than pivot goes left and*/
        /* higher element goes right*/
        quickSort_helper(arr, low, pi - 1, size);
        quickSort_helper(arr, pi + 1, high, size);
    }
}

/**
 * quick_sort - ====
 * @array: array
 * @size: size of array
 * Return: ===
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort_helper(array, 0, size - 1, size);

}
