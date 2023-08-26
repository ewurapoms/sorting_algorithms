#include "sort.h"

void swap_paws(int *array, size_t item1, size_t item2);
void lomuto_quicksort(int *array, size_t top, size_t bottom, size_t size);

/**
 * quick_sort - Sorts an int[] using the quick sort algo & Lomuto
 * @array: array to sort.
 * @size: array length/size
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		lomuto_quicksort(array, 0, size - 1, size);
	}
}

/**
 * swap_paws - function that swaps two array items
 * @item1: array element
 * @item2: array element
 * @array: ptr value
 */
void swap_paws(int *array, size_t item1, size_t item2)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[item1];
		array[item1] = array[item2];
		array[item2] = tmp;
	}
}

/**
 * lomuto_quicksort - uses quicksort algo to get int[]
 * @array: is ptr
 * @top: peak array to sort
 * @bottom: lowest array to sort
 * @size: array size/length
 */
void lomuto_quicksort(int *array, size_t bottom, size_t top, size_t size)
{
	size_t key, element;
	int pivot;

	if ((bottom >= top) || (array == NULL))
		return;
	pivot = array[top];
	key = bottom;
	for (element = bottom; element < top; element++)
	{
		if (array[element] <= pivot)
		{
			if (key != element)
			{
				swap_paws(array, element, key);
				print_array(array, size);
			}
			key++;
		}
	}
	if (key != top)
	{
		swap_paws(array, key, top);
		print_array(array, size);
	}
	if (key - bottom > 1)
		lomuto_quicksort(array, bottom, key - 1, size);
	if (top - key > 1)
		lomuto_quicksort(array, key + 1, top, size);
}
