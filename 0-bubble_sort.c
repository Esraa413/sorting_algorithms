#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: array of integers
 * @size: amount of elemnts
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int temp;

	if (!array || !size)
		return;

	x = 0;
	while (x < size)
	{
		for (y = 0; y < size - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
				print_array(array, size);
			}
		}
		x++;
	}
}

