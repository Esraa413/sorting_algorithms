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
* Return: Always 0
*/

int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;
	int tmp = array[i];

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, (size_t)j + 1);
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
