#include "sort.h"

int bucket_s(int *array, ssize_t size, int digit, int *updates);
int parse_num(long number, int digit);
/**
 * radix_sort - sorts int[] by LSD algo implementation
 * @size: size of the array
 * @array: ptr
 * Return: significant digit
 */
void radix_sort(int *array, size_t size)
{
	int *initial, *current;
	int *tmp, *ptr, range = 0;
	size_t i, sig_dig = 1;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > range)
			range = array[i];
	while (range /= 10)
		sig_dig++;
	initial = array;
	current = ptr = malloc(sizeof(int) * size);
	if (!current)
		return;
	for (i = 0; i < sig_dig; i++)
	{
		bucket_s(initial, (ssize_t)size, i, current);
		tmp = initial;
		initial = current;
		current = tmp;
		print_array(initial, size);
	}
	for (i = 0; i < size; i++)
		array[i] = initial[i];
	free(ptr);
}

/**
 * parse_num - retrieves int digit at specific position
 * @number: int value
 * @digit: to sort
 * Return: function value, else -1
**/
int parse_num(long number, int digit)
{
	long n = 0L, m = 1L, val;

	for (n = 0; n < digit; n++)
		m *= 10L;
	val = ((number / m) % 10);
	return (val);
}

/**
 * bucket_s - implements a radix sort pass for specific digits
 * @array: ptr
 * @size: ...
 * @digit: to sort
 * @updates: print new sorted array elements
 * Return: 1
 */
int bucket_s(int *array, ssize_t size, int digit, int *updates)
{
	ssize_t num;
	int radx[10] = {0};

	for (num = 0; num < size; num++)
		radx[parse_num(array[num], digit)]++;
	for (num = 1; num <= 9; num++)
		radx[num] += radx[num - 1];
	for (num = size - 1; num > -1; num--)
		updates[radx[parse_num(array[num], digit)]-- - 1] = array[num];
	return (1);
}
