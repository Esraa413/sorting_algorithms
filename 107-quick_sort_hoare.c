#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

int partition(int *array, int low, int high);
void quick_sort_recursive(int *array, int low, int high);

/**
* quick_sort_hoare - sort array using the Quick sort algorithm
* @array: array of ints to sorted
* @size: size of array
*/

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1);
}

/**
* partition - Hoare partition
* @array: array to  the partition
* @low: str index of partition
* @high: ending index of partition
* Return: Return: Always 0
*/

int partition(int *array, int low, int high)
{
	int piv = array[high];
	int x = low - 1, k = high + 1;
	int tmp = array[x];

	while (1)
	{
		do {
			x++;
		} while (array[x] < piv);

		do {
			k--;
		} while (array[k] > piv);

		if (x >= k)
		{
			return (k);
		}
		array[x] = array[k];
		array[k] = tmp;
		print_array(array, (size_t)k + 1);
	}
}

/**
* quick_sort_recursive -  function to recursive perform Quick
* @array: sort array
* @low: str index of subarray
* @high: ending index subarray
*/

void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high);
		quick_sort_recursive(array, low, pivot_index);
		quick_sort_recursive(array, pivot_index + 1, high);
	}
}
