#include "sort.h"

/**
 * selection_sort - sorts an array of int in ascending order
 * @array: ...to sort
 * @size: array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, mini;
	size_t arr = 0;
	int show;

	for (; arr < size - 1; arr++)
	{
		mini = arr;
		for (i = arr + 1; i < size; i++)
		{
			if (array[i] < array[mini])
				mini = i;
		}

		if (mini != arr)
		{
			show = array[arr];
			array[arr] = array[mini];
			array[mini] = show;
			print_array(array, size);
		}
	}
}
