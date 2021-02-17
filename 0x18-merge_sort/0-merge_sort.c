#include "sort.h"

/**
 * print_ - print
 * @left: the array to size
 * @lsize: size of the array
 */
void print_(int left, size_t lsize)
{
	printf("Merging...\n[left]: ");
	print_array(left, lsize);
	printf("[right]: ");
}

/**
 * merge_sort - merge sort in place on an array of integers
 * @array: the array to size
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right, *beg = array, top;
	size_t lsize = size / 2, re_size = size / 2 + size % 2;
	static int *buff, *alloc, idx, i;

	if (array == NULL || size <= 1)
		return;
	top = 0;
	if (buff == NULL)
	{
		top = 1;
		buff = malloc(sizeof(int) * size);
	}
	alloc = buff;
	merge_sort(array, lsize);
	merge_sort(array + lsize, re_size);
	left = array;
	right = array + lsize;
	print_(left, lsize);
	print_array(right, re_size);
	for (idx = 0; lsize > 0 && re_size > 0; idx++)
	{
		if (*left < *right)
		{
			buff[idx] = *left;
			left++;
			lsize--;
		}
		else
		{
			buff[idx] = *right;
			right++;
			re_size--;
		}
	}
	idx--;
	for (i = idx + 1; lsize; lsize--, left++, i++)
		array[i] = *left;
	for (i = idx + 1; re_size; re_size--, right++, i++)
		array[i] = *right;
	for (; idx >= 0; idx--)
		array[idx] = buff[idx];
	printf("[Done]: ");
	print_array(beg, size);
	if (top)
		free(alloc);
}
