#include "sort.h"

int peak_value(int *array, int size);

/**
 * counting_sort - sorts an int[] by the counting sort algorithm
 * @array: pointer to int
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *counter, *sorter, maxi, i;

	if (array == NULL || size < 2)
		return;

	sorter = malloc(sizeof(int) * size);
	if (sorter == NULL)
		return;
	maxi = peak_value(array, size);
	counter = malloc(sizeof(int) * (maxi + 1));
	if (counter == NULL)
	{
		free(sorter);
		return;
	}

	for (i = 0; i < (maxi + 1); i++)
		counter[i] = 0;
	for (i = 0; i < (int)size; i++)
		counter[array[i]] += 1;
	for (i = 0; i < (maxi + 1); i++)
		counter[i] += counter[i - 1];
	print_array(counter, maxi + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorter[counter[array[i]] - 1] = array[i];
		counter[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorter[i];

	free(sorter);
	free(counter);
}

/**
 * peak_value - checks the maximum value in an int[]
 * @array: ptr
 * @size: ...
 * Return: the array's maximum int value
 */
int peak_value(int *array, int size)
{
	int highest, num;

	for (highest = array[0], num = 1; num < size; num++)
	{
		if (array[num] > highest)
			highest = array[num];
	}

	return (highest);
}
