#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - 2 intgar values
 * @array: integer array to be sorted
 * @size: size of the array
 * @a: address of first value
 * @j: address of second value
 *
 * Return: Always 0.
 */

void swap(int *array, size_t size, int *a, int *j)
{
	if (*a != *j)
	{
		*a = *a + *j;
		*j = *a - *j;
		*a = *a - *j;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - the partitions of the array
 * @array: int array to sort
 * @size: the size of the array
 * @lw: low index of range in sort
 * @hi: high index of range in sort
 *
 * Return: Always 0.
 */
size_t lomuto_partition(int *array, size_t size, ssize_t lw, ssize_t hi)
{
	int x, k, piv = array[hi];
	
	x = k = lw;
	while (k < hi)
	{
		if (array[k] < piv)
		{
			swap(array, size, &array[k], &array[x++]);
		}
		k++;
	}
	swap(array, size, &array[x], &array[hi]);

	return (x);
}

/**
 * quicksort - quicksorts via Lomuto partition.
 * @array: integer array to sort
 * @size: size of the array
 * @lw: low index of the sort range
 * @hi: high index of the sort range
 *
 * Return: Always 0
 */

void quicksort(int *array, size_t size, ssize_t lw, ssize_t hi)
{
	if (lw < hi)
	{
		size_t p = lomuto_partition(array, size, lw, hi);

		quicksort(array, size, lw, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - function that sorts an array of integers,
 * in ascending order using the Quick sort algorithm
 * @array: integer array to sort
 * @size: size of the array
 *
 * Return: Always 0
 */

void quick_sort(int *array, size_t size)
{
	if (!array || !size)
	{
		return;
	}
	quicksort(array, size, 0, size - 1);
}
