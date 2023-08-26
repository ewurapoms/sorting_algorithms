#include "sort.h"

void swap(int arr[], int num1, int num2, int format);
void merger(int arr[], int down, int key, int order);
void _bitonic_sort(int arr[], int down, int key, int order, int size);

/**
 * bitonic_sort - function implements a bitonic sort algo.
 * @array: is the array.
 * @size: length of array.
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	_bitonic_sort(array, 0, size, order, size);
}

/**
 * swap - switches 2 ascending or descending values' order
 * @arr: ...
 * @num1: ...
 * @num2: ...
 * @format: checks 1 for ascending order, descending order 0
 */
void swap(int arr[], int num1, int num2, int format)
{
	int swp;

	if (format == (arr[num1] > arr[num2]))
	{
		swp = arr[num1];
		arr[num1] = arr[num2];
		arr[num2] = swp;
	}
}
/**
 * merger - performs recursive sorting
 * @arr: ...
 * @down: ...
 * @key: ...
 * @order: ...
 */
void merger(int arr[], int down, int key, int order)
{
	int m, center;

	if (key > 1)
	{
		center = key / 2;
		for (m = down; m < down + center; m++)
			swap(arr, m, m + center, order);
		merger(arr, down, center, order);
		merger(arr, down + center, center, order);
	}
}
/**
 * _bitonic_sort - function implements a bitonic sort algo(helper)
 * @arr: ...
 * @down: ...
 * @key: ...
 * @order: ...
 * @size: ...
 */
void _bitonic_sort(int arr[], int down, int key, int order, int size)
{
	int center;

	if (key > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", key, size);
			print_array(&arr[down], key);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", key, size);
			print_array(&arr[down], key);
		}
		center = key / 2;
		_bitonic_sort(arr, down, center, 1, size);
		_bitonic_sort(arr, down + center, center, 0, size);
		merger(arr, down, key, order);
		if (order < 1)
		{
			printf("Result [%i/%i] (DOWN):\n", key, size);
			print_array(&arr[down], key);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", key, size);
			print_array(&arr[down], key);
		}
	}
}
