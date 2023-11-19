#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void bitonic_recursion(int *array, int l, int r, int direction, size_t size);
void bitonic_merge(int *array, int l, int r, int direction);

/**
 * bitonic_sort - sorts an array following the Bitonic sort algorithm
 * @array: sort array of ints
 * @size: size of array
 *
 */

void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	bitonic_recursion(array, 0, size - 1, 1, size);
}

/**
 * bitonic_recursion - function for bitonic in sort recursive
 * @array: sort array
 * @l: left-most element
 * @r: right-most element
 * @direction: the ascending or the descending
 * @size: size of array
 */

void bitonic_recursion(int *array, int l, int r, int direction, size_t size)
{
	int st;

	if (r - l >= 1)
	{
		st = (r + l) / 2;
		printf("Merging [%d/%lu] ", r - l + 1, size);
		if (direction)
		{
			printf("(UP):\n");
		}
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
		bitonic_recursion(array, l, st, 1, size);
		bitonic_recursion(array, st + 1, r, 0, size);
		bitonic_merge(array, l, r, direction);
		printf("Result [%d/%lu] ", r - l + 1, size);
		if (direction)
		{
			printf("(UP):\n");
		}
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
	}
}

/**
 * bitonic_merge - sorts and merges the sequence,
 * in ascending or the descending order
 * @array: sort array
 * @l: left-most element
 * @r: right-most element
 * @direction: the ascending or the descending
 */

void bitonic_merge(int *array, int l, int r, int direction)
{
	int tmp, x, st = (l + r) / 2, md = (r - l + 1) / 2;

	if (r - l >= 1)
	{
		x = l;
		while (x < l + md)
		{
			if (direction == (array[x] > array[x + md]))
			{
				tmp = array[x + md];
				array[x + md] = array[x];
				array[x] = tmp;
			}
			x++;
		}
		bitonic_merge(array, l, st, direction);
		bitonic_merge(array, st + 1, r, direction);
	}
}
