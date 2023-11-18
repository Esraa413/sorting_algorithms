#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* radix_sort - function that sorts an array of integers,
* in ascending order using the Radix sort algorithm
* @array: int array to sort
* @size: size of array
*/

void radix_sort(int *array, size_t size)
{
	int max_num = 0;
	size_t x, lsd;

	if (!array || size < 2)
		return;
	x = 0;
	while (x < size)
	{
		if (array[x] > max_num)
		{
			max_num = array[x];
		}
		x++;
	}

	for (lsd = 1; max_num / lsd > 0; lsd *= 10)
	{
		counting_sort(array, size, lsd);
		print_array(array, size);
	}
}

/**
* counting_sort - the count of sort with LSD
* @array: sort array
* @size: size of array
* @exp: significant digit (exponent of 10)
*/

void counting_sort(int *array, size_t size, int exp)
{
	int count_arr[10] = {0}, *out_arr;
	int x, y;
	size_t j, k;

	out_arr = malloc(sizeof(int) * size);
	j = 0;
	while (j < size)
	{
		count_arr[(array[j] / exp) % 10]++;
		j++;
	}
	x = 1;
	while (x < 10)
	{
		count_arr[x] += count_arr[x - 1];
		x++;
	}
	for (y = size - 1; y >= 0; y--)
	{
		out_arr[count_arr[(array[y] / exp) % 10] - 1] = array[y];
		count_arr[(array[y] / exp) % 10]--;
	}
	k = 0;
	while (k < size)
	{
		array[k] = out_arr[k];
		k++;
	}
	free(out_arr);
}
