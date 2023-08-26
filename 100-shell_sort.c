#include "sort.h"

/**
 * shell_sort - combines the shell sort algo $ Knuth seq to sort an array
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	int n = 1;
	int sh, i, temp;

	if (!array || !size || size < 2)
		return;
	while (n < (int)size / 3)
		n = n * 5 - 1;
	while (n > 0)
	{
		for (sh = n; sh < (int)size; sh++)
		{
			temp = array[sh];
			i = sh;
			while (i > (n - 1) && array[i - n] >= temp)
			{
				array[i] = array[i - n];
				i = i - n;
			}
			array[i] = temp;
		}
		n = n / 3;
		print_array(array, size);
	}
}
