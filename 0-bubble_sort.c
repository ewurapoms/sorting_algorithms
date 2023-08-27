#include "sort.h"

/**
 *bubble_sort - sorts an array of int using the bubble sort algorithm
 *@array: the array to be sorted
 *@size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t bub = 0;
	size_t sort = 0;
	int n;

	if (size < 2)
		return;
	for (sort = 0; sort < size - 1; sort++)
	{
		for (bub = 0; bub < size - sort - 1; bub++)
		{
			if (array[bub] > array[bub + 1])
			{
				n = array[bub];
				array[bub] = array[bub + 1];
				array[bub + 1] = n;
				print_array(array, size);
			}
		}
	}
}
