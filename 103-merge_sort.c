#include "sort.h"

/**
 * merger - Merge and sorts an array of integers
 * @arr: A sub array of integers to be merged and sorted.
 * @buff: holds the merged and sorted int[]
 * @start: is the start point
 * @mid: rep the center point
 * @end: array's end
 */
void merger(int *arr, int *buff, size_t start, size_t mid, size_t end)
{
	size_t a, b, c = 0;

	printf("Merging...\n[left]: ");
	print_array(arr + start, mid - start);

	printf("[right]: ");
	print_array(arr + mid, end - mid);

	for (a = start, b = mid; a < mid && b < end; c++)
		buff[c] = (arr[a] < arr[b]) ? arr[a++] : arr[b++];
	for (; a < mid; a++)
		buff[c++] = arr[a];
	for (; b < end; b++)
		buff[c++] = arr[b];
	for (a = start, c = 0; a < end; a++)
		arr[a] = buff[c++];

	printf("[Done]: ");
	print_array(arr + start, end - start);
}

/**
 * loop_mergeSort - performs a recursive implementation of merge sort
 * @arr: ...
 * @buffer: ...
 * @start: ...
 * @end: ...
 */
void loop_mergeSort(int *arr, int *buffer, size_t start, size_t end)
{
	size_t center;

	if (end - start > 1)
	{
		center = start + (end - start) / 2;
		loop_mergeSort(arr, buffer, start, center);
		loop_mergeSort(arr, buffer, center, end);
		merger(arr, buffer, start, center, end);
	}
}

/**
 * merge_sort - implements the merge sort algo
 * @array: ...
 * @size: ...
 */
void merge_sort(int *array, size_t size)
{
	int *result;

	if (array == NULL || size < 2)
		return;

	result = malloc(sizeof(int) * size);
	if (result == NULL)
		return;

	loop_mergeSort(array, result, 0, size);

	free(result);
}
