#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using a shell
 * sort algorithm, with gap sizes determined by a decreasing Knuth seqeuence
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */

void shell_sort(int *array, size_t size)
{
	int x, y, gap, z, Knuth_max, temp;

	if (!array || size < 2)
		return;

	z = (int)size;

	for (gap = 1; gap < z; gap = (gap * 3) + 1)
	{
		Knuth_max = gap;
	}

	for (gap = Knuth_max; gap > 0; gap = (gap - 1) / 3)
	{
		for (x = gap; x < z; x++)
		{
			temp = array[x];
			for (y = x; y >= gap && array[y - gap] > temp; y -= gap)
			{
				array[y] = array[y - gap];
			}
			array[y] = temp;
		}
		print_array(array, size);
	}
}
