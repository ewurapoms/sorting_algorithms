#include "sort.h"

size_t splitter(int *array, ssize_t drop, ssize_t stack, size_t size);
void quicksort(int *array, ssize_t drop, ssize_t stack, size_t size);

/**
 * quick_sort_hoare - uses the Quick sort algo to sort an array of integers
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}

/**
 * splitter - implements the Hoare scheme
 * @array: ...
 * @drop: minimum index
 * @stack: maximum index
 * @size: ...
 * Return: sorted index
 */
size_t splitter(int *array, ssize_t drop, ssize_t stack, size_t size)
{
	int swap, pivot;

	pivot = array[stack];
	while (drop <= stack)
	{
		while (array[drop] < pivot)
			drop++;
		while (array[stack] > pivot)
			stack--;
		if (drop <= stack)
		{
			if (drop != stack)
			{
				swap = array[drop];
				array[drop] = array[stack];
				array[stack] = swap;
				print_array(array, size);
			}
			drop++;
			stack--;
		}
	}
	return (stack);
}

/**
 * quicksort - sorts an array of integers that has been splitted
 * @array: ...
 * @drop: ...
 * @stack: ...
 * @size: ...
 */
void quicksort(int *array, ssize_t drop, ssize_t stack, size_t size)
{
	ssize_t pivot;

	if (drop < stack)
	{
		pivot = splitter(array, drop, stack, size);
		quicksort(array, drop, pivot, size);
		quicksort(array, pivot + 1, stack, size);

	}
}
