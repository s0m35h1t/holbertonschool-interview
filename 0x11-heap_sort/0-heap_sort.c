#include "sort.h"

/**
 *	sift_ - sift positions in the heap
 *	@array: Array to use for the sift
 *	@size: Array size
 *	@start: Shift start position
 *	@end: Shift End position
 */
void sift_(int *arr, size_t size, size_t beg, size_t end)
{
	size_t parent, child, swp;
	int tmp;

	parent = beg;
	while (parent * 2 + 1 <= end)
	{
		child = 2 * parent + 1;
		swp = parent;
		if (arr[swp] < arr[child])
			swp = child;

		if (child + 1 <= end && arr[swp] < arr[child + 1])
			swp = child + 1;

		if (swp != parent)
		{
			tmp = arr[parent];
			arr[parent] = arr[swp];
			arr[swp] = tmp;
			print_array(arr, size);
			parent = swp;
		}
		else
			break;
	}
}

/**
*	heap_sort - heap sort in ascending order
 *
 *	@array: Array to be sorted
 *	@size: Array size
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int tmp;
	long beg = (size - 2) / 2;

	if (size < 2)
		return;

	while (beg >= 0)
		sift_(array, size, beg--, size - 1);

	end = size - 1;
	while (end > 0)
	{
		tmp = array[end];
		array[end] = array[0];
		array[0] = tmp;
		print_array(array, size);
		sift_(array, size, 0, --end);
	}
}
