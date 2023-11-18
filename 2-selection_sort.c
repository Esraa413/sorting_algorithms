#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort-function that sorts an array of integers in,
 * ascending order using the Selection sort algorithm 
 * @array: after each time you swap two elements 
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t x, k, y;
	int temp;

	if (!array || !size)
		return;
	
	x = 0;
	while (x < size - 1)
	{
		for (k = size - 1, y = x + 1; k > x; k--)
		{
			if (array[k] < array[y])
			{
				y = k;
			}
		}
		if (array[x] > array[y])
		{
			temp = array[x];
			array[x] = array[y];
			array[y] = temp;
			print_array(array, size);
		}
		x++;
	}
}
