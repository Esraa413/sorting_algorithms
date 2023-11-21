#include "sort.h"

/**
* swap - function to Swaps two integers in an array
* @a: First integer
* @b: Second integer
*/

void swap(int *a, int *b)
	{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
* sift_down - function to Performs sift-down operation on a heap node
* @array: array of the heap
* @size: Size heap
* @index: Index of the node
* @heap_size: Size of the current
*/

void sift_down(int *array, size_t size, size_t index, size_t heap_size)
	{
	size_t largest = index;
	size_t left = 2 * index + 1;
	size_t right = 2 * index + 2;

	if (left < heap_size && array[left] > array[largest])
	largest = left;

	if (right < heap_size && array[right] > array[largest])
	largest = right;

	if (largest != index)
	{
	swap(&array[index], &array[largest]);
	print_array(array, size);
	sift_down(array, size, largest, heap_size);
	}
	}

/**
* heap_sort - function yo  Sorts an array of integers
* @array: Array to be sorted
* @size: Size of the array
*/

void heap_sort(int *array, size_t size)
	{
	size_t x;

	if (!array || size < 2)
	return;

	for (x = size / 2; x != 0; x--)
	{
	sift_down(array, size, x - 1, size);
	}

	for (x = size; x > 1; x--)
	{
	swap(&array[0], &array[x - 1]);
	print_array(array, size);
	sift_down(array, size, 0, x - 1);
	}
	}
