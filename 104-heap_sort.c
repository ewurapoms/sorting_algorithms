#include "sort.h"

void binary_tree(int *array, size_t length, size_t size, size_t i);
/**
 * heap_sort - sorts int[] by heap sort algo
 * @array: pointer
 * @size: is the size
 *
**/
void heap_sort(int *array, size_t size)
{
	int num;
	size_t i = 0;
	size_t len = size;

	if (!array)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		binary_tree(array, len, size, size / 2 - 1 - i);
	}
	for (i = 0; i < len - 1; i++)
	{
		num = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = num;
		print_array(array, len);
		binary_tree(array, len, size - i - 1, 0);
	}

}


/**
 * binary_tree - function implements the sift-down heap sort algo
 * @array: ...
 * @size: ...
 * @length: is the initial array size
 * @i: tree index
 *
**/
void binary_tree(int *array, size_t length, size_t size, size_t i)
{

	int root, branch, anther;
	size_t stem, leaf;

	stem = i * 2 + 1;
	leaf = stem + 1;
	branch = array[stem];
	anther = array[leaf];
	if (((stem < size) && (leaf < size) &&
		(branch >= anther && branch > array[i]))
		|| ((stem == size - 1) && branch > array[i]))
	{
		root = array[i];
		array[i] = branch;
		array[stem] = root;
		print_array(array, length);
	}
	else if ((stem < size) && (leaf < size) &&
		(anther > branch && anther > array[i]))
	{
		root = array[i];
		array[i] = anther;
		array[leaf] = root;
		print_array(array, length);
	}
	if (stem < size - 1)
		binary_tree(array, length, size, stem);
	if (leaf < size - 1)
		binary_tree(array, length, size, leaf);
}
